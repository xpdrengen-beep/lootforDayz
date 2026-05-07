class LootHouse05_02
{
	static string PREFAB = "{AD53607D6A80B571}Prefabs/Structures/Houses/Village/Single Floor Buildings/House 05_02.et";

	static ref array<vector> BedSpawns = {
		"-2.696 1.332 -0.139",
		"-2.516 1.071 -2.526",
		"1.831 1.088 -4.005",
		"-3.992 1.089 -1.578"
	};

	static ref array<vector> KitchenSpawns = {
		"-0.153 1.476 1.6",
		"-0.77 1.476 0.73",
		"-2.278 1.5 3.033"
	};

	static ref array<vector> WeaponSpawns = {
		"-4.237 0.981 -0.266",
		"1.96 0.981 -1.794",
		"3.816 1.33 4.262"
	};

	static ref array<vector> MedicalSpawns = {
		"4.802 1.131 -2.829",
		"2.647 1.452 -2.597",
		"-2.278 1.586 3.363"
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
