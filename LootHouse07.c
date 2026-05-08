class LootHouse07
{
	// TODO: Replace with the prefab/resource id for this house before enabling it in-game.
	static string PREFAB = "{834D8888882DE65E}Prefabs/Structures/Houses/Village/Single Floor Buildings/House 07.et";
	static ref array<vector> BedSpawns;

	static array<vector> GetBedSpawns()
	{
		if (!BedSpawns)
		{
			BedSpawns = new array<vector>();
			BedSpawns.Insert("-3.758 0.98 2.175");
			BedSpawns.Insert("-3.852 0.98 0.684");
			BedSpawns.Insert("-3.874 1.497 -0.727");
		}

		return BedSpawns;
	}
	static ref array<vector> KitchenSpawns;

	static array<vector> GetKitchenSpawns()
	{
		if (!KitchenSpawns)
		{
			KitchenSpawns = new array<vector>();
			KitchenSpawns.Insert("3.2 1.512 -1.368");
			KitchenSpawns.Insert("3.251 1.52 0.945");
			KitchenSpawns.Insert("3.311 1.492 1.431");
		}

		return KitchenSpawns;
	}
	static ref array<vector> WeaponSpawns;

	static array<vector> GetWeaponSpawns()
	{
		if (!WeaponSpawns)
		{
			WeaponSpawns = new array<vector>();
			WeaponSpawns.Insert("0.891 1.047 2.529");
		}

		return WeaponSpawns;
	}
	static ref array<vector> MedicalSpawns;

	static array<vector> GetMedicalSpawns()
	{
		if (!MedicalSpawns)
		{
			MedicalSpawns = new array<vector>();
			MedicalSpawns.Insert("-1.222 1.408 -1.279");
			MedicalSpawns.Insert("-0.523 1.496 -1.481");
			MedicalSpawns.Insert("0.174 1.496 -1.483");
		}

		return MedicalSpawns;
	}
	static void Spawn(IEntity house, SpawnedHouseLoot data)
	{
		if (!house || !data)
			return;
		LootSpawner.SpawnWeightedFromArray(house, data, GetBedSpawns(), LootTables.Geth07BedLoot(), 0.5, "BED", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetKitchenSpawns(), LootTables.Geth07KitchenItems(), 0.5, "KITCHEN", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetWeaponSpawns(), LootTables.Geth07WeaponItems(), 0.1, "WEAPON", "90 0 90", 0.02);
		LootSpawner.SpawnWeightedFromArray(house, data, GetMedicalSpawns(), LootTables.Geth07MedicalItems(), 0.35, "MEDICAL", "0 0 0", 0.01);
	}
}
