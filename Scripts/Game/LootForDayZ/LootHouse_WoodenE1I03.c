class LootHouse_WoodenE1I03
{
	static string PREFAB = "{B24F05AE1E7FBBFA}PrefabLibrary/Structures/Houses/House_Wooden_E_1I03.et";
	static ref array<vector> BedSpawns;

	static array<vector> GetBedSpawns()
	{
		if (!BedSpawns)
		{
			BedSpawns = new array<vector>();
			BedSpawns.Insert("-0.266 0.622 6.611");
			BedSpawns.Insert("3.458 0.593 -2.756");
			BedSpawns.Insert("4.865 0.604 -3.915");
		}

		return BedSpawns;
	}
	static ref array<vector> KitchenSpawns;

	static array<vector> GetKitchenSpawns()
	{
		if (!KitchenSpawns)
		{
			KitchenSpawns = new array<vector>();
			KitchenSpawns.Insert("-0.103 1.004 5.402");
			KitchenSpawns.Insert("2.513 0.928 2.93");
			KitchenSpawns.Insert("4.87 1.109 5.313");
			KitchenSpawns.Insert("5.234 0.618 4.35");
		}

		return KitchenSpawns;
	}
	static ref array<vector> WeaponSpawns;

	static array<vector> GetWeaponSpawns()
	{
		if (!WeaponSpawns)
		{
			WeaponSpawns = new array<vector>();
			WeaponSpawns.Insert("2.481 0.623 2.073");
			WeaponSpawns.Insert("7.773 0.623 1.313");
		}

		return WeaponSpawns;
	}
	static ref array<vector> MedicalSpawns;

	static array<vector> GetMedicalSpawns()
	{
		if (!MedicalSpawns)
		{
			MedicalSpawns = new array<vector>();
			MedicalSpawns.Insert("0.336 0.808 -2.422");
			MedicalSpawns.Insert("0.21 0.664 -3.143");
			MedicalSpawns.Insert("-1.816 0.23 -3.052");
		}

		return MedicalSpawns;
	}
	static void Spawn(IEntity house, SpawnedHouseLoot data)
	{
		if (!house || !data)
			return;
		LootSpawner.SpawnWeightedFromArray(house, data, GetBedSpawns(), LootTables.GetE1I03BedLoot(), 0.5, "BED", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetKitchenSpawns(), LootTables.GetE1I03KitchenItems(), 0.5, "KITCHEN", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetWeaponSpawns(), LootTables.GetE1I03WeaponItems(), 0.1, "WEAPON", "0 0 0", 0.02);
		LootSpawner.SpawnWeightedFromArray(house, data, GetMedicalSpawns(), LootTables.GetE1I03MedicalItems(), 0.35, "MEDICAL", "0 0 0", 0.01);
	}
}
