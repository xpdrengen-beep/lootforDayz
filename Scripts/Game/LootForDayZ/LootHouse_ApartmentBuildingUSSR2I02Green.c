class LootHouse_ApartmentBuildingUSSR2I02Green
{
	static string PREFAB = "{1EBBC2A6B198BD9E}Prefabs/Structures/Military/Houses/ApartmentBuilding_2I02/ApartmentBuilding_USSR_2I02_green.et";
	static ref array<vector> BedSpawns;

	static array<vector> GetBedSpawns()
	{
		if (!BedSpawns)
		{
			BedSpawns = new array<vector>();
			BedSpawns.Insert("6.131 2.003 -5.943");
			BedSpawns.Insert("-2.777 2.003 6.25");
			BedSpawns.Insert("-2.569 2.003 -2.826");
			BedSpawns.Insert("-2.477 2.003 -6.189");
			BedSpawns.Insert("4.21 4.985 -1.947");
			BedSpawns.Insert("7.828 5.401 -5.09");
			BedSpawns.Insert("8.661 5.401 1.87");
			BedSpawns.Insert("6.092 5.401 5.846");
			BedSpawns.Insert("3.056 5.401 3.975");
			BedSpawns.Insert("-6.109 5.401 5.794");
			BedSpawns.Insert("-3.48 5.401 -1.9");
			BedSpawns.Insert("-6.014 5.401 -5.749");
			BedSpawns.Insert("-2.628 5.401 -5.832");
			BedSpawns.Insert("-10.182 4.979 -5.853");
			BedSpawns.Insert("-10.214 4.979 -4.15");
			BedSpawns.Insert("-10.231 4.979 -5.033");
			BedSpawns.Insert("1.353 4.979 -3.766");
			BedSpawns.Insert("1.424 6.042 -5.299");
		}

		return BedSpawns;
	}
	static ref array<vector> KitchenSpawns;

	static array<vector> GetKitchenSpawns()
	{
		if (!KitchenSpawns)
		{
			KitchenSpawns = new array<vector>();
			KitchenSpawns.Insert("2.638 2.001 -4.73");
			KitchenSpawns.Insert("2.598 2.001 -3.579");
			KitchenSpawns.Insert("3.695 2.001 -3.587");
			KitchenSpawns.Insert("7.228 2.001 5.672");
			KitchenSpawns.Insert("7.381 2.001 4.606");
			KitchenSpawns.Insert("5.941 2.001 4.558");
			KitchenSpawns.Insert("5.944 2.001 5.85");
			KitchenSpawns.Insert("2.719 2.001 6.169");
			KitchenSpawns.Insert("-10.025 2.001 4.826");
			KitchenSpawns.Insert("-10.071 2.001 5.751");
			KitchenSpawns.Insert("-5.792 2.001 -4.934");
			KitchenSpawns.Insert("-5.814 2.001 -6.74");
			KitchenSpawns.Insert("5.925 5.405 -5.145");
			KitchenSpawns.Insert("5.922 5.405 -6.436");
			KitchenSpawns.Insert("-7.298 5.401 5.561");
			KitchenSpawns.Insert("-7.247 5.401 6.516");
			KitchenSpawns.Insert("-8.009 5.41 -5.583");
			KitchenSpawns.Insert("-1.22 5.393 -6.217");
			KitchenSpawns.Insert("-1.326 5.393 -7.107");
		}

		return KitchenSpawns;
	}
	static ref array<vector> WeaponSpawns;

	static array<vector> GetWeaponSpawns()
	{
		if (!WeaponSpawns)
		{
			WeaponSpawns = new array<vector>();
			WeaponSpawns.Insert("-2.25 0.514 1.096");
			WeaponSpawns.Insert("8.436 1.999 -1.838");
			WeaponSpawns.Insert("10.065 2.537 -4.505");
			WeaponSpawns.Insert("3.272 2.537 -1.952");
			WeaponSpawns.Insert("10.151 2.004 5.322");
			WeaponSpawns.Insert("-7.332 1.592 5.839");
			WeaponSpawns.Insert("-7.987 2 -5.381");
			WeaponSpawns.Insert("2.601 5.405 -3.561");
			WeaponSpawns.Insert("2.571 5.491 -5.931");
			WeaponSpawns.Insert("10.156 5.937 -5.168");
			WeaponSpawns.Insert("-5.154 5.405 1.947");
			WeaponSpawns.Insert("-9.145 5.495 1.902");
			WeaponSpawns.Insert("1.199 4.985 -5.256");
			WeaponSpawns.Insert("1.128 6.075 -3.879");
		}

		return WeaponSpawns;
	}
	static ref array<vector> MedicalSpawns;

	static array<vector> GetMedicalSpawns()
	{
		if (!MedicalSpawns)
		{
			MedicalSpawns = new array<vector>();
			MedicalSpawns.Insert("10.087 1.661 -0.626");
			MedicalSpawns.Insert("10.591 1.347 0.632");
			MedicalSpawns.Insert("7.531 1.874 0.854");
			MedicalSpawns.Insert("8.849 1.799 1.775");
			MedicalSpawns.Insert("2.689 2.001 5.654");
			MedicalSpawns.Insert("6.283 2.001 1.884");
			MedicalSpawns.Insert("5.352 2.001 1.627");
			MedicalSpawns.Insert("-5.939 2.001 4.58");
			MedicalSpawns.Insert("-9.204 2.097 1.851");
			MedicalSpawns.Insert("-8.18 2.097 1.916");
			MedicalSpawns.Insert("-7.77 1.795 -1.917");
			MedicalSpawns.Insert("-10.042 1.656 -0.521");
			MedicalSpawns.Insert("-7.498 1.849 0.933");
			MedicalSpawns.Insert("3.75 5.401 4.244");
			MedicalSpawns.Insert("5.943 5.401 6.444");
			MedicalSpawns.Insert("-2.733 5.401 3.743");
			MedicalSpawns.Insert("-2.698 5.401 4.9");
			MedicalSpawns.Insert("-10.237 5.401 3.946");
			MedicalSpawns.Insert("-10.183 5.401 4.789");
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
			ToolSpawns.Insert("-1.052 1.105 -3.668");
			ToolSpawns.Insert("-0.921 1.105 -7.051");
			ToolSpawns.Insert("1.317 1.105 -6.861");
			ToolSpawns.Insert("0.145 7.902 -2.924");
			ToolSpawns.Insert("-2.809 7.902 5.174");
			ToolSpawns.Insert("3.122 7.902 3.221");
			ToolSpawns.Insert("5.207 8.291 2.349");
			ToolSpawns.Insert("4.372 8.291 2.336");
			ToolSpawns.Insert("5.651 7.895 -2.532");
			ToolSpawns.Insert("-9.86 7.895 -0.783");
		}

		return ToolSpawns;
	}
	static void Spawn(IEntity house, SpawnedHouseLoot data)
	{
		if (!house || !data)
			return;
		LootSpawner.SpawnWeightedFromArray(house, data, GetBedSpawns(), LootTables.GetTownE2I02BedLoot(), 0.09, "BED", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetKitchenSpawns(), LootTables.GetTownE2I02KitchenItems(), 0.08, "KITCHEN", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetWeaponSpawns(), LootTables.GetTownE2I02WeaponItems(), 0.03, "WEAPON", "0 0 0", 0.02);
		LootSpawner.SpawnWeightedFromArray(house, data, GetMedicalSpawns(), LootTables.GetTownE2I02MedicalItems(), 0.07, "MEDICAL", "0 0 0", 0.01);
	}
}
