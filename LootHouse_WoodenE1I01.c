class LootHouse_WoodenE1I01
{
	static string PREFAB = "{3B877DB7AE5EA3BC}PrefabLibrary/DefaultLibrary/Structures/Houses/House_Wooden_E_1I01/House_Wooden_E_1I01.et";

	static ref array<vector> BedSpawns = {
		"3.316 1.67 2.105",
		"3.571 1.863 1.104",
		"1.304 2.167 -2.352"
	};

	static ref array<vector> KitchenSpawns = {
		"-4.112 2.191 -0.482",
		"-2.515 2.085 -0.815",
		"-0.95 2.06 -2.177",
		"-0.032 2.06 -2.44"
	};

	static ref array<vector> WeaponSpawns = {
		"0.814 2.164 1.985"
	};

	static ref array<vector> MedicalSpawns = {
		"-4.804 1.171 0.439",
		"-4.845 2.066 2.178",
		"-0.032 2.06 -2.44"
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