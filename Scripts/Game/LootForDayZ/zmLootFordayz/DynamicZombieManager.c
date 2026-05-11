class DynamicZombieManager
{
	static bool Started = false;

	static int CHECK_INTERVAL_MS = 5000;
	static float MIN_SPAWN_DISTANCE = 45.0;
	static float DESPAWN_DISTANCE = 350.0;
	static int EMPTY_AREA_DESPAWN_MS = 900000;
	static int RECOUNT_INTERVAL_MS = 60000;
	static int MAX_ACTIVE_ZOMBIES = 120;

	static ref array<vector> CurrentPlayerPositions = new array<vector>();
	static int LastRecountTime = 0;

	static void Start()
	{
		GetGame().GetCallqueue().Remove(CheckZones);

		if (!Started)
		{
			Started = true;
			Print("[Zombies] Dynamic zombie manager started.");
		}
		else
		{
			Print("[Zombies] Dynamic zombie manager scheduler refreshed.");
		}

		GetGame().GetCallqueue().CallLater(CheckZones, CHECK_INTERVAL_MS, true);
		GetGame().GetCallqueue().CallLater(CheckZones, 1000, false);
	}

	static void CheckZones()
	{
		array<vector> playerPositions = {};
		array<int> players = {};
		GetGame().GetPlayerManager().GetPlayers(players);

		foreach (int playerId : players)
		{
			IEntity player = GetGame().GetPlayerManager().GetPlayerControlledEntity(playerId);

			if (!player)
				continue;

			playerPositions.Insert(player.GetOrigin());
		}

		CurrentPlayerPositions.Clear();

		foreach (vector playerPos : playerPositions)
			CurrentPlayerPositions.Insert(playerPos);

		MaybeRecountActiveZombieCount();
		CheckWorkbenchZones(playerPositions);
		CheckDespawn(playerPositions);
	}

	static void CheckWorkbenchZones(array<vector> playerPositions)
	{
		array<LFZ_ZombieZoneEntity> zones = LFZ_ZombieZoneRegistry.GetZones();

		foreach (LFZ_ZombieZoneEntity zone : zones)
		{
			if (!zone)
				continue;

			if (!IsAnyPlayerNearPosition(zone.GetOrigin(), playerPositions, zone.GetActivationDistance()))
				continue;

			ZombieSpawner.TrySpawnZone(zone);
		}
	}

	static void MaybeRecountActiveZombieCount()
	{
		int currentTime = System.GetTickCount();

		if (LastRecountTime > 0 && currentTime - LastRecountTime < RECOUNT_INTERVAL_MS)
			return;

		LastRecountTime = currentTime;
		ZombieSpawner.RecountActiveZombieCount();
	}

	static bool IsAnyPlayerTooClose(vector position)
	{
		array<int> players = {};
		GetGame().GetPlayerManager().GetPlayers(players);

		foreach (int playerId : players)
		{
			IEntity player = GetGame().GetPlayerManager().GetPlayerControlledEntity(playerId);

			if (!player)
				continue;

			if (vector.Distance(player.GetOrigin(), position) < MIN_SPAWN_DISTANCE)
				return true;
		}

		return false;
	}

	static void CheckDespawn(array<vector> playerPositions)
	{
		int currentTime = System.GetTickCount();

		foreach (string key, SpawnedZombieZone data : ZombieSpawner.ActiveZones)
		{
			if (!data || !data.IsSpawned)
				continue;

			if (IsAnyPlayerNearPosition(data.ZonePosition, playerPositions, DESPAWN_DISTANCE))
			{
				data.LastPlayerNearbyTime = currentTime;
				continue;
			}

			if (data.LastPlayerNearbyTime <= 0)
				data.LastPlayerNearbyTime = currentTime;

			if (currentTime - data.LastPlayerNearbyTime < EMPTY_AREA_DESPAWN_MS)
				continue;

			ZombieSpawner.DespawnZoneZombies(key, data);
		}
	}

	static bool IsAnyPlayerNearPosition(vector position, array<vector> playerPositions, float distance)
	{
		foreach (vector playerPos : playerPositions)
		{
			if (vector.Distance(playerPos, position) <= distance)
				return true;
		}

		return false;
	}
}
