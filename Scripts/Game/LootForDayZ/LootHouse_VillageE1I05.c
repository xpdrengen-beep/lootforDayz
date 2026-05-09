class LootHouse_VillageE1I05
{
	static string PREFAB_S = "{143F44A0916B2845}PrefabLibrary/DefaultLibrary/Structures/Houses/House_Village_E_1I05s.et";
	static string PREFAB_T = "{A7259960AB98A3A0}PrefabLibrary/DefaultLibrary/Structures/Houses/House_Village_E_1I05t.et";
	static ref array<vector> BedSpawns;

	static array<vector> GetBedSpawns()
	{
		if (!BedSpawns)
		{
			BedSpawns = new array<vector>();
			BedSpawns.Insert("5.799 1.001 3.805");
			BedSpawns.Insert("4.257 1.001 3.721");
			BedSpawns.Insert("5.259 1.075 0.84");
			BedSpawns.Insert("11.583 0.982 3.016");
			BedSpawns.Insert("11.646 0.982 1.444");
			BedSpawns.Insert("-1.368 1.009 1.704");
			BedSpawns.Insert("-2.811 1.009 0.722");
			BedSpawns.Insert("-2.965 1.009 2.341");
			BedSpawns.Insert("-1.437 1.009 0.663");
			BedSpawns.Insert("0.407 1.08 -3.736");
			BedSpawns.Insert("1.897 1.08 -3.708");
			BedSpawns.Insert("8.129 1.064 -1.523");
			BedSpawns.Insert("9.65 1.064 -3.862");
		}

		return BedSpawns;
	}
	static ref array<vector> KitchenSpawns;

	static array<vector> GetKitchenSpawns()
	{
		if (!KitchenSpawns)
		{
			KitchenSpawns = new array<vector>();
			KitchenSpawns.Insert("9.369 1.411 -1.958");
			KitchenSpawns.Insert("9.492 1.411 -2.773");
			KitchenSpawns.Insert("8.753 1.411 -2.521");
			KitchenSpawns.Insert("12.032 1.525 -2.271");
			KitchenSpawns.Insert("12.077 1.525 -3.325");
			KitchenSpawns.Insert("12.023 1.527 -0.825");
			KitchenSpawns.Insert("10.433 1.115 1.468");
			KitchenSpawns.Insert("10.734 1.115 2.784");
			KitchenSpawns.Insert("0.123 1.383 0.828");
			KitchenSpawns.Insert("-0.722 1.383 0.812");
			KitchenSpawns.Insert("9.212 1.629 0.104");
			KitchenSpawns.Insert("9.212 0.919 0.104");
		}

		return KitchenSpawns;
	}
	static ref array<vector> WeaponSpawns;

	static array<vector> GetWeaponSpawns()
	{
		if (!WeaponSpawns)
		{
			WeaponSpawns = new array<vector>();
			WeaponSpawns.Insert("-1.492 1.504 -4.072");
			WeaponSpawns.Insert("3.546 1.503 0.772");
			WeaponSpawns.Insert("-4.431 1.06 -4.377");
			WeaponSpawns.Insert("-4.547 1.413 2.939");
		}

		return WeaponSpawns;
	}
	static ref array<vector> MedicalSpawns;

	static array<vector> GetMedicalSpawns()
	{
		if (!MedicalSpawns)
		{
			MedicalSpawns = new array<vector>();
			MedicalSpawns.Insert("6.051 1.507 -4.083");
			MedicalSpawns.Insert("4.307 1.464 -3.224");
			MedicalSpawns.Insert("6.682 1.063 -1.565");
			MedicalSpawns.Insert("6.865 0.573 -3.033");
			MedicalSpawns.Insert("6.923 0.573 -3.885");
			MedicalSpawns.Insert("0.003 1.351 -0.764");
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
			ToolSpawns.Insert("0.314 1.509 4.115");
			ToolSpawns.Insert("-5.812 0.192 1.821");
			ToolSpawns.Insert("-11.098 0.008 -0.079");
			ToolSpawns.Insert("-10.981 0.008 3.736");
		}

		return ToolSpawns;
	}
	static void Spawn(IEntity house, SpawnedHouseLoot data)
	{
		if (!house || !data)
			return;
		LootSpawner.SpawnWeightedFromArray(house, data, GetBedSpawns(), LootTables.GetTownE2I02BedLoot(), 0.16, "BED", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetKitchenSpawns(), LootTables.GetTownE2I02KitchenItems(), 0.14, "KITCHEN", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetWeaponSpawns(), LootTables.GetTownE2I02WeaponItems(), 0.05, "WEAPON", "0 0 0", 0.02);
		LootSpawner.SpawnWeightedFromArray(house, data, GetMedicalSpawns(), LootTables.GetTownE2I02MedicalItems(), 0.10, "MEDICAL", "0 0 0", 0.01);
	}
}
