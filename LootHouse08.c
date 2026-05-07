class LootHouse08
{
	static string PREFAB = "{1CB98E016E11635B}Prefabs/Structures/Houses/Village/Single Floor Buildings/House 08.et";

	static ref array<vector> BedSpawns = {
		"-5.197 0.715 0.574",
		"-5.093 0.715 -0.906",
		"-4.021 0.725 -3.624",
		"-5.496 0.721 -3.323",
		"-5.013 4.348 0.957",
		"-5.551 4.348 2.651"
	};

	static ref array<vector> KitchenSpawns = {
		"2.699 1.133 3.507",
		"1.75 1.133 3.113",
		"-0.882 1.145 1.34"
	};

	static ref array<vector> WeaponSpawns = {
		"-5.689 0.97 -2.633",
		"-2.29 4.325 1.556",
		"2.323 3.969 2.514"
	};

	static ref array<vector> MedicalSpawns = {
		"-2.802 1.013 4.744",
		"-4.477 4.589 2.54",
		"3.056 4.34 2.52",
		"2.349 4.347 2.583",
		"4.738 4.397 0.675"
	};

	static void Spawn(IEntity house, SpawnedHouseLoot data)
	{
		if (!house || !data)
			return;

		LootSpawner.SpawnWeightedFromArray(house, data, BedSpawns, LootTables.h08BedLoot, 0.5, "BED", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, KitchenSpawns, LootTables.h08KitchenItems, 0.5, "KITCHEN", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, WeaponSpawns, LootTables.h08WeaponItems, 0.1, "WEAPON", "0 0 0", 0.02);
		LootSpawner.SpawnWeightedFromArray(house, data, MedicalSpawns, LootTables.h08MedicalItems, 0.35, "MEDICAL", "0 0 0", 0.01);
	}
}
