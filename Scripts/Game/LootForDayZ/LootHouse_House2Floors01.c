class LootHouse_House2Floors01
{
	static string PREFAB = "{5340392A98705BEB}Prefabs/Structures/Houses/Village/Larger buildings/House2floors_01.et";
	static ref array<vector> BedSpawns;

	static array<vector> GetBedSpawns()
	{
		if (!BedSpawns)
		{
			BedSpawns = new array<vector>();
			BedSpawns.Insert("-1.691 0.493 0.765");
			BedSpawns.Insert("-0.446 0.493 0.716");
			BedSpawns.Insert("-2.579 3.838 2.149");
			BedSpawns.Insert("-2.494 3.854 -2.638");
		}

		return BedSpawns;
	}
	static ref array<vector> KitchenSpawns;

	static array<vector> GetKitchenSpawns()
	{
		if (!KitchenSpawns)
		{
			KitchenSpawns = new array<vector>();
			KitchenSpawns.Insert("1.987 0.927 -4.676");
			KitchenSpawns.Insert("0.183 1.129 -4.712");
			KitchenSpawns.Insert("-0.585 1.13 -4.727");
			KitchenSpawns.Insert("-1.446 1.139 -4.741");
			KitchenSpawns.Insert("2.519 1.009 3.792");
			KitchenSpawns.Insert("2.844 1.009 4.623");
			KitchenSpawns.Insert("2.136 1.009 4.395");
		}

		return KitchenSpawns;
	}
	static ref array<vector> WeaponSpawns;

	static array<vector> GetWeaponSpawns()
	{
		if (!WeaponSpawns)
		{
			WeaponSpawns = new array<vector>();
			WeaponSpawns.Insert("-3.503 3.853 3.471");
			WeaponSpawns.Insert("-2.531 3.856 -3.779");
		}

		return WeaponSpawns;
	}
	static ref array<vector> MedicalSpawns;

	static array<vector> GetMedicalSpawns()
	{
		if (!MedicalSpawns)
		{
			MedicalSpawns = new array<vector>();
			MedicalSpawns.Insert("0.359 4.334 -4.619");
			MedicalSpawns.Insert("-0.671 4.334 -4.62");
		}

		return MedicalSpawns;
	}
	// Tool spawns are configurable through TOOL or HOUSE_TYPE.TOOL server tables.
	static ref array<vector> ToolSpawns;

	static array<vector> GetToolSpawns()
	{
		if (!ToolSpawns)
		{
			ToolSpawns = new array<vector>();
			ToolSpawns.Insert("-7.848 1.234 5.062");
		}

		return ToolSpawns;
	}
	static void Spawn(IEntity house, SpawnedHouseLoot data)
	{
		if (!house || !data)
			return;
		LootSpawner.SpawnWeightedFromArray(house, data, GetBedSpawns(), LootTables.GetHouse2Floors01BedLoot(), 0.32, "BED", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetKitchenSpawns(), LootTables.GetHouse2Floors01KitchenItems(), 0.28, "KITCHEN", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetWeaponSpawns(), LootTables.GetHouse2Floors01WeaponItems(), 0.12, "WEAPON", "0 0 0", 0.02);
		LootSpawner.SpawnWeightedFromArray(house, data, GetMedicalSpawns(), LootTables.GetHouse2Floors01MedicalItems(), 0.22, "MEDICAL", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetToolSpawns(), LootTables.GetToolItems(), 0.18, "TOOL", "0 0 0", 0.01);
	}
}
