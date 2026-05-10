class LootHouse_TownE2I03
{
	static string PREFAB = "{D288E1E16D11D57B}PrefabLibrary/DefaultLibrary/Structures/Houses/House_Town_E_2I03.et";
	static ref array<vector> BedSpawns;

	static array<vector> GetBedSpawns()
	{
		if (!BedSpawns)
		{
			BedSpawns = new array<vector>();
			BedSpawns.Insert("-5.93 0.691 1.864");
			BedSpawns.Insert("-7.426 0.691 1.778");
			BedSpawns.Insert("-5.195 1.198 1.551");
			BedSpawns.Insert("5.243 0.657 2.43");
			BedSpawns.Insert("6.875 0.657 2.447");
			BedSpawns.Insert("8.866 0.761 0.109");
			BedSpawns.Insert("-1.509 1.103 4.359");
			BedSpawns.Insert("-5.574 3.88 1.302");
			BedSpawns.Insert("-5.598 3.88 0.266");
			BedSpawns.Insert("-4.524 3.986 -1.131");
			BedSpawns.Insert("-2.952 3.986 -1.464");
			BedSpawns.Insert("-8.563 3.99 2.805");
			BedSpawns.Insert("-8.69 3.99 4.073");
			BedSpawns.Insert("5.921 3.992 -1.195");
			BedSpawns.Insert("5.144 3.992 -0.137");
			BedSpawns.Insert("4.4 3.994 -1.722");
			BedSpawns.Insert("5.411 4.364 4.652");
		}

		return BedSpawns;
	}
	static ref array<vector> KitchenSpawns;

	static array<vector> GetKitchenSpawns()
	{
		if (!KitchenSpawns)
		{
			KitchenSpawns = new array<vector>();
			KitchenSpawns.Insert("-4.126 1.193 1.76");
			KitchenSpawns.Insert("5.516 0.79 3.196");
			KitchenSpawns.Insert("6.519 0.79 3.124");
			KitchenSpawns.Insert("7.466 1.101 -0.308");
			KitchenSpawns.Insert("7.855 1.101 0.04");
			KitchenSpawns.Insert("6.786 1.211 -2.548");
			KitchenSpawns.Insert("7.801 1.211 -2.566");
			KitchenSpawns.Insert("7.324 1.091 -4.157");
			KitchenSpawns.Insert("6.197 1.091 -4.74");
			KitchenSpawns.Insert("3.563 1.119 0.425");
			KitchenSpawns.Insert("-5.324 4.41 4.212");
			KitchenSpawns.Insert("-5.292 4.41 3.387");
			KitchenSpawns.Insert("-6.486 4.41 4.312");
			KitchenSpawns.Insert("6.811 4.101 2.666");
			KitchenSpawns.Insert("6.757 4.101 3.198");
			KitchenSpawns.Insert("6.213 4.101 2.93");
		}

		return KitchenSpawns;
	}
	static ref array<vector> WeaponSpawns;

	static array<vector> GetWeaponSpawns()
	{
		if (!WeaponSpawns)
		{
			WeaponSpawns = new array<vector>();
			WeaponSpawns.Insert("5.311 1.214 2.717");
			WeaponSpawns.Insert("-8.922 1.119 2.125");
			WeaponSpawns.Insert("-5.811 1.102 4.435");
			WeaponSpawns.Insert("2.666 1.193 -3.702");
			WeaponSpawns.Insert("-8.719 1.193 -1.622");
			WeaponSpawns.Insert("-6.686 4.493 -4.613");
			WeaponSpawns.Insert("-8.495 4.494 1.78");
			WeaponSpawns.Insert("8.856 3.994 3.985");
			WeaponSpawns.Insert("-2.759 7.284 4.766");
		}

		return WeaponSpawns;
	}
	static ref array<vector> MedicalSpawns;

	static array<vector> GetMedicalSpawns()
	{
		if (!MedicalSpawns)
		{
			MedicalSpawns = new array<vector>();
			MedicalSpawns.Insert("2.636 0.947 4.661");
			MedicalSpawns.Insert("2.629 0.947 3.79");
			MedicalSpawns.Insert("1.611 1.195 -4.646");
			MedicalSpawns.Insert("0.501 0.27 -2.582");
			MedicalSpawns.Insert("1.604 0.27 -2.586");
			MedicalSpawns.Insert("-3.086 4.053 -2.668");
			MedicalSpawns.Insert("-4.494 3.645 -2.544");
			MedicalSpawns.Insert("-5.34 3.645 -2.608");
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
			ToolSpawns.Insert("-7.047 1.231 -4.491");
			ToolSpawns.Insert("-8.347 0.21 -3.882");
			ToolSpawns.Insert("-8.099 0.21 0.189");
			ToolSpawns.Insert("-2.489 6.834 0.155");
			ToolSpawns.Insert("-6.21 6.834 1.255");
			ToolSpawns.Insert("-8.665 6.834 -3.181");
			ToolSpawns.Insert("8.188 6.834 -4.407");
			ToolSpawns.Insert("-7.509 6.834 4.358");
			ToolSpawns.Insert("1.054 6.834 -4.605");
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
