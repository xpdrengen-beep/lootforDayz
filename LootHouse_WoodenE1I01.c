class LootHouse_WoodenE1I01
{
	static string PREFAB = "{3B877DB7AE5EA3BC}PrefabLibrary/DefaultLibrary/Structures/Houses/House_Wooden_E_1I01/House_Wooden_E_1I01.et";

	static ref array<vector> BedSpawns = {
		"3.362 1.658 2.011",
		"3.662 1.864 1.201"
	};

	static ref array<vector> KitchenSpawns = {
		"-0.952 2.062 -2.256",
		"-0.062 2.062 -2.055",
		"-2.508 2.085 -0.768",
		"-3.281 2.182 -0.501",
		"-3.968 2.181 -0.636"
	};

	static ref array<vector> WeaponSpawns = {
		"1.463 2.173 -2.464"
	};

	static ref array<vector> MedicalSpawns = {
		"-3.705 2.304 2.704",
		"-4.855 2.02 2.186",
		"-4.587 1.173 0.676"
	};

	static void Spawn(IEntity house, SpawnedHouseLoot data)
	{
		if (!house || !data)
			return;

		LootSpawner.SpawnWeightedFromArray(house, data, BedSpawns, LootTables.E1I01BedLoot, 0.5, "BED", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, KitchenSpawns, LootTables.E1I01KitchenItems, 0.5, "KITCHEN", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, WeaponSpawns, LootTables.E1I01WeaponItems, 0.1, "WEAPON", "90 0 90", 0.02);
		LootSpawner.SpawnWeightedFromArray(house, data, MedicalSpawns, LootTables.E1I01MedicalItems, 0.35, "MEDICAL", "0 0 0", 0.01);
	}
}