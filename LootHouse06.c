class LootHouse06
{
	static string PREFAB = "{66D1C47184C87135}Prefabs/Structures/Houses/Village/Single Floor Buildings/House 06.et";

	static ref array<vector> BedSpawns = {
		"-2.933 0.951 3.232",
		"-5.922 0.456 -0.933"
	};

	static ref array<vector> KitchenSpawns = {
		"2.564 1.376 0.99",
		"3.316 1.356 3.081"
	};

	static ref array<vector> WeaponSpawns = {
		"2.519 0.953 2.448"
	};

	static ref array<vector> MedicalSpawns = {
		"-2.802 1.013 4.744",
		"3.326 1.551 4.126"
	};

	static void Spawn(IEntity house, SpawnedHouseLoot data)
	{
		if (!house || !data)
			return;

		LootSpawner.SpawnWeightedFromArray(house, data, BedSpawns, LootTables.h06BedLoot, 0.5, "BED", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, KitchenSpawns, LootTables.h06KitchenItems, 0.5, "KITCHEN", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, WeaponSpawns, LootTables.h06WeaponItems, 0.1, "WEAPON", "0 0 0", 0.02);
		LootSpawner.SpawnWeightedFromArray(house, data, MedicalSpawns, LootTables.h06MedicalItems, 0.35, "MEDICAL", "0 0 0", 0.01);
	}
}
