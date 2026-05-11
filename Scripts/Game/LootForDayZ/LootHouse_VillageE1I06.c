class LootHouse_VillageE1I06
{
	static string PREFAB = "{7BE9DE15EE9823C2}PrefabLibrary/DefaultLibrary/Structures/Houses/House_Village_E_1I06.et";
	static ref array<vector> BedSpawns;

	static array<vector> GetBedSpawns()
	{
		if (!BedSpawns)
		{
			BedSpawns = new array<vector>();
			BedSpawns.Insert("2.352 0.457 -2.201");
			BedSpawns.Insert("-7.352 0.517 -2.86");
			BedSpawns.Insert("-8.265 4.125 3.208");
			BedSpawns.Insert("-6.988 4.125 3.068");
			BedSpawns.Insert("-4.052 4.125 3.666");
			BedSpawns.Insert("-5.592 4.125 3.144");
			BedSpawns.Insert("2.714 4.184 -4.338");
			BedSpawns.Insert("1.032 4.184 -4.352");
			BedSpawns.Insert("4.226 4.107 2.258");
			BedSpawns.Insert("5.611 4.113 2.242");
			BedSpawns.Insert("5.542 4.11 3.705");
			BedSpawns.Insert("4.275 4.108 3.691");
		}

		return BedSpawns;
	}
	static ref array<vector> KitchenSpawns;

	static array<vector> GetKitchenSpawns()
	{
		if (!KitchenSpawns)
		{
			KitchenSpawns = new array<vector>();
			KitchenSpawns.Insert("2.284 0.93 0.808");
			KitchenSpawns.Insert("1.015 0.891 -1.236");
			KitchenSpawns.Insert("1.036 0.891 -0.128");
			KitchenSpawns.Insert("1.036 1.388 -0.128");
			KitchenSpawns.Insert("1.075 1.371 -0.906");
			KitchenSpawns.Insert("4.107 1.543 -1.69");
			KitchenSpawns.Insert("3.186 0.704 -1.886");
			KitchenSpawns.Insert("-7.936 1.008 -2.713");
			KitchenSpawns.Insert("-8.341 1.008 -3.38");
			KitchenSpawns.Insert("-5.047 0.891 1.304");
			KitchenSpawns.Insert("-7.762 0.901 3.352");
			KitchenSpawns.Insert("4.921 4.628 1.473");
			KitchenSpawns.Insert("5.639 4.628 1.11");
		}

		return KitchenSpawns;
	}
	static ref array<vector> WeaponSpawns;

	static array<vector> GetWeaponSpawns()
	{
		if (!WeaponSpawns)
		{
			WeaponSpawns = new array<vector>();
			WeaponSpawns.Insert("-2.25 0.514 1.096");
			WeaponSpawns.Insert("-1.037 0.501 -2.863");
			WeaponSpawns.Insert("5.072 0.92 -4.633");
			WeaponSpawns.Insert("-0.548 4.618 -4.654");
			WeaponSpawns.Insert("-6.228 4.52 0.04");
			WeaponSpawns.Insert("1.908 4.305 -4.469");
		}

		return WeaponSpawns;
	}
	static ref array<vector> MedicalSpawns;

	static array<vector> GetMedicalSpawns()
	{
		if (!MedicalSpawns)
		{
			MedicalSpawns = new array<vector>();
			MedicalSpawns.Insert("-6.899 4.161 -0.878");
			MedicalSpawns.Insert("-6.074 4.621 -4.689");
			MedicalSpawns.Insert("-7.066 4.621 -4.65");
			MedicalSpawns.Insert("-5.299 4.197 -4.557");
			MedicalSpawns.Insert("-8.673 3.745 -4.521");
			MedicalSpawns.Insert("4.638 4.756 -4.476");
		}

		return MedicalSpawns;
	}
	// Tool spawn points are kept for later tool loot support. No items are spawned from these points yet.
	static ref array<vector> ToolSpawns;

	static array<vector> GetToolSpawns()
	{
		if (!ToolSpawns)
		{
			ToolSpawns = new array<vector>();
			ToolSpawns.Insert("4.23 1.016 -0.641");
			ToolSpawns.Insert("5.573 0.819 0.801");
		}

		return ToolSpawns;
	}
	static void Spawn(IEntity house, SpawnedHouseLoot data)
	{
		if (!house || !data)
			return;
		LootSpawner.SpawnWeightedFromArray(house, data, GetBedSpawns(), LootTables.GetTownE2I02BedLoot(), 0.14, "BED", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetKitchenSpawns(), LootTables.GetTownE2I02KitchenItems(), 0.12, "KITCHEN", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetWeaponSpawns(), LootTables.GetTownE2I02WeaponItems(), 0.05, "WEAPON", "0 0 0", 0.02);
		LootSpawner.SpawnWeightedFromArray(house, data, GetMedicalSpawns(), LootTables.GetTownE2I02MedicalItems(), 0.10, "MEDICAL", "0 0 0", 0.01);
	}
}
