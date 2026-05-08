class LootSpawner
{
	static ref map<string, ref SpawnedHouseLoot> ActiveHouses = new map<string, ref SpawnedHouseLoot>();
	static ref array<IEntity> QueuedHouseEntities = new array<IEntity>();
	static ref array<string> QueuedHouseTypes = new array<string>();
	static ref array<string> QueuedHouseKeys = new array<string>();
	static int ActiveLootItemCount = 0;

	static bool HouseCallback(IEntity ent)
	{
		if (!ent)
			return true;

		string info = GetEntityPrefabName(ent);

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

		if (!spawnHouse)
			return;

		string queueKey = spawnHouse.ToString() + houseType;

		if (QueuedHouseKeys.Contains(queueKey))
			return;

		QueuedHouseEntities.Insert(spawnHouse);
		QueuedHouseTypes.Insert(houseType);
		QueuedHouseKeys.Insert(queueKey);
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
	}

	static void FlushQueuedHouses()
	{
		int count = QueuedHouseEntities.Count();

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
				Print("[Loot] Loot cap reached, delaying loot spawn for: " + houseType);
				return;
			}
		}

		int currentTime = System.GetTickCount();

		if (data.LastDespawnTime > 0)
		{
			if (currentTime - data.LastDespawnTime < DynamicLootManager.RESPAWN_COOLDOWN_MS)
			{
				Print("[Loot] House on cooldown: " + houseType);
				return;
			}
		}

		if (DynamicLootManager.IsAnyPlayerTooClose(data.HousePosition))
		{
			Print("[Loot] Player too close, delaying loot spawn.");
			return;
		}

		data.IsSpawned = true;
		data.LastPlayerNearbyTime = currentTime;

		Print("[Loot] Spawning dynamic loot for: " + houseType);
		Print("[Loot] House origin: " + house.GetOrigin());

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

		Print("[Loot] Loot cap reached, despawning oldest inactive house: " + oldestKey);
		DespawnHouseLoot(oldestKey, oldestData);
		return true;
	}

	static void DespawnHouseLoot(string key, SpawnedHouseLoot data)
	{
		if (!data || !data.IsSpawned)
			return;

		Print("[Loot] Despawning loot for house: " + key);

		int deletedItems = 0;

		foreach (IEntity item : data.Items)
		{
			if (item)
			{
				SCR_EntityHelper.DeleteEntityAndChildren(item);
				deletedItems++;
			}
		}

		ActiveLootItemCount -= deletedItems;

		if (ActiveLootItemCount < 0)
			ActiveLootItemCount = 0;

		data.Items.Clear();
		data.IsSpawned = false;
		data.LastDespawnTime = System.GetTickCount();
	}

	static void SpawnWeightedFromArray(IEntity house, SpawnedHouseLoot data, array<vector> offsets, array<ref LootEntry> lootTable, float chance, string category, vector localAngles, float spread = 0.02)
	{
		array<ref LootEntry> effectiveLootTable = LootServerConfigManager.GetLootTable(category, lootTable);

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

		Print("[Loot] Weighted picked: " + prefab);

		ref array<string> tempItems = { prefab };

		return SpawnLoot(pos, tempItems, house, localAngles);
	}

	static IEntity SpawnLoot(vector pos, array<string> items, IEntity house, vector localAngles)
	{
		if (!items || items.Count() == 0)
			return null;

		string prefab = items.GetRandomElement();
		Resource res = Resource.Load(prefab);

		if (!res)
		{
			Print("[Loot] Could not load prefab: " + prefab);
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
			Print("[Loot] Spawned: " + prefab);
			return item;
		}

		Print("[Loot] FAILED spawn: " + prefab);
		return null;
	}
}
