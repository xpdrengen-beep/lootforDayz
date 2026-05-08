class LootHouse_TownE2I02
{
	static string PREFAB = "{54F1C704EB440885}Prefabs/Structures/Houses/Town/House_Town_E_2I02/House_Town_E_2I02.et";

	static ref array<vector> BedSpawns = {
		"6.043 1.658 0.152",
		"1.92 0.753 4.756",
		"8.006 0.722 2.326",
		"7.588 0.782 5.061",
		"4.691 0.782 4.496",
		"-8.03 4.559 -1.081",
		"-6.68 4.565 -0.343",
		"4.06 4.528 2.864",
		"5.712 4.528 4.111"
	};

	static ref array<vector> KitchenSpawns = {
		"4.499 1.27 -3.013",
		"4.495 1.28 -3.552",
		"4.488 1.28 -4.52",
		"6.879 1.176 -3.953",
		"7.499 1.176 -2.96",
		"7.316 0.815 -5.078",
		"8.248 0.815 -3.666",
		"6.889 0.815 -1.998",
		"-6.453 1.159 -1.283",
		"-7.439 1.159 -1.319",
		"-8.323 0.676 -0.822",
		"-8.377 0.695 0.343",
		"7.115 4.967 -4.206",
		"7.73 4.967 -5.208",
		"8.307 5.084 -2.061",
		"8.353 5.084 -1.249",
		"4.207 4.677 3.973",
		"3.341 4.677 4.002"
	};

	static ref array<vector> WeaponSpawns = {
		"-1.077 5.062 -2.911",
		"0.159 1.189 2.828",
		"8.191 1.261 -0.463",
		"-8.357 4.968 4.648",
		"-8.349 5.064 2.001",
		"3.309 5.064 -1.211",
		"0.282 5.064 0.835",
		"5.833 8.318 -1.933",
		"4.5 7.496 4.494"
	};

	static ref array<vector> MedicalSpawns = {
		"-5.838 1.236 5.037",
		"0.309 0.829 -2.687",
		"0.212 0.333 -4.37",
		"3.241 1.274 -4.301",
		"0.031 4.912 -2.359",
		"0.084 4.775 -3.141",
		"3.303 5.063 -4.384"
	};

	// Placeholder for later tool loot support. No items are spawned from these points yet.
	static ref array<vector> ToolSpawns = {
		"-7.848 1.234 5.062",
		"-8.479 0.754 2.751",
		"-1.065 1.065 1.621",
		"-5.794 1.065 -2.361",
		"-8.377 1.659 -0.278",
		"-7.622 1.154 -1.355",
		"-6.444 1.154 -1.375",
		"-8.327 0.685 0.207",
		"-7.156 0.712 -1.362"
	};

	static void Spawn(IEntity house, SpawnedHouseLoot data)
	{
		if (!house || !data)
			return;

		LootSpawner.SpawnWeightedFromArray(house, data, BedSpawns, LootTables.TownE2I02BedLoot, 0.22, "BED", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, KitchenSpawns, LootTables.TownE2I02KitchenItems, 0.18, "KITCHEN", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, WeaponSpawns, LootTables.TownE2I02WeaponItems, 0.08, "WEAPON", "0 0 0", 0.02);
		LootSpawner.SpawnWeightedFromArray(house, data, MedicalSpawns, LootTables.TownE2I02MedicalItems, 0.18, "MEDICAL", "0 0 0", 0.01);
	}
}