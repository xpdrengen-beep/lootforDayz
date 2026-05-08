class LootHouse03
{
	static string PREFAB = "{D22D99504185E047}Prefabs/Structures/Houses/Village/Single Floor Buildings/House 03.et";
	static ref array<vector> BedSpawns;

	static array<vector> GetBedSpawns()
	{
		if (!BedSpawns)
		{
			BedSpawns = new array<vector>();
			BedSpawns.Insert("-2.23 0.599 -8.599");
			BedSpawns.Insert("1.537 0.594 -8.599");
			BedSpawns.Insert("-0.015 0.065 -8.599");
			BedSpawns.Insert("-2.59 0.555 1.194");
		}

		return BedSpawns;
	}
	static ref array<vector> KitchenSpawns;

	static array<vector> GetKitchenSpawns()
	{
		if (!KitchenSpawns)
		{
			KitchenSpawns = new array<vector>();
			KitchenSpawns.Insert("0.22 0.964 -2.463");
			KitchenSpawns.Insert("-0.383 1.069 -5.289");
			KitchenSpawns.Insert("-1.908 1.069 -5.128");
		}

		return KitchenSpawns;
	}
	static ref array<vector> WeaponSpawns;

	static array<vector> GetWeaponSpawns()
	{
		if (!WeaponSpawns)
		{
			WeaponSpawns = new array<vector>();
			WeaponSpawns.Insert("-1.259 0.954 -6.372");
			WeaponSpawns.Insert("-1.337 1.074 4.488");
		}

		return WeaponSpawns;
	}
	static ref array<vector> WeaponSpawnsRotated;

	static array<vector> GetWeaponSpawnsRotated()
	{
		if (!WeaponSpawnsRotated)
		{
			WeaponSpawnsRotated = new array<vector>();
			WeaponSpawnsRotated.Insert("2.913 0.64 4.178");
		}

		return WeaponSpawnsRotated;
	}
	static void Spawn(IEntity house, SpawnedHouseLoot data)
	{
		if (!house || !data)
			return;
		LootSpawner.SpawnWeightedFromArray(house, data, GetBedSpawns(), LootTables.Geth03BedLoot(), 0.5, "BED", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetKitchenSpawns(), LootTables.Geth03KitchenItems(), 0.5, "KITCHEN", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetWeaponSpawns(), LootTables.Geth03WeaponItems(), 0.1, "WEAPON", "90 0 90", 0.02);
		LootSpawner.SpawnWeightedFromArray(house, data, GetWeaponSpawnsRotated(), LootTables.Geth03WeaponItems(), 0.1, "WEAPON", "0 0 90", 0.01);
	}
}
