class LootHouse_Brickbuilding01
{
	static string PREFAB = "{5D6D34810978F2D9}Prefabs/Structures/Houses/Village/Larger buildings/Brickbuilding01.et";
	static ref array<vector> BedSpawns;

	static array<vector> GetBedSpawns()
	{
		if (!BedSpawns)
		{
			BedSpawns = new array<vector>();
			BedSpawns.Insert("-0.869 0.945 -7.01");
			BedSpawns.Insert("-0.517 0.945 -5.531");
			BedSpawns.Insert("-5.444 0.945 -5.553");
			BedSpawns.Insert("-5.322 0.945 -6.821");
			BedSpawns.Insert("-1.291 4.06 4.845");
			BedSpawns.Insert("-1.386 4.06 6.355");
			BedSpawns.Insert("3.552 4.06 -5.531");
			BedSpawns.Insert("3.392 4.06 -7.049");
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
			KitchenSpawns.Insert("-3.193 1.445 1.874");
			KitchenSpawns.Insert("-4.013 1.445 1.827");
			KitchenSpawns.Insert("-3.201 1.321 5.969");
			KitchenSpawns.Insert("-0.796 1.346 4.886");
			KitchenSpawns.Insert("-5.477 4.051 -1.552");
			KitchenSpawns.Insert("-5.477 4.051 -3.683");
			KitchenSpawns.Insert("-5.412 4.051 -2.519");
			KitchenSpawns.Insert("-3.793 4.451 -5.343");
			KitchenSpawns.Insert("-3.976 4.451 -6.209");
			KitchenSpawns.Insert("0.126 4.451 -6.074");
			KitchenSpawns.Insert("4.757 5.078 0.774");
		}

		return KitchenSpawns;
	}
	static ref array<vector> WeaponSpawns;

	static array<vector> GetWeaponSpawns()
	{
		if (!WeaponSpawns)
		{
			WeaponSpawns = new array<vector>();
			WeaponSpawns.Insert("-5.622 1.442 -3.102");
			WeaponSpawns.Insert("-4.903 0.909 0.363");
			WeaponSpawns.Insert("-0.667 4.102 -0.772");
			WeaponSpawns.Insert("0.163 4.45 -5.515");
			WeaponSpawns.Insert("6.348 4.15 -5.945");
		}

		return WeaponSpawns;
	}
	static ref array<vector> MedicalSpawns;

	static array<vector> GetMedicalSpawns()
	{
		if (!MedicalSpawns)
		{
			MedicalSpawns = new array<vector>();
			MedicalSpawns.Insert("0.796 0.934 2.154");
			MedicalSpawns.Insert("-3.822 0.923 5.505");
			MedicalSpawns.Insert("-2.793 0.923 6.098");
			MedicalSpawns.Insert("2.951 4.108 2.097");
			MedicalSpawns.Insert("1.084 3.663 1.977");
			MedicalSpawns.Insert("0.127 4.101 6.572");
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
			ToolSpawns.Insert("2.79 1.348 1.992");
			ToolSpawns.Insert("2.046 1.348 2.073");
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
