class LootHouse07
{
	// TODO: Replace with the prefab/resource id for this house before enabling it in-game.
	static string PREFAB = "{834D8888882DE65E}Prefabs/Structures/Houses/Village/Single Floor Buildings/House 07.et";

	static ref array<vector> BedSpawns = {
		"-3.758 0.98 2.175",
		"-3.852 0.98 0.684",
		"-3.874 1.497 -0.727"
	};

	static ref array<vector> KitchenSpawns = {
		"3.2 1.512 -1.368",
		"3.251 1.52 0.945",
		"3.311 1.492 1.431"
	};

	static ref array<vector> WeaponSpawns = {
		"0.891 1.047 2.529"
	};

	static ref array<vector> MedicalSpawns = {
		"-1.222 1.408 -1.279",
		"-0.523 1.496 -1.481",
		"0.174 1.496 -1.483"
	};

	static void Spawn(IEntity house, SpawnedHouseLoot data)
	{
		if (!house || !data)
			return;

		LootSpawner.SpawnWeightedFromArray(house, data, BedSpawns, LootTables.h07BedLoot, 0.5, "BED", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, KitchenSpawns, LootTables.h07KitchenItems, 0.5, "KITCHEN", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, WeaponSpawns, LootTables.h07WeaponItems, 0.1, "WEAPON", "90 0 90", 0.02);
		LootSpawner.SpawnWeightedFromArray(house, data, MedicalSpawns, LootTables.h07MedicalItems, 0.35, "MEDICAL", "0 0 0", 0.01);
	}
}