class LootHouse_TownE2I01
{
	static string PREFAB = "{38A5F3E4578087AB}Prefabs/Structures/Houses/Town/House_Town_E_2I01/House_Town_E_2I01.et";
	static string PREFAB_ORANGE = "{C50CF821412A2E0F}Prefabs/Structures/Houses/Town/House_Town_E_2I01/House_Town_E_2I01_orange.et";
	static ref array<vector> BedSpawns;

	static array<vector> GetBedSpawns()
	{
		if (!BedSpawns)
		{
			BedSpawns = new array<vector>();
			BedSpawns.Insert("5.216 0.706 -0.52");
			BedSpawns.Insert("3.882 0.706 -1.665");
			BedSpawns.Insert("5.183 0.768 4.119");
			BedSpawns.Insert("-0.668 4.876 2.111");
			BedSpawns.Insert("-2.172 4.876 2.123");
			BedSpawns.Insert("3.202 4.792 6.309");
			BedSpawns.Insert("5.06 4.762 6.355");
			BedSpawns.Insert("1.192 4.869 5.962");
			BedSpawns.Insert("-1.168 4.869 6.301");
			BedSpawns.Insert("-4.903 4.806 6.546");
			BedSpawns.Insert("-4.763 4.806 5.108");
		}

		return BedSpawns;
	}
	static ref array<vector> KitchenSpawns;

	static array<vector> GetKitchenSpawns()
	{
		if (!KitchenSpawns)
		{
			KitchenSpawns = new array<vector>();
			KitchenSpawns.Insert("-0.544 1.232 3.503");
			KitchenSpawns.Insert("0.212 1.232 3.477");
			KitchenSpawns.Insert("-0.749 1.116 6.162");
			KitchenSpawns.Insert("3.918 1.101 4.523");
			KitchenSpawns.Insert("3.782 1.101 5.264");
			KitchenSpawns.Insert("3.677 0.774 6.49");
			KitchenSpawns.Insert("-1.137 5.008 2.521");
			KitchenSpawns.Insert("-1.546 5.008 2.52");
			KitchenSpawns.Insert("5.542 5.056 5.234");
			KitchenSpawns.Insert("4.654 4.912 4.019");
			KitchenSpawns.Insert("-0.513 5.323 3.507");
			KitchenSpawns.Insert("0.233 5.324 3.504");
			KitchenSpawns.Insert("1.561 5.33 3.592");
			KitchenSpawns.Insert("0.433 5.205 5.942");
			KitchenSpawns.Insert("-0.255 5.205 6.033");
			KitchenSpawns.Insert("-0.222 5.205 6.681");
			KitchenSpawns.Insert("0.528 5.205 6.756");
		}

		return KitchenSpawns;
	}
	static ref array<vector> WeaponSpawns;

	static array<vector> GetWeaponSpawns()
	{
		if (!WeaponSpawns)
		{
			WeaponSpawns = new array<vector>();
			WeaponSpawns.Insert("5.311 1.214 2.717");
			WeaponSpawns.Insert("0.353 0.817 0.135");
			WeaponSpawns.Insert("-1.365 4.916 0.071");
			WeaponSpawns.Insert("5.357 8.026 -0.672");
			WeaponSpawns.Insert("3.669 8.163 5.661");
			WeaponSpawns.Insert("0.87 5.3 2.424");
			WeaponSpawns.Insert("-2.981 5.211 6.721");
		}

		return WeaponSpawns;
	}
	static ref array<vector> MedicalSpawns;

	static array<vector> GetMedicalSpawns()
	{
		if (!MedicalSpawns)
		{
			MedicalSpawns = new array<vector>();
			MedicalSpawns.Insert("3.053 0.896 -4.988");
			MedicalSpawns.Insert("3.221 0.267 -6.538");
			MedicalSpawns.Insert("3.221 0.267 -7.329");
			MedicalSpawns.Insert("5.281 0.751 -6.706");
			MedicalSpawns.Insert("5.206 0.766 -4.966");
			MedicalSpawns.Insert("5.228 1.207 -5.961");
			MedicalSpawns.Insert("-2.527 5.218 -3.245");
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
			ToolSpawns.Insert("-5.269 4.318 -4.645");
			ToolSpawns.Insert("-2.507 7.619 -4.576");
			ToolSpawns.Insert("-5.062 7.619 -3.172");
			ToolSpawns.Insert("3.337 7.619 -6.151");
			ToolSpawns.Insert("5.031 7.619 3.856");
			ToolSpawns.Insert("0.212 7.619 4.275");
			ToolSpawns.Insert("-5.403 7.632 6.151");
		}

		return ToolSpawns;
	}
	static void Spawn(IEntity house, SpawnedHouseLoot data)
	{
		if (!house || !data)
			return;
		LootSpawner.SpawnWeightedFromArray(house, data, GetBedSpawns(), LootTables.GetTownE2I02BedLoot(), 0.18, "BED", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetKitchenSpawns(), LootTables.GetTownE2I02KitchenItems(), 0.14, "KITCHEN", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetWeaponSpawns(), LootTables.GetTownE2I02WeaponItems(), 0.07, "WEAPON", "0 0 0", 0.02);
		LootSpawner.SpawnWeightedFromArray(house, data, GetMedicalSpawns(), LootTables.GetTownE2I02MedicalItems(), 0.14, "MEDICAL", "0 0 0", 0.01);
	}
}
