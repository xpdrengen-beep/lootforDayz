class LootHouse05_02
{
	static string PREFAB = "{AD53607D6A80B571}Prefabs/Structures/Houses/Village/Single Floor Buildings/House 05_02.et";
	static ref array<vector> BedSpawns;

	static array<vector> GetBedSpawns()
	{
		if (!BedSpawns)
		{
			BedSpawns = new array<vector>();
			BedSpawns.Insert("-2.696 1.332 -0.139");
			BedSpawns.Insert("-2.516 1.071 -2.526");
			BedSpawns.Insert("1.831 1.088 -4.005");
			BedSpawns.Insert("-3.992 1.089 -1.578");
		}

		return BedSpawns;
	}
	static ref array<vector> KitchenSpawns;

	static array<vector> GetKitchenSpawns()
	{
		if (!KitchenSpawns)
		{
			KitchenSpawns = new array<vector>();
			KitchenSpawns.Insert("-0.153 1.476 1.6");
			KitchenSpawns.Insert("-0.77 1.476 0.73");
			KitchenSpawns.Insert("-2.278 1.5 3.033");
		}

		return KitchenSpawns;
	}
	static ref array<vector> WeaponSpawns;

	static array<vector> GetWeaponSpawns()
	{
		if (!WeaponSpawns)
		{
			WeaponSpawns = new array<vector>();
			WeaponSpawns.Insert("-4.237 0.981 -0.266");
			WeaponSpawns.Insert("1.96 0.981 -1.794");
			WeaponSpawns.Insert("3.816 1.33 4.262");
		}

		return WeaponSpawns;
	}
	static ref array<vector> MedicalSpawns;

	static array<vector> GetMedicalSpawns()
	{
		if (!MedicalSpawns)
		{
			MedicalSpawns = new array<vector>();
			MedicalSpawns.Insert("4.802 1.131 -2.829");
			MedicalSpawns.Insert("2.647 1.452 -2.597");
			MedicalSpawns.Insert("-2.278 1.586 3.363");
		}

		return MedicalSpawns;
	}
	static void Spawn(IEntity house, SpawnedHouseLoot data)
	{
		if (!house || !data)
			return;
		LootSpawner.SpawnWeightedFromArray(house, data, GetBedSpawns(), LootTables.Geth05BedLoot(), 0.5, "BED", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetKitchenSpawns(), LootTables.Geth05KitchenItems(), 0.5, "KITCHEN", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetWeaponSpawns(), LootTables.Geth05WeaponItems(), 0.1, "WEAPON", "90 0 90", 0.02);
		LootSpawner.SpawnWeightedFromArray(house, data, GetMedicalSpawns(), LootTables.Geth05MedicalItems(), 0.35, "MEDICAL", "0 0 0", 0.01);
	}
}
