class LootHouse03
{
	static string PREFAB = "{D22D99504185E047}Prefabs/Structures/Houses/Village/Single Floor Buildings/House 03.et";

	static ref array<vector> BedSpawns = {
		"-2.23 0.599 -8.599",
		"1.537 0.594 -8.599",
		"-0.015 0.065 -8.599",
		"-2.59 0.555 1.194"
	};

	static ref array<vector> KitchenSpawns = {
		"0.22 0.964 -2.463",
		"-0.383 1.069 -5.289",
		"-1.908 1.069 -5.128"
	};

	static ref array<vector> WeaponSpawns = {
		"-1.259 0.954 -6.372",
		"-1.337 1.074 4.488"
	};

	static ref array<vector> WeaponSpawnsRotated = {
		"2.913 0.64 4.178"
	};

	static void Spawn(IEntity house, SpawnedHouseLoot data)
	{
		if (!house || !data)
			return;

		LootSpawner.SpawnWeightedFromArray(house, data, BedSpawns, LootTables.h03BedLoot, 0.5, "BED", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, KitchenSpawns, LootTables.h03KitchenItems, 0.5, "KITCHEN", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, WeaponSpawns, LootTables.h03WeaponItems, 0.1, "WEAPON", "90 0 90", 0.02);
		LootSpawner.SpawnWeightedFromArray(house, data, WeaponSpawnsRotated, LootTables.h03WeaponItems, 0.1, "WEAPON", "0 0 90", 0.01);
	}
}