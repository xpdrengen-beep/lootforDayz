class LootTables
{

	static ref array<ref LootEntry> E1I01_PBedLoot;

	static array<ref LootEntry> GetE1I01_PBedLoot()
	{
		if (!E1I01_PBedLoot)
		{
			E1I01_PBedLoot = new array<ref LootEntry>();
			E1I01_PBedLoot.Insert(new LootEntry("{4B57C11AA5161760}Prefabs/Characters/Vests/Vest_PASGT/Vest_PASGT.et", 60));
			E1I01_PBedLoot.Insert(new LootEntry("{06B68C58B72EAAC6}Prefabs/Items/Equipment/Backpacks/Backpack_ALICE_Medium.et", 15));
			E1I01_PBedLoot.Insert(new LootEntry("{95D4766BBE46F23D}Prefabs/Items/Equipment/Backpacks/Backpack_IIFS_FieldPack.et", 25));
			E1I01_PBedLoot.Insert(new LootEntry("{AC298BA8A7D27007}Prefabs/Items/Equipment/Backpacks/Backpack_Medical_Soviet_NoCross_01.et", 34));
			E1I01_PBedLoot.Insert(new LootEntry("{6A39B5843B3F36DA}Prefabs/Items/Equipment/Backpacks/Backpack_RPG_Assistant.et", 15));
		}

		return E1I01_PBedLoot;
	}
	static ref array<ref LootEntry> E1I01_PKitchenItems;

	static array<ref LootEntry> GetE1I01_PKitchenItems()
	{
		if (!E1I01_PKitchenItems)
		{
			E1I01_PKitchenItems = new array<ref LootEntry>();
			E1I01_PKitchenItems.Insert(new LootEntry("{128A19AA9F731095}Prefabs/Items/Food/MeatLeg_01.et", 65));
		}

		return E1I01_PKitchenItems;
	}
	static ref array<ref LootEntry> E1I01_PWeaponItems;

	static array<ref LootEntry> GetE1I01_PWeaponItems()
	{
		if (!E1I01_PWeaponItems)
		{
			E1I01_PWeaponItems = new array<ref LootEntry>();
			E1I01_PWeaponItems.Insert(new LootEntry("{C1B4F7B87B720EE8}Prefabs/Weapons/Rifles/Mosin/BC_Rifle_Mosin_Nagant_9130.et", 15));
			E1I01_PWeaponItems.Insert(new LootEntry("{6545DEABED4759E5}Prefabs/Weapons/Rifles/Mosin/BC_Rifle_Mosin_Nagant_9130_PU.et", 5));
			E1I01_PWeaponItems.Insert(new LootEntry("{8F5A4A44DD1D84D6}Prefabs/Weapons/Rifles/M1 Garand/BC_Rifle_M1_Garand.et", 15));
			E1I01_PWeaponItems.Insert(new LootEntry("{898B4433EED614A4}Prefabs/Weapons/Rifles/M1 Garand/BC_Rifle_M1D.et", 5));
			E1I01_PWeaponItems.Insert(new LootEntry("{8231579E96735D40}Prefabs/Weapons/Attachments/Muzzle/Mosin/BC_Suppressor_Bramit_Mosin.et", 3));
		}

		return E1I01_PWeaponItems;
	}
	static ref array<ref LootEntry> E1I01_PMedicalItems;
	static array<ref LootEntry> GetE1I01_PMedicalItems()
	{
		if (!E1I01_PMedicalItems)
		{
			E1I01_PMedicalItems = new array<ref LootEntry>();
			E1I01_PMedicalItems.Insert(new LootEntry("{AC298BA8A7D27007}Prefabs/Items/Equipment/Backpacks/Backpack_Medical_Soviet_NoCross_01.et", 100));
		}
		return E1I01_PMedicalItems;
	}
	static ref array<ref LootEntry> E1I01BedLoot;
	static array<ref LootEntry> GetE1I01BedLoot()
	{
		if (!E1I01BedLoot)
		{
			E1I01BedLoot = new array<ref LootEntry>();
			E1I01BedLoot.Insert(new LootEntry("{4B57C11AA5161760}Prefabs/Characters/Vests/Vest_PASGT/Vest_PASGT.et", 60));
			E1I01BedLoot.Insert(new LootEntry("{06B68C58B72EAAC6}Prefabs/Items/Equipment/Backpacks/Backpack_ALICE_Medium.et", 15));
			E1I01BedLoot.Insert(new LootEntry("{95D4766BBE46F23D}Prefabs/Items/Equipment/Backpacks/Backpack_IIFS_FieldPack.et", 25));
			E1I01BedLoot.Insert(new LootEntry("{AC298BA8A7D27007}Prefabs/Items/Equipment/Backpacks/Backpack_Medical_Soviet_NoCross_01.et", 34));
			E1I01BedLoot.Insert(new LootEntry("{6A39B5843B3F36DA}Prefabs/Items/Equipment/Backpacks/Backpack_RPG_Assistant.et", 15));
		}
		return E1I01BedLoot;
	}
	static ref array<ref LootEntry> E1I01KitchenItems;

	static array<ref LootEntry> GetE1I01KitchenItems()
	{
		if (!E1I01KitchenItems)
		{
			E1I01KitchenItems = new array<ref LootEntry>();
			E1I01KitchenItems.Insert(new LootEntry("{128A19AA9F731095}Prefabs/Items/Food/MeatLeg_01.et", 65));
		}

		return E1I01KitchenItems;
	}
	static ref array<ref LootEntry> E1I01WeaponItems;

	static array<ref LootEntry> GetE1I01WeaponItems()
	{
		if (!E1I01WeaponItems)
		{
			E1I01WeaponItems = new array<ref LootEntry>();
			E1I01WeaponItems.Insert(new LootEntry("{C1B4F7B87B720EE8}Prefabs/Weapons/Rifles/Mosin/BC_Rifle_Mosin_Nagant_9130.et", 15));
			E1I01WeaponItems.Insert(new LootEntry("{6545DEABED4759E5}Prefabs/Weapons/Rifles/Mosin/BC_Rifle_Mosin_Nagant_9130_PU.et", 5));
			E1I01WeaponItems.Insert(new LootEntry("{8F5A4A44DD1D84D6}Prefabs/Weapons/Rifles/M1 Garand/BC_Rifle_M1_Garand.et", 15));
			E1I01WeaponItems.Insert(new LootEntry("{898B4433EED614A4}Prefabs/Weapons/Rifles/M1 Garand/BC_Rifle_M1D.et", 5));
			E1I01WeaponItems.Insert(new LootEntry("{8231579E96735D40}Prefabs/Weapons/Attachments/Muzzle/Mosin/BC_Suppressor_Bramit_Mosin.et", 3));
		}

		return E1I01WeaponItems;
	}
	static ref array<ref LootEntry> E1I01MedicalItems;
	static array<ref LootEntry> GetE1I01MedicalItems()
	{
		if (!E1I01MedicalItems)
		{
			E1I01MedicalItems = new array<ref LootEntry>();
			E1I01MedicalItems.Insert(new LootEntry("{AC298BA8A7D27007}Prefabs/Items/Equipment/Backpacks/Backpack_Medical_Soviet_NoCross_01.et", 100));
		}
		return E1I01MedicalItems;
	}
	static ref array<ref LootEntry> E1I03BedLoot;

	static array<ref LootEntry> GetE1I03BedLoot()
	{
		if (!E1I03BedLoot)
		{
			E1I03BedLoot = new array<ref LootEntry>();
			E1I03BedLoot.Insert(new LootEntry("{4B57C11AA5161760}Prefabs/Characters/Vests/Vest_PASGT/Vest_PASGT.et", 60));
			E1I03BedLoot.Insert(new LootEntry("{06B68C58B72EAAC6}Prefabs/Items/Equipment/Backpacks/Backpack_ALICE_Medium.et", 15));
			E1I03BedLoot.Insert(new LootEntry("{95D4766BBE46F23D}Prefabs/Items/Equipment/Backpacks/Backpack_IIFS_FieldPack.et", 25));
			E1I03BedLoot.Insert(new LootEntry("{AC298BA8A7D27007}Prefabs/Items/Equipment/Backpacks/Backpack_Medical_Soviet_NoCross_01.et", 34));
			E1I03BedLoot.Insert(new LootEntry("{6A39B5843B3F36DA}Prefabs/Items/Equipment/Backpacks/Backpack_RPG_Assistant.et", 15));
		}

		return E1I03BedLoot;
	}
	static ref array<ref LootEntry> E1I03KitchenItems;

	static array<ref LootEntry> GetE1I03KitchenItems()
	{
		if (!E1I03KitchenItems)
		{
			E1I03KitchenItems = new array<ref LootEntry>();
			E1I03KitchenItems.Insert(new LootEntry("{128A19AA9F731095}Prefabs/Items/Food/MeatLeg_01.et", 65));
		}

		return E1I03KitchenItems;
	}
	static ref array<ref LootEntry> E1I03WeaponItems;

	static array<ref LootEntry> GetE1I03WeaponItems()
	{
		if (!E1I03WeaponItems)
		{
			E1I03WeaponItems = new array<ref LootEntry>();
			E1I03WeaponItems.Insert(new LootEntry("{C1B4F7B87B720EE8}Prefabs/Weapons/Rifles/Mosin/BC_Rifle_Mosin_Nagant_9130.et", 15));
			E1I03WeaponItems.Insert(new LootEntry("{6545DEABED4759E5}Prefabs/Weapons/Rifles/Mosin/BC_Rifle_Mosin_Nagant_9130_PU.et", 5));
			E1I03WeaponItems.Insert(new LootEntry("{8F5A4A44DD1D84D6}Prefabs/Weapons/Rifles/M1 Garand/BC_Rifle_M1_Garand.et", 15));
			E1I03WeaponItems.Insert(new LootEntry("{898B4433EED614A4}Prefabs/Weapons/Rifles/M1 Garand/BC_Rifle_M1D.et", 5));
			E1I03WeaponItems.Insert(new LootEntry("{8231579E96735D40}Prefabs/Weapons/Attachments/Muzzle/Mosin/BC_Suppressor_Bramit_Mosin.et", 3));
		}

		return E1I03WeaponItems;
	}
	static ref array<ref LootEntry> E1I03MedicalItems;
	static array<ref LootEntry> GetE1I03MedicalItems()
	{
		if (!E1I03MedicalItems)
		{
			E1I03MedicalItems = new array<ref LootEntry>();
			E1I03MedicalItems.Insert(new LootEntry("{AC298BA8A7D27007}Prefabs/Items/Equipment/Backpacks/Backpack_Medical_Soviet_NoCross_01.et", 100));
		}
		return E1I03MedicalItems;
	}
	static ref array<ref LootEntry> TownE2I02BedLoot;

	static array<ref LootEntry> GetTownE2I02BedLoot()
	{
		if (!TownE2I02BedLoot)
		{
			TownE2I02BedLoot = new array<ref LootEntry>();
			TownE2I02BedLoot.Insert(new LootEntry("{4B57C11AA5161760}Prefabs/Characters/Vests/Vest_PASGT/Vest_PASGT.et", 60));
			TownE2I02BedLoot.Insert(new LootEntry("{06B68C58B72EAAC6}Prefabs/Items/Equipment/Backpacks/Backpack_ALICE_Medium.et", 15));
			TownE2I02BedLoot.Insert(new LootEntry("{95D4766BBE46F23D}Prefabs/Items/Equipment/Backpacks/Backpack_IIFS_FieldPack.et", 25));
			TownE2I02BedLoot.Insert(new LootEntry("{AC298BA8A7D27007}Prefabs/Items/Equipment/Backpacks/Backpack_Medical_Soviet_NoCross_01.et", 34));
			TownE2I02BedLoot.Insert(new LootEntry("{6A39B5843B3F36DA}Prefabs/Items/Equipment/Backpacks/Backpack_RPG_Assistant.et", 15));
		}

		return TownE2I02BedLoot;
	}
	static ref array<ref LootEntry> TownE2I02KitchenItems;

	static array<ref LootEntry> GetTownE2I02KitchenItems()
	{
		if (!TownE2I02KitchenItems)
		{
			TownE2I02KitchenItems = new array<ref LootEntry>();
			TownE2I02KitchenItems.Insert(new LootEntry("{128A19AA9F731095}Prefabs/Items/Food/MeatLeg_01.et", 65));
		}

		return TownE2I02KitchenItems;
	}
	static ref array<ref LootEntry> TownE2I02WeaponItems;

	static array<ref LootEntry> GetTownE2I02WeaponItems()
	{
		if (!TownE2I02WeaponItems)
		{
			TownE2I02WeaponItems = new array<ref LootEntry>();
			TownE2I02WeaponItems.Insert(new LootEntry("{C1B4F7B87B720EE8}Prefabs/Weapons/Rifles/Mosin/BC_Rifle_Mosin_Nagant_9130.et", 15));
			TownE2I02WeaponItems.Insert(new LootEntry("{6545DEABED4759E5}Prefabs/Weapons/Rifles/Mosin/BC_Rifle_Mosin_Nagant_9130_PU.et", 5));
			TownE2I02WeaponItems.Insert(new LootEntry("{8F5A4A44DD1D84D6}Prefabs/Weapons/Rifles/M1 Garand/BC_Rifle_M1_Garand.et", 15));
			TownE2I02WeaponItems.Insert(new LootEntry("{898B4433EED614A4}Prefabs/Weapons/Rifles/M1 Garand/BC_Rifle_M1D.et", 5));
			TownE2I02WeaponItems.Insert(new LootEntry("{8231579E96735D40}Prefabs/Weapons/Attachments/Muzzle/Mosin/BC_Suppressor_Bramit_Mosin.et", 3));
		}

		return TownE2I02WeaponItems;
	}
	static ref array<ref LootEntry> TownE2I02MedicalItems;

	static array<ref LootEntry> GetTownE2I02MedicalItems()
	{
		if (!TownE2I02MedicalItems)
		{
			TownE2I02MedicalItems = new array<ref LootEntry>();
			TownE2I02MedicalItems.Insert(new LootEntry("{AC298BA8A7D27007}Prefabs/Items/Equipment/Backpacks/Backpack_Medical_Soviet_NoCross_01.et", 100));
		}

		return TownE2I02MedicalItems;
	}
	static ref array<ref LootEntry> hRaGBedLoot;

	static array<ref LootEntry> GethRaGBedLoot()
	{
		if (!hRaGBedLoot)
		{
			hRaGBedLoot = new array<ref LootEntry>();
			hRaGBedLoot.Insert(new LootEntry("{4B57C11AA5161760}Prefabs/Characters/Vests/Vest_PASGT/Vest_PASGT.et", 60));
			hRaGBedLoot.Insert(new LootEntry("{06B68C58B72EAAC6}Prefabs/Items/Equipment/Backpacks/Backpack_ALICE_Medium.et", 15));
			hRaGBedLoot.Insert(new LootEntry("{95D4766BBE46F23D}Prefabs/Items/Equipment/Backpacks/Backpack_IIFS_FieldPack.et", 25));
			hRaGBedLoot.Insert(new LootEntry("{AC298BA8A7D27007}Prefabs/Items/Equipment/Backpacks/Backpack_Medical_Soviet_NoCross_01.et", 34));
			hRaGBedLoot.Insert(new LootEntry("{6A39B5843B3F36DA}Prefabs/Items/Equipment/Backpacks/Backpack_RPG_Assistant.et", 15));
		}

		return hRaGBedLoot;
	}
	static ref array<ref LootEntry> hRaGKitchenItems;

	static array<ref LootEntry> GethRaGKitchenItems()
	{
		if (!hRaGKitchenItems)
		{
			hRaGKitchenItems = new array<ref LootEntry>();
			hRaGKitchenItems.Insert(new LootEntry("{128A19AA9F731095}Prefabs/Items/Food/MeatLeg_01.et", 65));
		}

		return hRaGKitchenItems;
	}
	static ref array<ref LootEntry> hRaGWeaponItems;

	static array<ref LootEntry> GethRaGWeaponItems()
	{
		if (!hRaGWeaponItems)
		{
			hRaGWeaponItems = new array<ref LootEntry>();
			hRaGWeaponItems.Insert(new LootEntry("{C1B4F7B87B720EE8}Prefabs/Weapons/Rifles/Mosin/BC_Rifle_Mosin_Nagant_9130.et", 15));
			hRaGWeaponItems.Insert(new LootEntry("{6545DEABED4759E5}Prefabs/Weapons/Rifles/Mosin/BC_Rifle_Mosin_Nagant_9130_PU.et", 5));
			hRaGWeaponItems.Insert(new LootEntry("{8F5A4A44DD1D84D6}Prefabs/Weapons/Rifles/M1 Garand/BC_Rifle_M1_Garand.et", 15));
			hRaGWeaponItems.Insert(new LootEntry("{898B4433EED614A4}Prefabs/Weapons/Rifles/M1 Garand/BC_Rifle_M1D.et", 5));
			hRaGWeaponItems.Insert(new LootEntry("{8231579E96735D40}Prefabs/Weapons/Attachments/Muzzle/Mosin/BC_Suppressor_Bramit_Mosin.et", 3));
		}

		return hRaGWeaponItems;
	}
	static ref array<ref LootEntry> hRaGMedicalItems;

	static array<ref LootEntry> GethRaGMedicalItems()
	{
		if (!hRaGMedicalItems)
		{
			hRaGMedicalItems = new array<ref LootEntry>();
			hRaGMedicalItems.Insert(new LootEntry("{AC298BA8A7D27007}Prefabs/Items/Equipment/Backpacks/Backpack_Medical_Soviet_NoCross_01.et", 100));
		}

		return hRaGMedicalItems;
	}
	static ref array<ref LootEntry> h06BedLoot;

	static array<ref LootEntry> Geth06BedLoot()
	{
		if (!h06BedLoot)
		{
			h06BedLoot = new array<ref LootEntry>();
			h06BedLoot.Insert(new LootEntry("{4B57C11AA5161760}Prefabs/Characters/Vests/Vest_PASGT/Vest_PASGT.et", 60));
			h06BedLoot.Insert(new LootEntry("{06B68C58B72EAAC6}Prefabs/Items/Equipment/Backpacks/Backpack_ALICE_Medium.et", 15));
			h06BedLoot.Insert(new LootEntry("{95D4766BBE46F23D}Prefabs/Items/Equipment/Backpacks/Backpack_IIFS_FieldPack.et", 25));
			h06BedLoot.Insert(new LootEntry("{AC298BA8A7D27007}Prefabs/Items/Equipment/Backpacks/Backpack_Medical_Soviet_NoCross_01.et", 34));
			h06BedLoot.Insert(new LootEntry("{6A39B5843B3F36DA}Prefabs/Items/Equipment/Backpacks/Backpack_RPG_Assistant.et", 15));
		}

		return h06BedLoot;
	}
	static ref array<ref LootEntry> h06KitchenItems;

	static array<ref LootEntry> Geth06KitchenItems()
	{
		if (!h06KitchenItems)
		{
			h06KitchenItems = new array<ref LootEntry>();
			h06KitchenItems.Insert(new LootEntry("{128A19AA9F731095}Prefabs/Items/Food/MeatLeg_01.et", 65));
		}

		return h06KitchenItems;
	}
	static ref array<ref LootEntry> h06WeaponItems;

	static array<ref LootEntry> Geth06WeaponItems()
	{
		if (!h06WeaponItems)
		{
			h06WeaponItems = new array<ref LootEntry>();
			h06WeaponItems.Insert(new LootEntry("{C1B4F7B87B720EE8}Prefabs/Weapons/Rifles/Mosin/BC_Rifle_Mosin_Nagant_9130.et", 15));
			h06WeaponItems.Insert(new LootEntry("{6545DEABED4759E5}Prefabs/Weapons/Rifles/Mosin/BC_Rifle_Mosin_Nagant_9130_PU.et", 5));
			h06WeaponItems.Insert(new LootEntry("{8F5A4A44DD1D84D6}Prefabs/Weapons/Rifles/M1 Garand/BC_Rifle_M1_Garand.et", 15));
			h06WeaponItems.Insert(new LootEntry("{898B4433EED614A4}Prefabs/Weapons/Rifles/M1 Garand/BC_Rifle_M1D.et", 5));
			h06WeaponItems.Insert(new LootEntry("{8231579E96735D40}Prefabs/Weapons/Attachments/Muzzle/Mosin/BC_Suppressor_Bramit_Mosin.et", 3));
		}

		return h06WeaponItems;
	}
	static ref array<ref LootEntry> h06MedicalItems;

	static array<ref LootEntry> Geth06MedicalItems()
	{
		if (!h06MedicalItems)
		{
			h06MedicalItems = new array<ref LootEntry>();
			h06MedicalItems.Insert(new LootEntry("{AC298BA8A7D27007}Prefabs/Items/Equipment/Backpacks/Backpack_Medical_Soviet_NoCross_01.et", 100));
		}

		return h06MedicalItems;
	}
	static ref array<ref LootEntry> h08BedLoot;

	static array<ref LootEntry> Geth08BedLoot()
	{
		if (!h08BedLoot)
		{
			h08BedLoot = new array<ref LootEntry>();
			h08BedLoot.Insert(new LootEntry("{4B57C11AA5161760}Prefabs/Characters/Vests/Vest_PASGT/Vest_PASGT.et", 60));
			h08BedLoot.Insert(new LootEntry("{06B68C58B72EAAC6}Prefabs/Items/Equipment/Backpacks/Backpack_ALICE_Medium.et", 15));
			h08BedLoot.Insert(new LootEntry("{95D4766BBE46F23D}Prefabs/Items/Equipment/Backpacks/Backpack_IIFS_FieldPack.et", 25));
			h08BedLoot.Insert(new LootEntry("{AC298BA8A7D27007}Prefabs/Items/Equipment/Backpacks/Backpack_Medical_Soviet_NoCross_01.et", 34));
			h08BedLoot.Insert(new LootEntry("{6A39B5843B3F36DA}Prefabs/Items/Equipment/Backpacks/Backpack_RPG_Assistant.et", 15));
		}

		return h08BedLoot;
	}
	static ref array<ref LootEntry> h08KitchenItems;

	static array<ref LootEntry> Geth08KitchenItems()
	{
		if (!h08KitchenItems)
		{
			h08KitchenItems = new array<ref LootEntry>();
			h08KitchenItems.Insert(new LootEntry("{128A19AA9F731095}Prefabs/Items/Food/MeatLeg_01.et", 65));
		}

		return h08KitchenItems;
	}
	static ref array<ref LootEntry> h08WeaponItems;

	static array<ref LootEntry> Geth08WeaponItems()
	{
		if (!h08WeaponItems)
		{
			h08WeaponItems = new array<ref LootEntry>();
			h08WeaponItems.Insert(new LootEntry("{C1B4F7B87B720EE8}Prefabs/Weapons/Rifles/Mosin/BC_Rifle_Mosin_Nagant_9130.et", 15));
			h08WeaponItems.Insert(new LootEntry("{6545DEABED4759E5}Prefabs/Weapons/Rifles/Mosin/BC_Rifle_Mosin_Nagant_9130_PU.et", 5));
			h08WeaponItems.Insert(new LootEntry("{8F5A4A44DD1D84D6}Prefabs/Weapons/Rifles/M1 Garand/BC_Rifle_M1_Garand.et", 15));
			h08WeaponItems.Insert(new LootEntry("{898B4433EED614A4}Prefabs/Weapons/Rifles/M1 Garand/BC_Rifle_M1D.et", 5));
			h08WeaponItems.Insert(new LootEntry("{8231579E96735D40}Prefabs/Weapons/Attachments/Muzzle/Mosin/BC_Suppressor_Bramit_Mosin.et", 3));
		}

		return h08WeaponItems;
	}
	static ref array<ref LootEntry> h08MedicalItems;

	static array<ref LootEntry> Geth08MedicalItems()
	{
		if (!h08MedicalItems)
		{
			h08MedicalItems = new array<ref LootEntry>();
			h08MedicalItems.Insert(new LootEntry("{AC298BA8A7D27007}Prefabs/Items/Equipment/Backpacks/Backpack_Medical_Soviet_NoCross_01.et", 100));
		}

		return h08MedicalItems;
	}
	static ref array<ref LootEntry> h07BedLoot;

	static array<ref LootEntry> Geth07BedLoot()
	{
		if (!h07BedLoot)
		{
			h07BedLoot = new array<ref LootEntry>();
			h07BedLoot.Insert(new LootEntry("{4B57C11AA5161760}Prefabs/Characters/Vests/Vest_PASGT/Vest_PASGT.et", 60));
			h07BedLoot.Insert(new LootEntry("{06B68C58B72EAAC6}Prefabs/Items/Equipment/Backpacks/Backpack_ALICE_Medium.et", 15));
			h07BedLoot.Insert(new LootEntry("{95D4766BBE46F23D}Prefabs/Items/Equipment/Backpacks/Backpack_IIFS_FieldPack.et", 25));
			h07BedLoot.Insert(new LootEntry("{AC298BA8A7D27007}Prefabs/Items/Equipment/Backpacks/Backpack_Medical_Soviet_NoCross_01.et", 34));
			h07BedLoot.Insert(new LootEntry("{6A39B5843B3F36DA}Prefabs/Items/Equipment/Backpacks/Backpack_RPG_Assistant.et", 15));
		}

		return h07BedLoot;
	}
	static ref array<ref LootEntry> h07KitchenItems;

	static array<ref LootEntry> Geth07KitchenItems()
	{
		if (!h07KitchenItems)
		{
			h07KitchenItems = new array<ref LootEntry>();
			h07KitchenItems.Insert(new LootEntry("{128A19AA9F731095}Prefabs/Items/Food/MeatLeg_01.et", 65));
		}

		return h07KitchenItems;
	}
	static ref array<ref LootEntry> h07WeaponItems;

	static array<ref LootEntry> Geth07WeaponItems()
	{
		if (!h07WeaponItems)
		{
			h07WeaponItems = new array<ref LootEntry>();
			h07WeaponItems.Insert(new LootEntry("{C1B4F7B87B720EE8}Prefabs/Weapons/Rifles/Mosin/BC_Rifle_Mosin_Nagant_9130.et", 15));
			h07WeaponItems.Insert(new LootEntry("{6545DEABED4759E5}Prefabs/Weapons/Rifles/Mosin/BC_Rifle_Mosin_Nagant_9130_PU.et", 5));
			h07WeaponItems.Insert(new LootEntry("{8F5A4A44DD1D84D6}Prefabs/Weapons/Rifles/M1 Garand/BC_Rifle_M1_Garand.et", 15));
			h07WeaponItems.Insert(new LootEntry("{898B4433EED614A4}Prefabs/Weapons/Rifles/M1 Garand/BC_Rifle_M1D.et", 5));
			h07WeaponItems.Insert(new LootEntry("{8231579E96735D40}Prefabs/Weapons/Attachments/Muzzle/Mosin/BC_Suppressor_Bramit_Mosin.et", 3));
		}

		return h07WeaponItems;
	}
	static ref array<ref LootEntry> h07MedicalItems;

	static array<ref LootEntry> Geth07MedicalItems()
	{
		if (!h07MedicalItems)
		{
			h07MedicalItems = new array<ref LootEntry>();
			h07MedicalItems.Insert(new LootEntry("{AC298BA8A7D27007}Prefabs/Items/Equipment/Backpacks/Backpack_Medical_Soviet_NoCross_01.et", 100));
		}

		return h07MedicalItems;
	}
	static ref array<ref LootEntry> h04BedLoot;

	static array<ref LootEntry> Geth04BedLoot()
	{
		if (!h04BedLoot)
		{
			h04BedLoot = new array<ref LootEntry>();
			h04BedLoot.Insert(new LootEntry("{4B57C11AA5161760}Prefabs/Characters/Vests/Vest_PASGT/Vest_PASGT.et", 60));
			h04BedLoot.Insert(new LootEntry("{06B68C58B72EAAC6}Prefabs/Items/Equipment/Backpacks/Backpack_ALICE_Medium.et", 15));
			h04BedLoot.Insert(new LootEntry("{95D4766BBE46F23D}Prefabs/Items/Equipment/Backpacks/Backpack_IIFS_FieldPack.et", 25));
			h04BedLoot.Insert(new LootEntry("{AC298BA8A7D27007}Prefabs/Items/Equipment/Backpacks/Backpack_Medical_Soviet_NoCross_01.et", 34));
			h04BedLoot.Insert(new LootEntry("{6A39B5843B3F36DA}Prefabs/Items/Equipment/Backpacks/Backpack_RPG_Assistant.et", 15));
		}

		return h04BedLoot;
	}
	static ref array<ref LootEntry> h05BedLoot;
	static array<ref LootEntry> Geth05BedLoot()
	{
		if (!h05BedLoot)
		{
			h05BedLoot = new array<ref LootEntry>();
			h05BedLoot.Insert(new LootEntry("{4B57C11AA5161760}Prefabs/Characters/Vests/Vest_PASGT/Vest_PASGT.et", 60));
			h05BedLoot.Insert(new LootEntry("{06B68C58B72EAAC6}Prefabs/Items/Equipment/Backpacks/Backpack_ALICE_Medium.et", 15));
			h05BedLoot.Insert(new LootEntry("{95D4766BBE46F23D}Prefabs/Items/Equipment/Backpacks/Backpack_IIFS_FieldPack.et", 25));
			h05BedLoot.Insert(new LootEntry("{AC298BA8A7D27007}Prefabs/Items/Equipment/Backpacks/Backpack_Medical_Soviet_NoCross_01.et", 34));
			h05BedLoot.Insert(new LootEntry("{6A39B5843B3F36DA}Prefabs/Items/Equipment/Backpacks/Backpack_RPG_Assistant.et", 15));
		}
		return h05BedLoot;
	}
	static ref array<ref LootEntry> h05KitchenItems;

	static array<ref LootEntry> Geth05KitchenItems()
	{
		if (!h05KitchenItems)
		{
			h05KitchenItems = new array<ref LootEntry>();
			h05KitchenItems.Insert(new LootEntry("{128A19AA9F731095}Prefabs/Items/Food/MeatLeg_01.et", 65));
		}

		return h05KitchenItems;
	}
	static ref array<ref LootEntry> h05WeaponItems;

	static array<ref LootEntry> Geth05WeaponItems()
	{
		if (!h05WeaponItems)
		{
			h05WeaponItems = new array<ref LootEntry>();
			h05WeaponItems.Insert(new LootEntry("{C1B4F7B87B720EE8}Prefabs/Weapons/Rifles/Mosin/BC_Rifle_Mosin_Nagant_9130.et", 15));
			h05WeaponItems.Insert(new LootEntry("{6545DEABED4759E5}Prefabs/Weapons/Rifles/Mosin/BC_Rifle_Mosin_Nagant_9130_PU.et", 5));
			h05WeaponItems.Insert(new LootEntry("{8F5A4A44DD1D84D6}Prefabs/Weapons/Rifles/M1 Garand/BC_Rifle_M1_Garand.et", 15));
			h05WeaponItems.Insert(new LootEntry("{898B4433EED614A4}Prefabs/Weapons/Rifles/M1 Garand/BC_Rifle_M1D.et", 5));
			h05WeaponItems.Insert(new LootEntry("{8231579E96735D40}Prefabs/Weapons/Attachments/Muzzle/Mosin/BC_Suppressor_Bramit_Mosin.et", 3));
		}

		return h05WeaponItems;
	}
	static ref array<ref LootEntry> h05MedicalItems;

	static array<ref LootEntry> Geth05MedicalItems()
	{
		if (!h05MedicalItems)
		{
			h05MedicalItems = new array<ref LootEntry>();
			h05MedicalItems.Insert(new LootEntry("{AC298BA8A7D27007}Prefabs/Items/Equipment/Backpacks/Backpack_Medical_Soviet_NoCross_01.et", 100));
		}

		return h05MedicalItems;
	}
	static ref array<ref LootEntry> h03BedLoot;

	static array<ref LootEntry> Geth03BedLoot()
	{
		if (!h03BedLoot)
		{
			h03BedLoot = new array<ref LootEntry>();
			h03BedLoot.Insert(new LootEntry("{4B57C11AA5161760}Prefabs/Characters/Vests/Vest_PASGT/Vest_PASGT.et", 60));
			h03BedLoot.Insert(new LootEntry("{06B68C58B72EAAC6}Prefabs/Items/Equipment/Backpacks/Backpack_ALICE_Medium.et", 15));
			h03BedLoot.Insert(new LootEntry("{95D4766BBE46F23D}Prefabs/Items/Equipment/Backpacks/Backpack_IIFS_FieldPack.et", 25));
			h03BedLoot.Insert(new LootEntry("{AC298BA8A7D27007}Prefabs/Items/Equipment/Backpacks/Backpack_Medical_Soviet_NoCross_01.et", 34));
			h03BedLoot.Insert(new LootEntry("{6A39B5843B3F36DA}Prefabs/Items/Equipment/Backpacks/Backpack_RPG_Assistant.et", 15));
		}

		return h03BedLoot;
	}
	static ref array<ref LootEntry> h03KitchenItems;

	static array<ref LootEntry> Geth03KitchenItems()
	{
		if (!h03KitchenItems)
		{
			h03KitchenItems = new array<ref LootEntry>();
			h03KitchenItems.Insert(new LootEntry("{128A19AA9F731095}Prefabs/Items/Food/MeatLeg_01.et", 65));
		}

		return h03KitchenItems;
	}
	static ref array<ref LootEntry> h03WeaponItems;

	static array<ref LootEntry> Geth03WeaponItems()
	{
		if (!h03WeaponItems)
		{
			h03WeaponItems = new array<ref LootEntry>();
			h03WeaponItems.Insert(new LootEntry("{C1B4F7B87B720EE8}Prefabs/Weapons/Rifles/Mosin/BC_Rifle_Mosin_Nagant_9130.et", 15));
			h03WeaponItems.Insert(new LootEntry("{6545DEABED4759E5}Prefabs/Weapons/Rifles/Mosin/BC_Rifle_Mosin_Nagant_9130_PU.et", 5));
			h03WeaponItems.Insert(new LootEntry("{8F5A4A44DD1D84D6}Prefabs/Weapons/Rifles/M1 Garand/BC_Rifle_M1_Garand.et", 15));
			h03WeaponItems.Insert(new LootEntry("{898B4433EED614A4}Prefabs/Weapons/Rifles/M1 Garand/BC_Rifle_M1D.et", 5));
			h03WeaponItems.Insert(
				new LootEntry("{8231579E96735D40}Prefabs/Weapons/Attachments/Muzzle/Mosin/BC_Suppressor_Bramit_Mosin.et", 3)
				//Tilføj ting med lignende linje -  new LootEntry("{C1B4F7B87B720EE8}Prefabs/Weapons/Rifles/Mosin/BC_Rifle_Mosin_Nagant_9130.et", 65)
			);
		}

		return h03WeaponItems;
	}

	static ref array<ref LootEntry> ToolItems;

	static array<ref LootEntry> GetToolItems()
	{
		if (!ToolItems)
			ToolItems = new array<ref LootEntry>();

		return ToolItems;
	}

	static array<ref LootEntry> GetFarmHouseE1L01BedLoot()
	{
		return GetTownE2I02BedLoot();
	}

	static array<ref LootEntry> GetFarmHouseE1L01KitchenItems()
	{
		return GetTownE2I02KitchenItems();
	}

	static array<ref LootEntry> GetFarmHouseE1L01WeaponItems()
	{
		return GetTownE2I02WeaponItems();
	}

	static array<ref LootEntry> GetFarmHouseE1L01MedicalItems()
	{
		return GetTownE2I02MedicalItems();
	}

	static array<ref LootEntry> GetHouse2Floors01BedLoot()
	{
		return GetTownE2I02BedLoot();
	}

	static array<ref LootEntry> GetHouse2Floors01KitchenItems()
	{
		return GetTownE2I02KitchenItems();
	}

	static array<ref LootEntry> GetHouse2Floors01WeaponItems()
	{
		return GetTownE2I02WeaponItems();
	}

	static array<ref LootEntry> GetHouse2Floors01MedicalItems()
	{
		return GetTownE2I02MedicalItems();
	}

	static array<ref LootEntry> GetBrickbuilding01BedLoot()
	{
		return GetTownE2I02BedLoot();
	}

	static array<ref LootEntry> GetBrickbuilding01KitchenItems()
	{
		return GetTownE2I02KitchenItems();
	}

	static array<ref LootEntry> GetBrickbuilding01WeaponItems()
	{
		return GetTownE2I02WeaponItems();
	}

	static array<ref LootEntry> GetBrickbuilding01MedicalItems()
	{
		return GetTownE2I02MedicalItems();
	}
}
