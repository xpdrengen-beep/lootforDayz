class LootHouse_TownE2I02Y
{
	static string PREFAB = "{7B197693AE45574A}Prefabs/Structures/Houses/Town/House_Town_E_2I02/House_Town_E_2I02_yellow.et";
	static ref array<vector> BedSpawns;

	static array<vector> GetBedSpawns()
	{
		if (!BedSpawns)
		{
			BedSpawns = new array<vector>();
			BedSpawns.Insert("6.043 1.658 0.152");
			BedSpawns.Insert("1.92 0.753 4.756");
			BedSpawns.Insert("8.006 0.722 2.326");
			BedSpawns.Insert("7.588 0.782 5.061");
			BedSpawns.Insert("4.691 0.782 4.496");
			BedSpawns.Insert("-8.03 4.559 -1.081");
			BedSpawns.Insert("-6.68 4.565 -0.343");
			BedSpawns.Insert("4.06 4.528 2.864");
			BedSpawns.Insert("5.712 4.528 4.111");
		}

		return BedSpawns;
	}
	static ref array<vector> KitchenSpawns;

	static array<vector> GetKitchenSpawns()
	{
		if (!KitchenSpawns)
		{
			KitchenSpawns = new array<vector>();
			KitchenSpawns.Insert("4.499 1.27 -3.013");
			KitchenSpawns.Insert("4.495 1.28 -3.552");
			KitchenSpawns.Insert("4.488 1.28 -4.52");
			KitchenSpawns.Insert("6.879 1.176 -3.953");
			KitchenSpawns.Insert("7.499 1.176 -2.96");
			KitchenSpawns.Insert("7.316 0.815 -5.078");
			KitchenSpawns.Insert("8.248 0.815 -3.666");
			KitchenSpawns.Insert("6.889 0.815 -1.998");
			KitchenSpawns.Insert("-6.453 1.159 -1.283");
			KitchenSpawns.Insert("-7.439 1.159 -1.319");
			KitchenSpawns.Insert("-8.323 0.676 -0.822");
			KitchenSpawns.Insert("-8.377 0.695 0.343");
			KitchenSpawns.Insert("7.115 4.967 -4.206");
			KitchenSpawns.Insert("7.73 4.967 -5.208");
			KitchenSpawns.Insert("8.307 5.084 -2.061");
			KitchenSpawns.Insert("8.353 5.084 -1.249");
			KitchenSpawns.Insert("4.207 4.677 3.973");
			KitchenSpawns.Insert("3.341 4.677 4.002");
		}

		return KitchenSpawns;
	}
	static ref array<vector> WeaponSpawns;

	static array<vector> GetWeaponSpawns()
	{
		if (!WeaponSpawns)
		{
			WeaponSpawns = new array<vector>();
			WeaponSpawns.Insert("-1.077 5.062 -2.911");
			WeaponSpawns.Insert("0.159 1.189 2.828");
			WeaponSpawns.Insert("8.191 1.261 -0.463");
			WeaponSpawns.Insert("-8.357 4.968 4.648");
			WeaponSpawns.Insert("-8.349 5.064 2.001");
			WeaponSpawns.Insert("3.309 5.064 -1.211");
			WeaponSpawns.Insert("0.282 5.064 0.835");
			WeaponSpawns.Insert("5.833 8.318 -1.933");
			WeaponSpawns.Insert("4.5 7.496 4.494");
		}

		return WeaponSpawns;
	}
	static ref array<vector> MedicalSpawns;

	static array<vector> GetMedicalSpawns()
	{
		if (!MedicalSpawns)
		{
			MedicalSpawns = new array<vector>();
			MedicalSpawns.Insert("-5.838 1.236 5.037");
			MedicalSpawns.Insert("0.309 0.829 -2.687");
			MedicalSpawns.Insert("0.212 0.333 -4.37");
			MedicalSpawns.Insert("3.241 1.274 -4.301");
			MedicalSpawns.Insert("0.031 4.912 -2.359");
			MedicalSpawns.Insert("0.084 4.775 -3.141");
			MedicalSpawns.Insert("3.303 5.063 -4.384");
		}

		return MedicalSpawns;
	}
	// Placeholder for later tool loot support. No items are spawned from these points yet.
	static ref array<vector> ToolSpawns;
	static array<vector> GetToolSpawns()
	{
		if (!ToolSpawns)
		{
			ToolSpawns = new array<vector>();
			ToolSpawns.Insert("-7.848 1.234 5.062");
			ToolSpawns.Insert("-8.479 0.754 2.751");
			ToolSpawns.Insert("-1.065 1.065 1.621");
			ToolSpawns.Insert("-5.794 1.065 -2.361");
			ToolSpawns.Insert("-8.377 1.659 -0.278");
			ToolSpawns.Insert("-7.622 1.154 -1.355");
			ToolSpawns.Insert("-6.444 1.154 -1.375");
			ToolSpawns.Insert("-8.327 0.685 0.207");
			ToolSpawns.Insert("-7.156 0.712 -1.362");
		}
		return ToolSpawns;
	}
	static void Spawn(IEntity house, SpawnedHouseLoot data)
	{
		if (!house || !data)
			return;
		LootSpawner.SpawnWeightedFromArray(house, data, GetBedSpawns(), LootTables.GetTownE2I02BedLoot(), 0.22, "BED", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetKitchenSpawns(), LootTables.GetTownE2I02KitchenItems(), 0.18, "KITCHEN", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetWeaponSpawns(), LootTables.GetTownE2I02WeaponItems(), 0.08, "WEAPON", "0 0 0", 0.02);
		LootSpawner.SpawnWeightedFromArray(house, data, GetMedicalSpawns(), LootTables.GetTownE2I02MedicalItems(), 0.18, "MEDICAL", "0 0 0", 0.01);
	}
}
