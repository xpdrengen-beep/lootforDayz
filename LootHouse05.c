class LootHouse05
{
	static string PREFAB = "{B98FAA85F278D4C4}Prefabs/Structures/Houses/Village/Single Floor Buildings/House 05.et";
	static ref array<vector> BedSpawns;

	static array<vector> GetBedSpawns()
	{
		if (!BedSpawns)
		{
			BedSpawns = new array<vector>();
			BedSpawns.Insert("-4.138 1.075 -2.499");
			BedSpawns.Insert("-2.516 1.071 -2.526");
			BedSpawns.Insert("-2.479 1.071 -1.275");
			BedSpawns.Insert("-4.129 1.064 -1.278");
		}

		return BedSpawns;
	}
	static ref array<vector> KitchenSpawns;

	static array<vector> GetKitchenSpawns()
	{
		if (!KitchenSpawns)
		{
			KitchenSpawns = new array<vector>();
			KitchenSpawns.Insert("0.257 1.476 2.456");
			KitchenSpawns.Insert("-0.702 1.476 1.844");
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
			WeaponSpawns.Insert("-4.297 0.981 -0.266");
			WeaponSpawns.Insert("-4.269 0.981 -3.373");
			WeaponSpawns.Insert("3.332 1.123 4.421");
		}

		return WeaponSpawns;
	}
	static ref array<vector> MedicalSpawns;

	static array<vector> GetMedicalSpawns()
	{
		if (!MedicalSpawns)
		{
			MedicalSpawns = new array<vector>();
			MedicalSpawns.Insert("4.909 1.131 -2.384");
			MedicalSpawns.Insert("5.03 1.582 -3.827");
			MedicalSpawns.Insert("3.057 1.575 -1.949");
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
