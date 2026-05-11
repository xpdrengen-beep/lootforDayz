class ZombieSpawner
{
	static ref map<string, ref SpawnedZombieZone> ActiveZones = new map<string, ref SpawnedZombieZone>();
	static ref map<string, Resource> ResourceCache = new map<string, Resource>();
	static int ActiveZombieCount = 0;
	static bool DEBUG_LOGGING = false;
	static LFZ_ZombieZoneEntity ClearanceCheckZone;
	static LFZ_ZombieSpawnPointEntity ClearanceCheckSpawnPoint;
	static bool ClearanceCheckBlocked = false;

	static void DebugPrint(string message)
	{
		if (DEBUG_LOGGING)
			Print(message);
	}

	static void WarningPrint(string message)
	{
		Print(message);
	}

	static void TrySpawnZone(LFZ_ZombieZoneEntity zone)
	{
		if (!zone)
			return;

		string zoneKey = zone.GetZoneKey();
		SpawnedZombieZone data = ActiveZones.Get(zoneKey);

		if (!data)
		{
			data = new SpawnedZombieZone();
			ActiveZones.Insert(zoneKey, data);
		}

		data.ZonePosition = zone.GetOrigin();

		if (data.IsSpawned)
		{
			data.LastPlayerNearbyTime = System.GetTickCount();
			return;
		}

		if (ActiveZombieCount >= DynamicZombieManager.MAX_ACTIVE_ZOMBIES)
		{
			DebugPrint("[Zombies] Zombie cap reached, delaying zone spawn: " + zone.GetDisplayName());
			return;
		}

		int currentTime = System.GetTickCount();

		if (data.LastDespawnTime > 0 && currentTime - data.LastDespawnTime < zone.GetEffectiveRespawnCooldownMs())
		{
			DebugPrint("[Zombies] Zone on cooldown: " + zone.GetDisplayName());
			return;
		}

		data.IsSpawned = true;
		data.LastPlayerNearbyTime = currentTime;

		int zombieCount = GetSpawnCount(zone);
		DebugPrint("[Zombies] Spawning " + zombieCount + " zombies in zone: " + zone.GetDisplayName() + " (" + zone.ZoneType + ")");

		for (int i = 0; i < zombieCount; i++)
		{
			if (ActiveZombieCount >= DynamicZombieManager.MAX_ACTIVE_ZOMBIES)
				break;

			IEntity zombie = SpawnZombie(zone);

			if (!zombie)
				continue;

			data.Zombies.Insert(zombie);
			ActiveZombieCount++;
		}

		if (data.Zombies.Count() == 0)
		{
			data.IsSpawned = false;
			data.LastDespawnTime = currentTime;
		}
	}

	static int GetSpawnCount(LFZ_ZombieZoneEntity zone)
	{
		int minZombies = zone.GetEffectiveMinZombies();
		int maxZombies = zone.GetEffectiveMaxZombies();

		if (maxZombies < minZombies)
			maxZombies = minZombies;

		return Math.RandomInt(minZombies, maxZombies + 1);
	}

	static IEntity SpawnZombie(LFZ_ZombieZoneEntity zone)
	{
		if (!zone || zone.ZombiePrefab == "")
		{
			WarningPrint("[Zombies] Missing ZombiePrefab on zone. Set an unarmed standard character prefab in Workbench.");
			return null;
		}

		Resource res = GetCachedResource(zone.ZombiePrefab);

		if (!res)
		{
			WarningPrint("[Zombies] Could not load zombie prefab: " + zone.ZombiePrefab);
			return null;
		}

		EntitySpawnParams params = new EntitySpawnParams();
		params.TransformMode = ETransformMode.WORLD;

		vector spawnPosition;

		if (!TryGetSpawnPosition(zone, spawnPosition))
		{
			DebugPrint("[Zombies] Could not find clear spawn position in zone: " + zone.GetDisplayName());
			return null;
		}

		vector mat[4];
		Math3D.AnglesToMatrix("0 0 0", mat);
		mat[3] = spawnPosition;
		params.Transform = mat;

		IEntity zombie = GetGame().SpawnEntityPrefab(res, GetGame().GetWorld(), params);

		if (!zombie)
		{
			WarningPrint("[Zombies] FAILED spawn: " + zone.ZombiePrefab);
			return null;
		}

		DebugPrint("[Zombies] Spawned zombie: " + zone.ZombiePrefab);
		return zombie;
	}

	static bool TryGetSpawnPosition(LFZ_ZombieZoneEntity zone, out vector spawnPosition)
	{
		if (zone.ShouldUseSpawnPoints() && TryGetSpawnPointPosition(zone, spawnPosition))
			return true;

		return TryGetRandomSpawnPosition(zone, spawnPosition);
	}

	static bool TryGetSpawnPointPosition(LFZ_ZombieZoneEntity zone, out vector spawnPosition)
	{
		array<LFZ_ZombieSpawnPointEntity> spawnPoints = LFZ_ZombieZoneRegistry.GetSpawnPoints();
		int count = spawnPoints.Count();

		if (count == 0)
			return false;

		int startIndex = Math.RandomInt(0, count);

		for (int i = 0; i < count; i++)
		{
			int index = (startIndex + i) % count;
			LFZ_ZombieSpawnPointEntity spawnPoint = spawnPoints[index];

			if (!spawnPoint || !spawnPoint.CanBeUsedByZone(zone))
				continue;

			vector candidate = spawnPoint.GetOrigin();

			if (!IsSpawnPositionClearForSpawnPoint(candidate, zone, spawnPoint))
				continue;

			spawnPosition = candidate;
			return true;
		}

		return false;
	}

	static bool TryGetRandomSpawnPosition(LFZ_ZombieZoneEntity zone, out vector spawnPosition)
	{
		vector center = zone.GetOrigin();
		float radius = zone.GetEffectiveRadius();
		float minDistance = DynamicZombieManager.MIN_SPAWN_DISTANCE;

		if (radius < minDistance)
			minDistance = 0.0;

		int attempts = zone.GetEffectiveSpawnPositionAttempts();

		for (int i = 0; i < attempts; i++)
		{
			float angle = Math.RandomFloat(0.0, 6.283185);
			float distance = Math.RandomFloat(minDistance, radius);
			vector candidate = center + Vector(Math.Cos(angle) * distance, 0.0, Math.Sin(angle) * distance);

			if (!IsSpawnPositionClear(candidate, zone))
				continue;

			spawnPosition = candidate;
			return true;
		}

		return false;
	}

	static bool IsSpawnPositionClear(vector candidate, LFZ_ZombieZoneEntity zone)
	{
		return IsSpawnPositionClearForSpawnPoint(candidate, zone, null);
	}

	static bool IsSpawnPositionClearForSpawnPoint(vector candidate, LFZ_ZombieZoneEntity zone, LFZ_ZombieSpawnPointEntity spawnPoint)
	{
		if (DynamicZombieManager.IsAnyPlayerTooClose(candidate))
			return false;

		float clearanceRadius = zone.GetEffectiveObjectClearanceRadius();

		if (clearanceRadius <= 0)
			return true;

		ClearanceCheckZone = zone;
		ClearanceCheckSpawnPoint = spawnPoint;
		ClearanceCheckBlocked = false;

		GetGame().GetWorld().QueryEntitiesBySphere(
			candidate,
			clearanceRadius,
			ObjectClearanceCallback,
			null,
			EQueryEntitiesFlags.WITH_OBJECT
		);

		ClearanceCheckZone = null;
		ClearanceCheckSpawnPoint = null;
		return !ClearanceCheckBlocked;
	}

	static bool ObjectClearanceCallback(IEntity ent)
	{
		if (!ent)
			return true;

		if (ent == ClearanceCheckZone)
			return true;

		if (ent == ClearanceCheckSpawnPoint)
			return true;

		ClearanceCheckBlocked = true;
		return false;
	}

	static Resource GetCachedResource(string prefab)
	{
		if (prefab == "")
			return null;

		Resource cachedResource = ResourceCache.Get(prefab);

		if (cachedResource)
			return cachedResource;

		Resource loadedResource = Resource.Load(prefab);

		if (loadedResource)
			ResourceCache.Insert(prefab, loadedResource);

		return loadedResource;
	}

	static void DespawnZoneZombies(string key, SpawnedZombieZone data)
	{
		if (!data || !data.IsSpawned)
			return;

		DebugPrint("[Zombies] Despawning zone: " + key);

		int trackedZombies = 0;

		foreach (IEntity zombie : data.Zombies)
		{
			if (!zombie)
				continue;

			trackedZombies++;
			SCR_EntityHelper.DeleteEntityAndChildren(zombie);
		}

		ActiveZombieCount -= trackedZombies;

		if (ActiveZombieCount < 0)
			ActiveZombieCount = 0;

		data.Zombies.Clear();
		data.IsSpawned = false;
		data.LastDespawnTime = System.GetTickCount();
	}

	static int RecountActiveZombieCount()
	{
		ActiveZombieCount = 0;

		foreach (string key, SpawnedZombieZone data : ActiveZones)
		{
			if (!data || !data.IsSpawned)
				continue;

			foreach (IEntity zombie : data.Zombies)
			{
				if (zombie)
					ActiveZombieCount++;
			}
		}

		return ActiveZombieCount;
	}
}
