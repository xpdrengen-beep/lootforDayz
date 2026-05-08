class LootHouse02
{
	static string PREFAB = "{37B1D5A94D60772C}Prefabs/Structures/Houses/Village/Single Floor Buildings/House 02.et";
	static ref array<vector> BedSpawns;

	static array<vector> GetBedSpawns()
	{
		if (!BedSpawns)
		{
			BedSpawns = new array<vector>();
			BedSpawns.Insert("-0.328 0.854 -7.168");
			BedSpawns.Insert("-0.328 0.854 -5.622");
			BedSpawns.Insert("0.807 0.854 -5.622");
			BedSpawns.Insert("0.807 0.854 -7.163");
		}

		return BedSpawns;
	}
	static ref array<vector> KitchenSpawns;

	static array<vector> GetKitchenSpawns()
	{
		if (!KitchenSpawns)
		{
			KitchenSpawns = new array<vector>();
			KitchenSpawns.Insert("-2.224 1.253 3.617");
			KitchenSpawns.Insert("-2.224 1.253 2.606");
			KitchenSpawns.Insert("-1.113 1.276 4.806");
			KitchenSpawns.Insert("-2.932 0.853 -6.286");
			KitchenSpawns.Insert("-2.932 0.853 -7.28");
			KitchenSpawns.Insert("-2.932 1.614 -7.28");
			KitchenSpawns.Insert("-2.932 1.614 -6.368");
		}

		return KitchenSpawns;
	}
	static ref array<vector> WeaponSpawns;

	static array<vector> GetWeaponSpawns()
	{
		if (!WeaponSpawns)
		{
			WeaponSpawns = new array<vector>();
			WeaponSpawns.Insert("-0.042 1.117 0.964");
			WeaponSpawns.Insert("0.86 1.117 0.964");
			WeaponSpawns.Insert("1.607 1.103 -7.393");
			WeaponSpawns.Insert("-1.2 1.103 -7.453");
			WeaponSpawns.Insert("0.552 0.844 -3.222");
		}

		return WeaponSpawns;
	}
	static void Spawn(IEntity house, SpawnedHouseLoot data)
	{
		if (!house || !data)
			return;
		LootSpawner.SpawnWeightedFromArray(house, data, GetBedSpawns(), LootTables.Geth03BedLoot(), 0.5, "BED", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetKitchenSpawns(), LootTables.Geth03KitchenItems(), 0.5, "KITCHEN", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetWeaponSpawns(), LootTables.Geth03WeaponItems(), 0.1, "WEAPON", "90 0 90", 0.02);
	}
}
