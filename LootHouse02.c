class LootHouse02
{
	static string PREFAB = "{37B1D5A94D60772C}Prefabs/Structures/Houses/Village/Single Floor Buildings/House 02.et";

	static ref array<vector> BedSpawns = {
		"-0.328 0.854 -7.168",
		"-0.328 0.854 -5.622",
		"0.807 0.854 -5.622",
		"0.807 0.854 -7.163"
	};

	static ref array<vector> KitchenSpawns = {
		"-2.224 1.253 3.617",
		"-2.224 1.253 2.606",
		"-1.113 1.276 4.806",
		"-2.932 0.853 -6.286",
		"-2.932 0.853 -7.28",
		"-2.932 1.614 -7.28",
		"-2.932 1.614 -6.368"
	};

	static ref array<vector> WeaponSpawns = {
		"-0.042 1.117 0.964",
		"0.86 1.117 0.964",
		"1.607 1.103 -7.393",
		"-1.2 1.103 -7.453",
		"0.552 0.844 -3.222"
	};

	static void Spawn(IEntity house, SpawnedHouseLoot data)
	{
		if (!house || !data)
			return;

		LootSpawner.SpawnWeightedFromArray(house, data, BedSpawns, LootTables.h03BedLoot, 0.5, "BED", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, KitchenSpawns, LootTables.h03KitchenItems, 0.5, "KITCHEN", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, WeaponSpawns, LootTables.h03WeaponItems, 0.1, "WEAPON", "90 0 90", 0.02);
	}
}