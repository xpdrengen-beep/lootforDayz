class LootServerConfigItem : JsonApiStruct
{
	string Prefab;
	float Weight;

	void LootServerConfigItem()
	{
		RegV("Prefab");
		RegV("Weight");
	}
}

class LootServerConfigCategory : JsonApiStruct
{
	string Category;
	ref array<ref LootServerConfigItem> Items = new array<ref LootServerConfigItem>();

	void LootServerConfigCategory()
	{
		RegV("Category");
		RegV("Items");
	}
}

class LootServerConfigFile : JsonApiStruct
{
	bool Enabled = false;
	bool DebugLogging = false;
	int CheckIntervalMs = 5000;
	float SpawnDistance = 100.0;
	float DespawnDistance = 130.0;
	float MinSpawnDistance = 30.0;
	int MaxActiveLootItems = 4000;
	int RespawnCooldownMs = 0;
	int EmptyAreaDespawnMs = 10800000;
	int RecountIntervalMs = 60000;
	int InactiveHousePruneMs = 3600000;
	int MaxHousesToSpawnPerFlush = 0;
	ref array<ref LootServerConfigCategory> Categories = new array<ref LootServerConfigCategory>();

	void LootServerConfigFile()
	{
		RegV("Enabled");
		RegV("DebugLogging");
		RegV("CheckIntervalMs");
		RegV("SpawnDistance");
		RegV("DespawnDistance");
		RegV("MinSpawnDistance");
		RegV("MaxActiveLootItems");
		RegV("RespawnCooldownMs");
		RegV("EmptyAreaDespawnMs");
		RegV("RecountIntervalMs");
		RegV("InactiveHousePruneMs");
		RegV("MaxHousesToSpawnPerFlush");
		RegV("Categories");
	}
}

class LootServerConfigManager
{
	static string CONFIG_DIR = "$profile:LootForDayZ";
	static string CONFIG_PATH = "$profile:LootForDayZ/LootTables.json";

	static bool Loaded = false;
	static bool Enabled = false;
	static ref map<string, ref array<ref LootEntry>> CategoryTables = new map<string, ref array<ref LootEntry>>();

	static void Load()
	{
		if (Loaded)
			return;

		Loaded = true;
		CategoryTables.Clear();

		if (!FileIO.FileExists(CONFIG_PATH))
		{
			CreateDefaultConfigFile();
			Print("[Loot] Created default loot config at: " + CONFIG_PATH);
			return;
		}

		LootServerConfigFile config = new LootServerConfigFile();

		if (!config.LoadFromFile(CONFIG_PATH))
		{
			Print("[Loot] Failed to load loot config, using hardcoded loot tables: " + CONFIG_PATH);
			return;
		}

		ApplyRuntimeSettings(config);

		Enabled = config.Enabled;

		if (!Enabled)
		{
			Print("[Loot] Loot config is disabled, using hardcoded loot tables.");
			return;
		}

		foreach (LootServerConfigCategory categoryConfig : config.Categories)
		{
			if (!categoryConfig || categoryConfig.Category == "")
				continue;

			array<ref LootEntry> entries = new array<ref LootEntry>();

			foreach (LootServerConfigItem itemConfig : categoryConfig.Items)
			{
				if (!itemConfig || itemConfig.Prefab == "" || itemConfig.Weight <= 0)
					continue;

				entries.Insert(new LootEntry(itemConfig.Prefab, itemConfig.Weight));
			}

			if (entries.Count() == 0)
				continue;

			CategoryTables.Insert(categoryConfig.Category, entries);
		}

		Print("[Loot] Loaded server loot config categories: " + CategoryTables.Count());
	}

	static array<ref LootEntry> GetLootTable(string category, array<ref LootEntry> fallbackTable, string houseType = "")
	{
		Load();

		if (!Enabled || category == "")
			return fallbackTable;

		array<ref LootEntry> configuredTable = null;

		if (houseType != "")
			configuredTable = CategoryTables.Get(houseType + "." + category);

		if (!configuredTable || configuredTable.Count() == 0)
			configuredTable = CategoryTables.Get(category);

		if (!configuredTable || configuredTable.Count() == 0)
			return fallbackTable;

		return configuredTable;
	}

	static void ApplyRuntimeSettings(LootServerConfigFile config)
	{
		if (!config)
			return;

		LootSpawner.DEBUG_LOGGING = config.DebugLogging;

		if (config.CheckIntervalMs > 0)
			DynamicLootManager.CHECK_INTERVAL_MS = config.CheckIntervalMs;

		if (config.SpawnDistance > 0)
			DynamicLootManager.SPAWN_DISTANCE = config.SpawnDistance;

		if (config.DespawnDistance > 0)
			DynamicLootManager.DESPAWN_DISTANCE = config.DespawnDistance;

		if (config.MinSpawnDistance >= 0)
			DynamicLootManager.MIN_SPAWN_DISTANCE = config.MinSpawnDistance;

		if (config.MaxActiveLootItems >= 0)
			DynamicLootManager.MAX_ACTIVE_LOOT_ITEMS = config.MaxActiveLootItems;

		if (config.RespawnCooldownMs >= 0)
			DynamicLootManager.RESPAWN_COOLDOWN_MS = config.RespawnCooldownMs;

		if (config.EmptyAreaDespawnMs >= 0)
			DynamicLootManager.EMPTY_AREA_DESPAWN_MS = config.EmptyAreaDespawnMs;

		if (config.RecountIntervalMs > 0)
			DynamicLootManager.RECOUNT_INTERVAL_MS = config.RecountIntervalMs;

		if (config.InactiveHousePruneMs >= 0)
			DynamicLootManager.INACTIVE_HOUSE_PRUNE_MS = config.InactiveHousePruneMs;

		if (config.MaxHousesToSpawnPerFlush >= 0)
			LootSpawner.MAX_HOUSES_TO_SPAWN_PER_FLUSH = config.MaxHousesToSpawnPerFlush;
	}

	static void CreateDefaultConfigFile()
	{
		FileIO.MakeDirectory(CONFIG_DIR);

		LootServerConfigFile config = new LootServerConfigFile();
		config.Enabled = false;

		AddDefaultCategory(config, "BED", "{4B57C11AA5161760}Prefabs/Characters/Vests/Vest_PASGT/Vest_PASGT.et", 60);
		AddDefaultCategory(config, "KITCHEN", "{128A19AA9F731095}Prefabs/Items/Food/MeatLeg_01.et", 65);
		AddDefaultCategory(config, "HOUSE06.KITCHEN", "{128A19AA9F731095}Prefabs/Items/Food/MeatLeg_01.et", 65);
		AddDefaultCategory(config, "WEAPON", "{C1B4F7B87B720EE8}Prefabs/Weapons/Rifles/Mosin/BC_Rifle_Mosin_Nagant_9130.et", 15);
		AddDefaultCategory(config, "MEDICAL", "{AC298BA8A7D27007}Prefabs/Items/Equipment/Backpacks/Backpack_Medical_Soviet_NoCross_01.et", 100);

		config.PackToFile(CONFIG_PATH);
	}

	static void AddDefaultCategory(LootServerConfigFile config, string category, string prefab, float weight)
	{
		LootServerConfigCategory categoryConfig = new LootServerConfigCategory();
		categoryConfig.Category = category;

		LootServerConfigItem itemConfig = new LootServerConfigItem();
		itemConfig.Prefab = prefab;
		itemConfig.Weight = weight;

		categoryConfig.Items.Insert(itemConfig);
		config.Categories.Insert(categoryConfig);
	}
}
