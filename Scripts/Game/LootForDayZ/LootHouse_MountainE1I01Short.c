class LootHouse_MountainE1I01Short
{
	static string PREFAB = "{678574044F58E1CA}Prefabs/Structures/Houses/Village/House_Mountain_E_1I01/House_Mountain_E_1I01_short.et";
	static ref array<vector> BedSpawns;

	static array<vector> GetBedSpawns()
	{
		if (!BedSpawns)
		{
			BedSpawns = new array<vector>();
			BedSpawns.Insert("3.275 0.501 2.046");
			BedSpawns.Insert("2.887 0.501 0.733");
			BedSpawns.Insert("1.954 0.501 2.114");
			BedSpawns.Insert("-1.311 0.575 3.382");
			BedSpawns.Insert("-9.274 0.557 -3.348");
		}

		return BedSpawns;
	}
	static ref array<vector> KitchenSpawns;

	static array<vector> GetKitchenSpawns()
	{
		if (!KitchenSpawns)
		{
			KitchenSpawns = new array<vector>();
			KitchenSpawns.Insert("-7.025 1.005 1.798");
			KitchenSpawns.Insert("-7.183 1.005 2.859");
			KitchenSpawns.Insert("-10.529 0.885 0.402");
			KitchenSpawns.Insert("-10.694 0.885 -0.477");
			KitchenSpawns.Insert("-10.051 0.848 2.687");
			KitchenSpawns.Insert("-10.441 0.848 3.837");
			KitchenSpawns.Insert("-9.838 0.848 3.711");
		}

		return KitchenSpawns;
	}
	static ref array<vector> WeaponSpawns;

	static array<vector> GetWeaponSpawns()
	{
		if (!WeaponSpawns)
		{
			WeaponSpawns = new array<vector>();
			WeaponSpawns.Insert("-0.662 0.717 3.449");
			WeaponSpawns.Insert("-8.764 0.807 0.504");
			WeaponSpawns.Insert("-6.963 1.003 -3.304");
		}

		return WeaponSpawns;
	}
	static ref array<vector> MedicalSpawns;

	static array<vector> GetMedicalSpawns()
	{
		if (!MedicalSpawns)
		{
			MedicalSpawns = new array<vector>();
			MedicalSpawns.Insert("-0.956 0.543 -2.568");
			MedicalSpawns.Insert("-1.534 0.111 -3.575");
			MedicalSpawns.Insert("-0.862 0.111 -3.616");
			MedicalSpawns.Insert("-1.702 0.928 -1.074");
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
			ToolSpawns.Insert("0.229 1.365 -3.655");
			ToolSpawns.Insert("0.264 1.365 -2.57");
			ToolSpawns.Insert("-5.95 0.612 -0.064");
			ToolSpawns.Insert("-6.016 0.521 3.436");
		}

		return ToolSpawns;
	}
	static void Spawn(IEntity house, SpawnedHouseLoot data)
	{
		if (!house || !data)
			return;
		LootSpawner.SpawnWeightedFromArray(house, data, GetBedSpawns(), LootTables.GetTownE2I02BedLoot(), 0.22, "BED", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetKitchenSpawns(), LootTables.GetTownE2I02KitchenItems(), 0.16, "KITCHEN", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetWeaponSpawns(), LootTables.GetTownE2I02WeaponItems(), 0.06, "WEAPON", "0 0 0", 0.02);
		LootSpawner.SpawnWeightedFromArray(house, data, GetMedicalSpawns(), LootTables.GetTownE2I02MedicalItems(), 0.12, "MEDICAL", "0 0 0", 0.01);
	}
}
