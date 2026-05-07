class LootSpawner
{
	static ref map<string, ref SpawnedHouseLoot> ActiveHouses = new map<string, ref SpawnedHouseLoot>();

	static bool HouseCallback(IEntity ent)
	{
		if (!ent)
			return true;

		string info = ent.ToString();
		
		if (IsHousePrefab(info, LootHouse_WoodenE1I01_P.PREFAB))
		{
			TrySpawnHouse(ent, "HOUSEWOODE1I01_P");
			return true;
		}
		
		if (IsHousePrefab(info, LootHouse_WoodenE1I01.PREFAB))
		{
			TrySpawnHouse(ent, "HOUSEWOODE1I01");
			return true;
		}
		
		if (IsHousePrefab(info, LootHouse_WoodenE1I03.PREFAB))
		{
			TrySpawnHouse(ent, "HOUSEWOODE1I03");
			return true;
		}
		
		if (IsHousePrefab(info, LootHouseRaG.PREFAB))
		{
			TrySpawnHouse(ent, "HOUSERAG");
			return true;
		}
		
		if (IsHousePrefab(info, LootHouse07.PREFAB))
		{
			TrySpawnHouse(ent, "HOUSE07");
			return true;
		}		

		if (IsHousePrefab(info, LootHouse05_02.PREFAB))
		{
			TrySpawnHouse(ent, "HOUSE05_02");
			return true;
		}
		
		if (IsHousePrefab(info, LootHouse05.PREFAB))
		{
			TrySpawnHouse(ent, "HOUSE05");
			return true;
		}

		if (IsHousePrefab(info, LootHouse03.PREFAB))
		{
			TrySpawnHouse(ent, "HOUSE03");
			return true;
		}

		if (IsHousePrefab(info, LootHouse02.PREFAB))
		{
			TrySpawnHouse(ent, "HOUSE02");
			return true;
		}

		return true;
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
			LootHouseRaG.Spawn(house, data);
		
		if (houseType == "HOUSEWOODE1I01")
			LootHouseRaG.Spawn(house, data);
		
		if (houseType == "HOUSEWOODE1I03")
			LootHouse_WoodenE1I03.Spawn(house, data);
		
		if (houseType == "HOUSERAG")
			LootHouseRaG.Spawn(house, data);		
		
		if (houseType == "HOUSE07")
			LootHouse07.Spawn(house, data);		
		
		if (houseType == "HOUSE05")
			LootHouse05.Spawn(house, data);

		if (houseType == "HOUSE05_02")
			LootHouse05_02.Spawn(house, data);
		
		if (houseType == "HOUSE03")
			LootHouse03.Spawn(house, data);

		if (houseType == "HOUSE02")
			LootHouse02.Spawn(house, data);
	}

	static void SpawnWeightedFromArray(IEntity house, SpawnedHouseLoot data, array<vector> offsets, array<ref LootEntry> lootTable, float chance, string category, vector localAngles, float spread = 0.02)
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

			IEntity item = SpawnWeightedLoot(worldPos, lootTable, house, localAngles);

			if (item)
				data.Items.Insert(item);
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
				data.Items.Insert(item);
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