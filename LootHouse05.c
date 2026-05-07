class LootHouse05
{
	static string PREFAB = "{B98FAA85F278D4C4}Prefabs/Structures/Houses/Village/Single Floor Buildings/House 05.et";

	static ref array<vector> BedSpawns = {
		"-4.138 1.075 -2.499",
		"-2.516 1.071 -2.526",
		"-2.479 1.071 -1.275",
		"-4.129 1.064 -1.278"
	};

	static ref array<vector> KitchenSpawns = {
		"0.257 1.476 2.456",
		"-0.702 1.476 1.844",
		"-2.278 1.5 3.033"
	};

	static ref array<vector> WeaponSpawns = {
		"-4.297 0.981 -0.266",
		"-4.269 0.981 -3.373",
		"3.332 1.123 4.421"
	};

	static ref array<vector> MedicalSpawns = {
		"4.909 1.131 -2.384",
		"5.03 1.582 -3.827",
		"3.057 1.575 -1.949"
	};

	static void Spawn(IEntity house, SpawnedHouseLoot data)
	{
		if (!house || !data)
			return;

		LootSpawner.SpawnWeightedFromArray(house, data, BedSpawns, LootTables.h05BedLoot, 0.5, "BED", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, KitchenSpawns, LootTables.h05KitchenItems, 0.5, "KITCHEN", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, WeaponSpawns, LootTables.h05WeaponItems, 0.1, "WEAPON", "90 0 90", 0.02);
		LootSpawner.SpawnWeightedFromArray(house, data, MedicalSpawns, LootTables.h05MedicalItems, 0.35, "MEDICAL", "0 0 0", 0.01);
	}
}