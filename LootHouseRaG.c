class LootHouseRaG
{
	static string PREFAB = "{A809E681B08C2DA3}Prefabs/Structures/Houses/Village/Single Floor Buildings/House A Red and Green.et";

	static ref array<vector> BedSpawns = {
		"-4.133 0.534 2.307",
		"-3.095 0.953 -2.369",
		"4.149 0.552 -2.232"
	};

	static ref array<vector> KitchenSpawns = {
		"1.86 0.849 0.373",
		"-0.598 0.957 1.368"
	};

	static ref array<vector> KitchenSpawnsRotated = {
		"1.746 0.847 1.463"
	};

	static ref array<vector> WeaponSpawns = {
		"-3.281 0.783 2.663"
	};

	static ref array<vector> MedicalSpawns = {
		"-3.015 0.54 -1.751",
		"3.185 0.789 -2.543",
		"0.932 0.521 1.313"
	};

	static void Spawn(IEntity house, SpawnedHouseLoot data)
	{
		if (!house || !data)
			return;

		LootSpawner.SpawnWeightedFromArray(house, data, BedSpawns, LootTables.hRaGBedLoot, 0.5, "BED", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, KitchenSpawns, LootTables.hRaGKitchenItems, 0.5, "KITCHEN", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, KitchenSpawnsRotated, LootTables.hRaGKitchenItems, 0.5, "KITCHEN", "0 -3.067 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, WeaponSpawns, LootTables.hRaGWeaponItems, 0.1, "WEAPON", "90 0 90", 0.02);
		LootSpawner.SpawnWeightedFromArray(house, data, MedicalSpawns, LootTables.hRaGMedicalItems, 0.35, "MEDICAL", "0 0 0", 0.01);
	}
}
