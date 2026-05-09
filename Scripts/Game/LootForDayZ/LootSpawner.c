class LootSpawner
{
	static ref map<string, ref SpawnedHouseLoot> ActiveHouses = new map<string, ref SpawnedHouseLoot>();
	static ref array<IEntity> QueuedHouseEntities = new array<IEntity>();
	static ref array<string> QueuedHouseTypes = new array<string>();
	static ref array<string> QueuedHouseKeys = new array<string>();
	static ref map<string, bool> QueuedHouseKeySet = new map<string, bool>();
	static ref map<string, string> HouseTypeCache = new map<string, string>();
	static ref map<string, Resource> ResourceCache = new map<string, Resource>();
	static int ActiveLootItemCount = 0;
	static string CurrentHouseType = "";
	static bool DEBUG_LOGGING = false;
	static int MAX_HOUSES_TO_SPAWN_PER_FLUSH = 0;

	static void DebugPrint(string message)
	{
		if (DEBUG_LOGGING)
			Print(message);
	}

	static void WarningPrint(string message)
	{
		Print(message);
	}

	static void CacheHouseType(string key, string houseType)
	{
		if (key == "" || houseType == "")
			return;

		if (HouseTypeCache.Contains(key))
			HouseTypeCache.Remove(key);

		HouseTypeCache.Insert(key, houseType);
	}

	static bool HouseCallback(IEntity ent)
	{
		if (!ent)
			return true;

		string entityKey = ent.ToString();
		string cachedHouseType = HouseTypeCache.Get(entityKey);

		if (cachedHouseType != "")
		{
			QueueHouse(ent, cachedHouseType);
			return true;
		}

		string info = GetEntityPrefabName(ent);

		if (IsHousePrefab(info, LootHouse_FarmHouseE1L01.PREFAB))
		{
			QueueHouse(ent, "FARMHOUSEE1L01");
			return true;
		}

		if (IsHousePrefab(info, LootHouse_FarmHouseE1L01.PREFAB_GREEN))
		{
			QueueHouse(ent, "FARMHOUSEE1L01_GREEN");
			return true;
		}

		if (IsHousePrefab(info, LootHouse_FarmHouseE1L01.PREFAB_WOOD))
		{
			QueueHouse(ent, "FARMHOUSEE1L01_WOOD");
			return true;
		}

		if (IsHousePrefab(info, LootHouse_Brickbuilding01.PREFAB))
		{
			QueueHouse(ent, "BRICKBUILDING01");
			return true;
		}

		if (IsHousePrefab(info, LootHouse_House2Floors01.PREFAB))
		{
			QueueHouse(ent, "HOUSE2FLOORS01");
			return true;
		}

		if (IsHousePrefab(info, LootHouse_VillageE1I04s.PREFAB))
		{
			QueueHouse(ent, "HOUSEVILLAGEE1I04S");
			return true;
		}

		if (IsHousePrefab(info, LootHouse_VillageE1I05.PREFAB_S))
		{
			QueueHouse(ent, "HOUSEVILLAGEE1I05S");
			return true;
		}

		if (IsHousePrefab(info, LootHouse_VillageE1I05.PREFAB_T))
		{
			QueueHouse(ent, "HOUSEVILLAGEE1I05T");
			return true;
		}

		if (IsHousePrefab(info, LootHouse_WoodenE1I01_P.PREFAB))
		{
			QueueHouse(ent, "HOUSEWOODE1I01_P");
			return true;
		}

		if (IsHousePrefab(info, LootHouse_WoodenE1I01.PREFAB))
		{
			QueueHouse(ent, "HOUSEWOODE1I01");
			return true;
		}

		if (IsHousePrefab(info, LootHouse_WoodenE1I03.PREFAB))
		{
			QueueHouse(ent, "HOUSEWOODE1I03");
			return true;
		}

		if (IsHousePrefab(info, LootHouse_TownE2I02.PREFAB))
		{
			QueueHouse(ent, "HOUSETOWNE2I02Y");
			return true;
		}

		if (IsHousePrefab(info, LootHouse_TownE2I02.PREFAB))
		{
			QueueHouse(ent, "HOUSETOWNE2I02V2");
			return true;
		}

		if (IsHousePrefab(info, LootHouse_TownE2I02.PREFAB))
		{
			QueueHouse(ent, "HOUSETOWNE2I02B");
			return true;
		}

		if (IsHousePrefab(info, LootHouse_TownE2I02.PREFAB))
		{
			QueueHouse(ent, "HOUSETOWNE2I02");
			return true;
		}

		if (IsHousePrefab(info, LootHouseRaG.PREFAB))
		{
			QueueHouse(ent, "HOUSERAG");
			return true;
		}

		if (IsHousePrefab(info, LootHouse08.PREFAB))
		{
			QueueHouse(ent, "HOUSE08");
			return true;
		}

		if (IsHousePrefab(info, LootHouse07.PREFAB))
		{
			QueueHouse(ent, "HOUSE07");
			return true;
		}

		if (IsHousePrefab(info, LootHouse06.PREFAB))
		{
			QueueHouse(ent, "HOUSE06");
			return true;
		}

		if (IsHousePrefab(info, LootHouse05_02.PREFAB))
		{
			QueueHouse(ent, "HOUSE05_02");
			return true;
		}

		if (IsHousePrefab(info, LootHouse05.PREFAB))
		{
			QueueHouse(ent, "HOUSE05");
			return true;
		}

		if (IsHousePrefab(info, LootHouse03.PREFAB))
		{
			QueueHouse(ent, "HOUSE03");
			return true;
		}

		if (IsHousePrefab(info, LootHouse02.PREFAB))
		{
			QueueHouse(ent, "HOUSE02");
			return true;
		}

		return true;
	}

	static string GetEntityPrefabName(IEntity ent)
	{
		if (!ent)
			return "";

		EntityPrefabData prefabData = ent.GetPrefabData();

		if (!prefabData)
			return "";

		return prefabData.GetPrefabName();
	}

	static void QueueHouse(IEntity house, string houseType)
	{
		if (!house || houseType == "")
			return;

		IEntity spawnHouse = GetHouseSpawnEntity(house, houseType);

		CacheHouseType(house.ToString(), houseType);

		if (!spawnHouse)
			return;

		CacheHouseType(spawnHouse.ToString(), houseType);

		string queueKey = spawnHouse.ToString() + houseType;

		if (QueuedHouseKeySet.Contains(queueKey))
			return;

		QueuedHouseEntities.Insert(spawnHouse);
		QueuedHouseTypes.Insert(houseType);
		QueuedHouseKeys.Insert(queueKey);
		QueuedHouseKeySet.Insert(queueKey, true);
	}

	static IEntity GetHouseSpawnEntity(IEntity house, string houseType)
	{
		if (!house)
			return null;

		IEntity rootHouse = house.GetRootParent();

		if (rootHouse)
			return rootHouse;

		return house;
	}

	static void ClearQueuedHouses()
	{
		QueuedHouseEntities.Clear();
		QueuedHouseTypes.Clear();
		QueuedHouseKeys.Clear();
		QueuedHouseKeySet.Clear();
	}

	static void FlushQueuedHouses()
	{
		int count = QueuedHouseEntities.Count();

		if (MAX_HOUSES_TO_SPAWN_PER_FLUSH > 0 && count > MAX_HOUSES_TO_SPAWN_PER_FLUSH)
			count = MAX_HOUSES_TO_SPAWN_PER_FLUSH;

		for (int i = 0; i < count; i++)
		{
			IEntity house = QueuedHouseEntities[i];
			string houseType = QueuedHouseTypes[i];

			TrySpawnHouse(house, houseType);
		}

		ClearQueuedHouses();
	}

	static bool IsHousePrefab(string info, string prefab)
	{
		if (prefab == "")
			return false;

		return info.Contains(prefab);
	}

	static void TrySpawnHouse(IEntity house, string houseType)
	{
		if (!house)
			return;

		string houseKey = house.ToString();

		SpawnedHouseLoot data = ActiveHouses.Get(houseKey);

		if (!data)
		{
			data = new SpawnedHouseLoot();
			ActiveHouses.Insert(houseKey, data);
		}

		data.HousePosition = house.GetOrigin();

		if (data.IsSpawned)
		{
			data.LastPlayerNearbyTime = System.GetTickCount();
			return;
		}

		if (GetActiveLootItemCount() >= DynamicLootManager.MAX_ACTIVE_LOOT_ITEMS)
		{
			EnforceLootCap(DynamicLootManager.CurrentPlayerPositions);

			if (GetActiveLootItemCount() >= DynamicLootManager.MAX_ACTIVE_LOOT_ITEMS)
			{
				DebugPrint("[Loot] Loot cap reached, delaying loot spawn for: " + houseType);
				return;
			}
		}

		int currentTime = System.GetTickCount();

		if (data.LastDespawnTime > 0)
		{
			if (currentTime - data.LastDespawnTime < DynamicLootManager.RESPAWN_COOLDOWN_MS)
			{
				DebugPrint("[Loot] House on cooldown: " + houseType);
				return;
			}
		}

		if (DynamicLootManager.IsAnyPlayerTooClose(data.HousePosition))
		{
			DebugPrint("[Loot] Player too close, delaying loot spawn.");
			return;
		}

		data.IsSpawned = true;
		data.LastPlayerNearbyTime = currentTime;

		DebugPrint("[Loot] Spawning dynamic loot for: " + houseType);
		DebugPrint("[Loot] House origin: " + house.GetOrigin());

		CurrentHouseType = houseType;

		if (houseType == "FARMHOUSEE1L01")
			LootHouse_FarmHouseE1L01.Spawn(house, data);

		if (houseType == "FARMHOUSEE1L01_GREEN")
			LootHouse_FarmHouseE1L01.Spawn(house, data);

		if (houseType == "FARMHOUSEE1L01_WOOD")
			LootHouse_FarmHouseE1L01.Spawn(house, data);

		if (houseType == "BRICKBUILDING01")
			LootHouse_Brickbuilding01.Spawn(house, data);

		if (houseType == "HOUSE2FLOORS01")
			LootHouse_House2Floors01.Spawn(house, data);

		if (houseType == "HOUSEVILLAGEE1I04S")
			LootHouse_VillageE1I04s.Spawn(house, data);

		if (houseType == "HOUSEVILLAGEE1I05S")
			LootHouse_VillageE1I05.Spawn(house, data);

		if (houseType == "HOUSEVILLAGEE1I05T")
			LootHouse_VillageE1I05.Spawn(house, data);

		if (houseType == "HOUSEWOODE1I01_P")
			LootHouse_WoodenE1I01_P.Spawn(house, data);

		if (houseType == "HOUSEWOODE1I01")
			LootHouse_WoodenE1I01.Spawn(house, data);

		if (houseType == "HOUSEWOODE1I03")
			LootHouse_WoodenE1I03.Spawn(house, data);

		if (houseType == "HOUSETOWNE2I02Y")
			LootHouse_TownE2I02.Spawn(house, data);

		if (houseType == "HOUSETOWNE2I02V2")
			LootHouse_TownE2I02.Spawn(house, data);

		if (houseType == "HOUSETOWNE2I02B")
			LootHouse_TownE2I02.Spawn(house, data);

		if (houseType == "HOUSETOWNE2I02")
			LootHouse_TownE2I02.Spawn(house, data);

		if (houseType == "HOUSERAG")
			LootHouseRaG.Spawn(house, data);

		if (houseType == "HOUSE08")
			LootHouse08.Spawn(house, data);

		if (houseType == "HOUSE07")
			LootHouse07.Spawn(house, data);

		if (houseType == "HOUSE06")
			LootHouse06.Spawn(house, data);

		if (houseType == "HOUSE05")
			LootHouse05.Spawn(house, data);

		if (houseType == "HOUSE05_02")
			LootHouse05_02.Spawn(house, data);

		if (houseType == "HOUSE03")
			LootHouse03.Spawn(house, data);

		if (houseType == "HOUSE02")
			LootHouse02.Spawn(house, data);

		CurrentHouseType = "";

		EnforceLootCap(DynamicLootManager.CurrentPlayerPositions);
	}

	static int GetActiveLootItemCount()
	{
		return ActiveLootItemCount;
	}

	static int RecountActiveLootItemCount()
	{
		ActiveLootItemCount = 0;

		foreach (string key, SpawnedHouseLoot data : ActiveHouses)
		{
			if (!data || !data.IsSpawned)
				continue;

			foreach (IEntity item : data.Items)
			{
				if (item)
					ActiveLootItemCount++;
			}
		}

		return ActiveLootItemCount;
	}

	static void EnforceLootCap(array<vector> playerPositions)
	{
		if (DynamicLootManager.MAX_ACTIVE_LOOT_ITEMS <= 0)
			return;

		int activeLootCount = GetActiveLootItemCount();

		while (activeLootCount > DynamicLootManager.MAX_ACTIVE_LOOT_ITEMS)
		{
			if (!DespawnOldestInactiveHouse(playerPositions))
				return;

			activeLootCount = GetActiveLootItemCount();
		}
	}

	static bool DespawnOldestInactiveHouse(array<vector> playerPositions)
	{
		string oldestKey = "";
		SpawnedHouseLoot oldestData = null;
		int oldestNearbyTime = System.GetTickCount();

		foreach (string key, SpawnedHouseLoot data : ActiveHouses)
		{
			if (!data || !data.IsSpawned)
				continue;

			if (DynamicLootManager.IsAnyPlayerNearPosition(data.HousePosition, playerPositions, DynamicLootManager.DESPAWN_DISTANCE))
				continue;

			int nearbyTime = data.LastPlayerNearbyTime;

			if (nearbyTime <= 0)
				nearbyTime = 0;

			if (!oldestData || nearbyTime < oldestNearbyTime)
			{
				oldestKey = key;
				oldestData = data;
				oldestNearbyTime = nearbyTime;
			}
		}

		if (!oldestData)
			return false;

		DebugPrint("[Loot] Loot cap reached, despawning oldest inactive house: " + oldestKey);
		DespawnHouseLoot(oldestKey, oldestData);
		return true;
	}

	static void DespawnHouseLoot(string key, SpawnedHouseLoot data)
	{
		if (!data || !data.IsSpawned)
			return;

		DebugPrint("[Loot] Despawning loot for house: " + key);

		int trackedItems = 0;

		foreach (IEntity item : data.Items)
		{
			if (item)
			{
				trackedItems++;

				if (IsTrackedItemSafeToDelete(item, data))
					SCR_EntityHelper.DeleteEntityAndChildren(item);
			}
		}

		ActiveLootItemCount -= trackedItems;

		if (ActiveLootItemCount < 0)
			ActiveLootItemCount = 0;

		data.Items.Clear();
		data.IsSpawned = false;
		data.LastDespawnTime = System.GetTickCount();
	}

	static bool IsTrackedItemSafeToDelete(IEntity item, SpawnedHouseLoot data)
	{
		if (!item || !data)
			return false;

		if (vector.Distance(item.GetOrigin(), data.HousePosition) > DynamicLootManager.DESPAWN_DISTANCE)
			return false;

		return true;
	}

	static void PruneInactiveHouses(array<vector> playerPositions)
	{
		if (DynamicLootManager.INACTIVE_HOUSE_PRUNE_MS <= 0)
			return;

		int currentTime = System.GetTickCount();
		array<string> keysToRemove = {};

		foreach (string key, SpawnedHouseLoot data : ActiveHouses)
		{
			if (!data || data.IsSpawned || data.LastDespawnTime <= 0)
				continue;

			if (currentTime - data.LastDespawnTime < DynamicLootManager.INACTIVE_HOUSE_PRUNE_MS)
				continue;

			if (DynamicLootManager.IsAnyPlayerNearPosition(data.HousePosition, playerPositions, DynamicLootManager.DESPAWN_DISTANCE))
				continue;

			keysToRemove.Insert(key);
		}

		foreach (string keyToRemove : keysToRemove)
			ActiveHouses.Remove(keyToRemove);
	}

	static void SpawnWeightedFromArray(IEntity house, SpawnedHouseLoot data, array<vector> offsets, array<ref LootEntry> lootTable, float chance, string category, vector localAngles, float spread = 0.02)
	{
		array<ref LootEntry> effectiveLootTable = LootServerConfigManager.GetLootTable(category, lootTable, CurrentHouseType);

		foreach (vector offset : offsets)
		{
			if (Math.RandomFloat(0, 1) > chance)
				continue;

			vector worldPos = house.CoordToParent(offset);

			worldPos = worldPos + Vector(
				Math.RandomFloat(-spread, spread),
				0.0,
				Math.RandomFloat(-spread, spread)
			);

			IEntity item = SpawnWeightedLoot(worldPos, effectiveLootTable, house, localAngles);

			if (item)
			{
				data.Items.Insert(item);
				ActiveLootItemCount++;
			}
		}
	}

	static void SpawnFromArray(IEntity house, SpawnedHouseLoot data, array<vector> offsets, array<string> items, float chance, string category, vector localAngles, float spread = 0.02)
	{
		foreach (vector offset : offsets)
		{
			if (Math.RandomFloat(0, 1) > chance)
				continue;

			vector worldPos = house.CoordToParent(offset);

			worldPos = worldPos + Vector(
				Math.RandomFloat(-spread, spread),
				0.0,
				Math.RandomFloat(-spread, spread)
			);

			IEntity item = SpawnLoot(worldPos, items, house, localAngles);

			if (item)
			{
				data.Items.Insert(item);
				ActiveLootItemCount++;
			}
		}
	}

	static string GetWeightedRandom(array<ref LootEntry> lootTable)
	{
		if (!lootTable || lootTable.Count() == 0)
			return "";

		float totalWeight = 0;

		foreach (LootEntry entry : lootTable)
			totalWeight += entry.Weight;

		float roll = Math.RandomFloat(0, totalWeight);
		float current = 0;

		foreach (LootEntry entry : lootTable)
		{
			current += entry.Weight;

			if (roll <= current)
				return entry.Prefab;
		}

		return lootTable[0].Prefab;
	}

	static IEntity SpawnWeightedLoot(vector pos, array<ref LootEntry> lootTable, IEntity house, vector localAngles)
	{
		string prefab = GetWeightedRandom(lootTable);

		if (prefab == "")
			return null;

		DebugPrint("[Loot] Weighted picked: " + prefab);

		ref array<string> tempItems = { prefab };

		return SpawnLoot(pos, tempItems, house, localAngles);
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

	static IEntity SpawnLoot(vector pos, array<string> items, IEntity house, vector localAngles)
	{
		if (!items || items.Count() == 0)
			return null;

		string prefab = items.GetRandomElement();
		Resource res = GetCachedResource(prefab);

		if (!res)
		{
			WarningPrint("[Loot] Could not load prefab: " + prefab);
			return null;
		}

		EntitySpawnParams params = new EntitySpawnParams();
		params.TransformMode = ETransformMode.WORLD;

		vector houseMat[4];
		house.GetWorldTransform(houseMat);

		vector localMat[4];
		Math3D.AnglesToMatrix(localAngles, localMat);

		vector finalMat[4];
		Math3D.MatrixMultiply3(houseMat, localMat, finalMat);

		finalMat[3] = pos;
		params.Transform = finalMat;

		IEntity item = GetGame().SpawnEntityPrefab(
			res,
			GetGame().GetWorld(),
			params
		);

		if (item)
		{
			DebugPrint("[Loot] Spawned: " + prefab);
			return item;
		}

		WarningPrint("[Loot] FAILED spawn: " + prefab);
		return null;
	}
}
