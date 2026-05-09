class LootHouse_VillageE1I04s
{
	static string PREFAB = "{63352C2865C9C735}PrefabLibrary/DefaultLibrary/Structures/Houses/House_Village_E_1I04s.et";
	static ref array<vector> BedSpawns;

	static array<vector> GetBedSpawns()
	{
		if (!BedSpawns)
		{
			BedSpawns = new array<vector>();
			BedSpawns.Insert("-1.927 0.753 2.397");
			BedSpawns.Insert("-7.721 0.696 1.473");
			BedSpawns.Insert("-6.59 0.696 1.421");
			BedSpawns.Insert("-6.183 0.696 2.845");
			BedSpawns.Insert("-7.384 0.696 2.807");
		}

		return BedSpawns;
	}
	static ref array<vector> KitchenSpawns;

	static array<vector> GetKitchenSpawns()
	{
		if (!KitchenSpawns)
		{
			KitchenSpawns = new array<vector>();
			KitchenSpawns.Insert("-2.001 1.211 -2.494");
			KitchenSpawns.Insert("-2.021 1.211 -1.669");
			KitchenSpawns.Insert("-2.028 1.219 -4.008");
			KitchenSpawns.Insert("-0.12 1.099 -1.473");
			KitchenSpawns.Insert("-0.67 1.093 2.242");
			KitchenSpawns.Insert("-1.263 1.093 3.081");
		}

		return KitchenSpawns;
	}
	static ref array<vector> WeaponSpawns;

	static array<vector> GetWeaponSpawns()
	{
		if (!WeaponSpawns)
		{
			WeaponSpawns = new array<vector>();
			WeaponSpawns.Insert("-7.757 1.194 -1.158");
			WeaponSpawns.Insert("-5.764 0.947 3.83");
		}

		return WeaponSpawns;
	}
	static ref array<vector> MedicalSpawns;

	static array<vector> GetMedicalSpawns()
	{
		if (!MedicalSpawns)
		{
			MedicalSpawns = new array<vector>();
			MedicalSpawns.Insert("1.308 1.102 -4.203");
			MedicalSpawns.Insert("-6.89 1.038 -4.501");
			MedicalSpawns.Insert("-5.946 0.893 -4.435");
			MedicalSpawns.Insert("-7.182 1.199 -2.229");
			MedicalSpawns.Insert("-8.652 0.26 -4.305");
			MedicalSpawns.Insert("-9.385 0.26 -4.356");
			MedicalSpawns.Insert("-9.538 0.756 -2.336");
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
			ToolSpawns.Insert("3.384 0.61 -2.159");
			ToolSpawns.Insert("3.373 0.61 -0.641");
			ToolSpawns.Insert("3.373 1.594 -0.641");
			ToolSpawns.Insert("3.409 1.594 -1.713");
			ToolSpawns.Insert("0.995 0.208 -2.958");
			ToolSpawns.Insert("4.816 0.02 -1.196");
		}

		return ToolSpawns;
	}
	static void Spawn(IEntity house, SpawnedHouseLoot data)
	{
		if (!house || !data)
			return;
		LootSpawner.SpawnWeightedFromArray(house, data, GetBedSpawns(), LootTables.GetTownE2I02BedLoot(), 0.22, "BED", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetKitchenSpawns(), LootTables.GetTownE2I02KitchenItems(), 0.18, "KITCHEN", "0 0 0", 0.01);
		LootSpawner.SpawnWeightedFromArray(house, data, GetWeaponSpawns(), LootTables.GetTownE2I02WeaponItems(), 0.06, "WEAPON", "0 0 0", 0.02);
		LootSpawner.SpawnWeightedFromArray(house, data, GetMedicalSpawns(), LootTables.GetTownE2I02MedicalItems(), 0.12, "MEDICAL", "0 0 0", 0.01);
	}
}
