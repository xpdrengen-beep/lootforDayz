class LootHouse08
{
	static string PREFAB = "{1CB98E016E11635B}Prefabs/Structures/Houses/Village/Single Floor Buildings/House 08.et";
	static ref array<vector> BedSpawns;

	static array<vector> GetBedSpawns()
	{
		if (!BedSpawns)
		{
			BedSpawns = new array<vector>();
			BedSpawns.Insert("-5.197 0.715 0.574");
			BedSpawns.Insert("-5.093 0.715 -0.906");
			BedSpawns.Insert("-4.021 0.725 -3.624");
			BedSpawns.Insert("-5.496 0.721 -3.323");
			BedSpawns.Insert("-5.013 4.348 0.957");
			BedSpawns.Insert("-5.551 4.348 2.651");
		}

		return BedSpawns;
	}
	static ref array<vector> KitchenSpawns;

	static array<vector> GetKitchenSpawns()
	{
		if (!KitchenSpawns)
		{
			KitchenSpawns = new array<vector>();
			KitchenSpawns.Insert("2.699 1.133 3.507");
			KitchenSpawns.Insert("1.75 1.133 3.113");
			KitchenSpawns.Insert("-0.882 1.145 1.34");
		}

		return KitchenSpawns;
	}
	static ref array<vector> WeaponSpawns;

	static array<vector> GetWeaponSpawns()
	{
		if (!WeaponSpawns)
		{
			WeaponSpawns = new array<vector>();
			WeaponSpawns.Insert("-5.689 0.97 -2.633");
			WeaponSpawns.Insert("-2.29 4.325 1.556");
			WeaponSpawns.Insert("2.323 3.969 2.514");
		}

		return WeaponSpawns;
	}
	static ref array<vector> MedicalSpawns;

	static array<vector> GetMedicalSpawns()
	{
		if (!MedicalSpawns)
		{
			MedicalSpawns = new array<vector>();
			MedicalSpawns.Insert("-2.802 1.013 4.744");
			MedicalSpawns.Insert("-4.477 4.589 2.54");
			MedicalSpawns.Insert("3.056 4.34 2.52");
			MedicalSpawns.Insert("2.349 4.347 2.583");
			MedicalSpawns.Insert("4.738 4.397 0.675");
		}

		return MedicalSpawns;
	}
	static void Spawn(IEntity house, SpawnedHouseLoot data)
	{
		if (!house || !data)
			return;
		LootSpawner.SpawnWeightedFromArray(house, data, GetBedSpawns(), LootTables.Geth08BedLoot(), 0.5, "BED", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetKitchenSpawns(), LootTables.Geth08KitchenItems(), 0.5, "KITCHEN", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetWeaponSpawns(), LootTables.Geth08WeaponItems(), 0.1, "WEAPON", "0 0 0", 0.02);
		LootSpawner.SpawnWeightedFromArray(house, data, GetMedicalSpawns(), LootTables.Geth08MedicalItems(), 0.35, "MEDICAL", "0 0 0", 0.01);
	}
}
