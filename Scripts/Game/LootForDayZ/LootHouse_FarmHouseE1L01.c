class LootHouse_FarmHouseE1L01
{
	static string PREFAB = "{0E7899885A92BF4F}PrefabLibrary/DefaultLibrary/Structures/Houses/FarmHouse_E_1L01/FarmHouse_E_1L01.et";
	static string PREFAB_GREEN = "{8A54FD8F840E3BC4}PrefabLibrary/DefaultLibrary/Structures/Houses/FarmHouse_E_1L01/FarmHouse_E_1L01_Green.et";
	static string PREFAB_WOOD = "{9ACCDC76D1EBDA27}PrefabLibrary/DefaultLibrary/Structures/Houses/FarmHouse_E_1L01/FarmHouse_E_1L01_Wood.et";
	static ref array<vector> BedSpawns;

	static array<vector> GetBedSpawns()
	{
		if (!BedSpawns)
		{
			BedSpawns = new array<vector>();
			BedSpawns.Insert("2.234 0.306 1.16");
			BedSpawns.Insert("4.191 4.049 -4.043");
			BedSpawns.Insert("4.241 4.049 -5.725");
			BedSpawns.Insert("4.157 4.049 -4.856");
			BedSpawns.Insert("-7.12 4.084 -4.255");
			BedSpawns.Insert("-8.663 4.084 -3.771");
			BedSpawns.Insert("-7.022 4.088 -6.385");
			BedSpawns.Insert("-8.605 4.08 -6.751");
		}

		return BedSpawns;
	}
	static ref array<vector> KitchenSpawns;

	static array<vector> GetKitchenSpawns()
	{
		if (!KitchenSpawns)
		{
			KitchenSpawns = new array<vector>();
			KitchenSpawns.Insert("0.625 1.18 -7.11");
			KitchenSpawns.Insert("1.369 1.183 -8.109");
			KitchenSpawns.Insert("-3.785 1.306 -5.574");
			KitchenSpawns.Insert("-5.65 1.306 -5.72");
			KitchenSpawns.Insert("4.451 1.049 -7.416");
			KitchenSpawns.Insert("4.257 0.783 -6.551");
			KitchenSpawns.Insert("-8.924 4.072 -5.301");
			KitchenSpawns.Insert("-4.458 4.086 -6.987");
		}

		return KitchenSpawns;
	}
	static ref array<vector> WeaponSpawns;

	static array<vector> GetWeaponSpawns()
	{
		if (!WeaponSpawns)
		{
			WeaponSpawns = new array<vector>();
			WeaponSpawns.Insert("1.947 1.811 -2.659");
			WeaponSpawns.Insert("1.083 4.594 -4.665");
			WeaponSpawns.Insert("-5.521 4.594 -3.694");
			WeaponSpawns.Insert("-8.968 4.29 -5.286");
		}

		return WeaponSpawns;
	}
	static ref array<vector> MedicalSpawns;

	static array<vector> GetMedicalSpawns()
	{
		if (!MedicalSpawns)
		{
			MedicalSpawns = new array<vector>();
			MedicalSpawns.Insert("-1.289 1.275 8.169");
			MedicalSpawns.Insert("-2.497 0.633 -3.992");
			MedicalSpawns.Insert("-4.501 1.398 -4.889");
			MedicalSpawns.Insert("-4.501 0.809 -4.421");
			MedicalSpawns.Insert("-2.394 1.167 -2.991");
		}

		return MedicalSpawns;
	}
	// Tool spawn points are kept for later tool loot support. No items are spawned from these points yet.
	static ref array<vector> ToolSpawns;

	static array<vector> GetToolSpawns()
	{
		if (!ToolSpawns)
		{
			ToolSpawns = new array<vector>();
			ToolSpawns.Insert("3.377 0.284 6.615");
			ToolSpawns.Insert("0.322 0.284 8.564");
			ToolSpawns.Insert("1.906 1.315 10.051");
			ToolSpawns.Insert("4.099 1.262 9.791");
			ToolSpawns.Insert("0.238 1.18 -1.483");
			ToolSpawns.Insert("-1.059 0.709 -1.506");
		}

		return ToolSpawns;
	}
	static void Spawn(IEntity house, SpawnedHouseLoot data)
	{
		if (!house || !data)
			return;
		LootSpawner.SpawnWeightedFromArray(house, data, GetBedSpawns(), LootTables.GetTownE2I02BedLoot(), 0.24, "BED", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetKitchenSpawns(), LootTables.GetTownE2I02KitchenItems(), 0.20, "KITCHEN", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetWeaponSpawns(), LootTables.GetTownE2I02WeaponItems(), 0.08, "WEAPON", "0 0 0", 0.02);
		LootSpawner.SpawnWeightedFromArray(house, data, GetMedicalSpawns(), LootTables.GetTownE2I02MedicalItems(), 0.18, "MEDICAL", "0 0 0", 0.01);
	}
}
