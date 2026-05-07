class LootHouse_WoodenE1I03
{
	static string PREFAB = "{B24F05AE1E7FBBFA}PrefabLibrary/Structures/Houses/House_Wooden_E_1I03.et";

	static ref array<vector> BedSpawns = {
		"-0.266 0.622 6.611",
		"3.458 0.593 -2.756",
		"4.865 0.604 -3.915"
	};

	static ref array<vector> KitchenSpawns = {
		"-0.103 1.004 5.402",
		"2.513 0.928 2.93",
		"4.87 1.109 5.313",
		"5.234 0.618 4.35"
	};

	static ref array<vector> WeaponSpawns = {
		"2.481 0.623 2.073",
		"7.773 0.623 1.313"
	};

	static ref array<vector> MedicalSpawns = {
		"0.336 0.808 -2.422",
		"0.21 0.664 -3.143",
		"-1.816 0.23 -3.052"
	};

	static void Spawn(IEntity house, SpawnedHouseLoot data)
	{
		if (!house || !data)
			return;

		LootSpawner.SpawnWeightedFromArray(house, data, BedSpawns, LootTables.E1I03BedLoot, 0.5, "BED", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, KitchenSpawns, LootTables.E1I03KitchenItems, 0.5, "KITCHEN", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, WeaponSpawns, LootTables.E1I03WeaponItems, 0.1, "WEAPON", "0 0 0", 0.02);
		LootSpawner.SpawnWeightedFromArray(house, data, MedicalSpawns, LootTables.E1I03MedicalItems, 0.35, "MEDICAL", "0 0 0", 0.01);
	}
}
