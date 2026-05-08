class LootHouse_WoodenE1I01_P
{
	static string PREFAB = "{FD91510268A541A7}PrefabLibrary/DefaultLibrary/Structures/Houses/House_Wooden_E_1I01/House_Wooden_E_1I01_panels.et";
	static ref array<vector> BedSpawns;

	static array<vector> GetBedSpawns()
	{
		if (!BedSpawns)
		{
			BedSpawns = new array<vector>();
			BedSpawns.Insert("3.362 1.658 2.011");
			BedSpawns.Insert("3.662 1.864 1.201");
		}

		return BedSpawns;
	}
	static ref array<vector> KitchenSpawns;

	static array<vector> GetKitchenSpawns()
	{
		if (!KitchenSpawns)
		{
			KitchenSpawns = new array<vector>();
			KitchenSpawns.Insert("-0.952 2.062 -2.256");
			KitchenSpawns.Insert("-0.062 2.062 -2.055");
			KitchenSpawns.Insert("-2.508 2.085 -0.768");
			KitchenSpawns.Insert("-3.281 2.182 -0.501");
			KitchenSpawns.Insert("-3.968 2.181 -0.636");
		}

		return KitchenSpawns;
	}
	static ref array<vector> WeaponSpawns;

	static array<vector> GetWeaponSpawns()
	{
		if (!WeaponSpawns)
		{
			WeaponSpawns = new array<vector>();
			WeaponSpawns.Insert("1.463 2.173 -2.464");
		}

		return WeaponSpawns;
	}
	static ref array<vector> MedicalSpawns;

	static array<vector> GetMedicalSpawns()
	{
		if (!MedicalSpawns)
		{
			MedicalSpawns = new array<vector>();
			MedicalSpawns.Insert("-3.705 2.304 2.704");
			MedicalSpawns.Insert("-4.855 2.02 2.186");
			MedicalSpawns.Insert("-4.587 1.173 0.676");
		}

		return MedicalSpawns;
	}
	static void Spawn(IEntity house, SpawnedHouseLoot data)
	{
		if (!house || !data)
			return;
		LootSpawner.SpawnWeightedFromArray(house, data, GetBedSpawns(), LootTables.GetE1I01_PBedLoot(), 0.5, "BED", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetKitchenSpawns(), LootTables.GetE1I01_PKitchenItems(), 0.5, "KITCHEN", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetWeaponSpawns(), LootTables.GetE1I01_PWeaponItems(), 0.1, "WEAPON", "90 0 90", 0.02);
		LootSpawner.SpawnWeightedFromArray(house, data, GetMedicalSpawns(), LootTables.GetE1I01_PMedicalItems(), 0.35, "MEDICAL", "0 0 0", 0.01);
	}
}
