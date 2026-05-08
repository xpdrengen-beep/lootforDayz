class LootHouseRaG
{
	static string PREFAB = "{A809E681B08C2DA3}Prefabs/Structures/Houses/Village/Single Floor Buildings/House A Red and Green.et";
	static ref array<vector> BedSpawns;

	static array<vector> GetBedSpawns()
	{
		if (!BedSpawns)
		{
			BedSpawns = new array<vector>();
			BedSpawns.Insert("-4.133 0.534 2.307");
			BedSpawns.Insert("-3.095 0.953 -2.369");
			BedSpawns.Insert("4.149 0.552 -2.232");
		}

		return BedSpawns;
	}
	static ref array<vector> KitchenSpawns;

	static array<vector> GetKitchenSpawns()
	{
		if (!KitchenSpawns)
		{
			KitchenSpawns = new array<vector>();
			KitchenSpawns.Insert("1.86 0.849 0.373");
			KitchenSpawns.Insert("-0.598 0.957 1.368");
			KitchenSpawns.Insert("1.746 0.847 1.463");
		}

		return KitchenSpawns;
	}
	static ref array<vector> WeaponSpawns;

	static array<vector> GetWeaponSpawns()
	{
		if (!WeaponSpawns)
		{
			WeaponSpawns = new array<vector>();
			WeaponSpawns.Insert("-3.281 0.783 2.663");
		}

		return WeaponSpawns;
	}
	static ref array<vector> MedicalSpawns;

	static array<vector> GetMedicalSpawns()
	{
		if (!MedicalSpawns)
		{
			MedicalSpawns = new array<vector>();
			MedicalSpawns.Insert("-3.015 0.54 -1.751");
			MedicalSpawns.Insert("3.185 0.789 -2.543");
			MedicalSpawns.Insert("0.932 0.521 1.313");
		}

		return MedicalSpawns;
	}
	static void Spawn(IEntity house, SpawnedHouseLoot data)
	{
		if (!house || !data)
			return;
		LootSpawner.SpawnWeightedFromArray(house, data, GetBedSpawns(), LootTables.GethRaGBedLoot(), 0.5, "BED", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetKitchenSpawns(), LootTables.GethRaGKitchenItems(), 0.5, "KITCHEN", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetWeaponSpawns(), LootTables.GethRaGWeaponItems(), 0.1, "WEAPON", "90 0 90", 0.02);
		LootSpawner.SpawnWeightedFromArray(house, data, GetMedicalSpawns(), LootTables.GethRaGMedicalItems(), 0.35, "MEDICAL", "0 0 0", 0.01);
	}
}
