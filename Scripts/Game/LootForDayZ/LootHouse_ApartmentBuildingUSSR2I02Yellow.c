class LootHouse_ApartmentBuildingUSSR2I02Yellow
{
	static string PREFAB = "{06257D07F436AD1C}Prefabs/Structures/Military/Houses/ApartmentBuilding_2I02/ApartmentBuilding_USSR_2I02_yellow.et";
	static ref array<vector> BedSpawns;

	static array<vector> GetBedSpawns()
	{
		if (!BedSpawns)
		{
			BedSpawns = new array<vector>();
			BedSpawns.Insert("4.259 1.478 -2.006");
			BedSpawns.Insert("2.972 1.478 -1.921");
			BedSpawns.Insert("7.359 1.644 -2.041");
			BedSpawns.Insert("8.735 1.597 -4.108");
			BedSpawns.Insert("10.207 1.597 -4.236");
			BedSpawns.Insert("10.216 1.597 -5.595");
			BedSpawns.Insert("9.345 1.597 -5.729");
			BedSpawns.Insert("9.362 1.597 -4.351");
			BedSpawns.Insert("5.998 1.478 4.543");
			BedSpawns.Insert("6 1.478 5.893");
			BedSpawns.Insert("7.353 1.582 5.766");
			BedSpawns.Insert("7.501 1.582 7.198");
			BedSpawns.Insert("9.959 1.582 5.674");
			BedSpawns.Insert("10.107 1.582 7.106");
			BedSpawns.Insert("10.012 1.655 2.142");
			BedSpawns.Insert("-2.671 1.484 -5.057");
			BedSpawns.Insert("-2.625 1.484 -5.075");
			BedSpawns.Insert("-2.726 1.484 -5.8");
			BedSpawns.Insert("-7.375 1.588 -5.697");
			BedSpawns.Insert("-7.366 1.588 -7.187");
			BedSpawns.Insert("-7.58 1.653 -2.027");
			BedSpawns.Insert("-2.694 1.484 4.655");
			BedSpawns.Insert("-2.647 1.484 5.95");
			BedSpawns.Insert("-10.013 1.583 5.774");
			BedSpawns.Insert("-9.923 1.583 7.075");
			BedSpawns.Insert("-7.372 1.583 6.383");
			BedSpawns.Insert("-7.374 1.583 7.14");
			BedSpawns.Insert("-2.834 4.994 5.018");
			BedSpawns.Insert("-2.963 4.994 3.841");
			BedSpawns.Insert("-8.67 4.994 2.01");
			BedSpawns.Insert("-7.729 4.994 2.1");
			BedSpawns.Insert("-10.344 4.994 3.948");
			BedSpawns.Insert("-9.972 5.006 5.577");
			BedSpawns.Insert("-9.766 5.006 6.772");
			BedSpawns.Insert("-10.083 4.994 -5.669");
			BedSpawns.Insert("-10.013 4.994 -6.877");
			BedSpawns.Insert("-7.307 4.994 -7.118");
			BedSpawns.Insert("-7.565 4.994 -5.525");
			BedSpawns.Insert("-4.384 4.877 -2.004");
			BedSpawns.Insert("-3.523 4.877 -2.019");
			BedSpawns.Insert("2.757 4.949 3.594");
			BedSpawns.Insert("2.766 4.949 5.231");
			BedSpawns.Insert("7.439 4.988 5.697");
			BedSpawns.Insert("7.435 4.988 7.078");
			BedSpawns.Insert("10.124 4.988 7.149");
			BedSpawns.Insert("9.785 4.988 5.641");
			BedSpawns.Insert("2.69 4.876 -3.943");
			BedSpawns.Insert("2.742 4.876 -5.221");
			BedSpawns.Insert("8.673 4.985 -2.043");
			BedSpawns.Insert("7.384 4.985 -1.935");
			BedSpawns.Insert("9.972 5.006 -5.669");
			BedSpawns.Insert("9.965 5.006 -7.067");
		}

		return BedSpawns;
	}
	static ref array<vector> KitchenSpawns;

	static array<vector> GetKitchenSpawns()
	{
		if (!KitchenSpawns)
		{
			KitchenSpawns = new array<vector>();
			KitchenSpawns.Insert("2.854 1.994 -3.913");
			KitchenSpawns.Insert("3.094 1.994 -4.295");
			KitchenSpawns.Insert("2.649 2.121 -6.437");
			KitchenSpawns.Insert("7.14 1.794 -7.199");
			KitchenSpawns.Insert("2.617 2.097 6.398");
			KitchenSpawns.Insert("2.747 2.001 5.141");
			KitchenSpawns.Insert("3.013 2.001 4.667");
			KitchenSpawns.Insert("-2.665 1.798 3.981");
			KitchenSpawns.Insert("-5.693 2.004 4.916");
			KitchenSpawns.Insert("-5.511 2.004 5.865");
			KitchenSpawns.Insert("-6.013 2.088 6.74");
			KitchenSpawns.Insert("-5.845 5.499 6.145");
			KitchenSpawns.Insert("-5.648 5.4 5.104");
			KitchenSpawns.Insert("-2.51 5.385 6.153");
			KitchenSpawns.Insert("-6.121 5.489 -7.134");
			KitchenSpawns.Insert("-5.646 5.403 -5.205");
			KitchenSpawns.Insert("-2.558 5.51 -6.033");
			KitchenSpawns.Insert("-2.646 5.205 -4.531");
			KitchenSpawns.Insert("9.011 5.492 2.004");
			KitchenSpawns.Insert("8.107 5.492 2.038");
			KitchenSpawns.Insert("5.663 5.395 4.621");
			KitchenSpawns.Insert("5.56 5.395 -5.071");
			KitchenSpawns.Insert("6.05 5.395 -6.054");
			KitchenSpawns.Insert("5.438 5.395 -6.036");
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
			WeaponSpawns.Insert("6.285 1.719 6.944");
			WeaponSpawns.Insert("8.33 1.999 1.973");
			WeaponSpawns.Insert("-10.142 5.242 4.951");
			WeaponSpawns.Insert("-10.232 5.484 -4.089");
			WeaponSpawns.Insert("2.434 5.044 -6.154");
			WeaponSpawns.Insert("10.153 5.407 -4.454");
			WeaponSpawns.Insert("8.13 8.679 1.254");
			WeaponSpawns.Insert("6.858 8.679 2.276");
			WeaponSpawns.Insert("2.664 8.784 -1.748");
		}

		return WeaponSpawns;
	}
	static ref array<vector> MedicalSpawns;

	static array<vector> GetMedicalSpawns()
	{
		if (!MedicalSpawns)
		{
			MedicalSpawns = new array<vector>();
			MedicalSpawns.Insert("10.087 1.661 -0.626");
			MedicalSpawns.Insert("7.532 1.839 0.884");
			MedicalSpawns.Insert("-3.524 1.813 -4.429");
			MedicalSpawns.Insert("-9.294 2 -1.94");
			MedicalSpawns.Insert("-10.164 2 -1.94");
			MedicalSpawns.Insert("-10.039 1.674 -0.509");
			MedicalSpawns.Insert("-10.591 1.674 0.687");
			MedicalSpawns.Insert("-9.297 4.998 -2.204");
			MedicalSpawns.Insert("-10.019 5.076 0.58");
			MedicalSpawns.Insert("10.07 5.066 -0.597");
			MedicalSpawns.Insert("10.611 5.066 0.63");
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
			ToolSpawns.Insert("0.984 1.105 -6.323");
			ToolSpawns.Insert("-0.719 1.105 -6.625");
			ToolSpawns.Insert("-1.33 2.052 -3.975");
			ToolSpawns.Insert("1.196 4.507 -4.52");
			ToolSpawns.Insert("-0.809 4.508 -7.129");
			ToolSpawns.Insert("-1.534 4.913 -5.639");
			ToolSpawns.Insert("-9.324 7.872 -1.074");
			ToolSpawns.Insert("-4.054 7.872 4.386");
			ToolSpawns.Insert("2.818 7.872 -1.984");
			ToolSpawns.Insert("6.282 7.872 -2.145");
			ToolSpawns.Insert("9.832 7.872 0.119");
			ToolSpawns.Insert("8.083 7.872 2.521");
			ToolSpawns.Insert("-0.973 8.783 3.882");
		}

		return ToolSpawns;
	}
	static void Spawn(IEntity house, SpawnedHouseLoot data)
	{
		if (!house || !data)
			return;
		LootSpawner.SpawnWeightedFromArray(house, data, GetBedSpawns(), LootTables.GetTownE2I02BedLoot(), 0.04, "BED", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetKitchenSpawns(), LootTables.GetTownE2I02KitchenItems(), 0.06, "KITCHEN", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetWeaponSpawns(), LootTables.GetTownE2I02WeaponItems(), 0.025, "WEAPON", "0 0 0", 0.02);
		LootSpawner.SpawnWeightedFromArray(house, data, GetMedicalSpawns(), LootTables.GetTownE2I02MedicalItems(), 0.04, "MEDICAL", "0 0 0", 0.01);
	}
}
