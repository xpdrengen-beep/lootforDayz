class DynamicLootManager
{
	static bool Started = false;

	static float CHECK_INTERVAL_MS = 5000;
	static float SPAWN_DISTANCE = 100.0;
	static float DESPAWN_DISTANCE = 130.0;
	static float MIN_SPAWN_DISTANCE = 30.0;

	static int RESPAWN_COOLDOWN_MS = 60000;       // 10 minutes
	static int EMPTY_AREA_DESPAWN_MS = 60000;   // 3 hours

	static void Start()
	{
		if (Started)
			return;

		Started = true;

		Print("[Loot] Dynamic loot manager started.");

		CheckPlayers();

		GetGame().GetCallqueue().CallLater(CheckPlayers, 5000, true);
	}

	static void CheckPlayers()
	{
		array<vector> playerPositions = {};

		array<int> players = {};
		GetGame().GetPlayerManager().GetPlayers(players);

		foreach (int playerId : players)
		{
			IEntity player = GetGame().GetPlayerManager().GetPlayerControlledEntity(playerId);

			if (!player)
				continue;

			vector playerPos = player.GetOrigin();
			playerPositions.Insert(playerPos);

			GetGame().GetWorld().QueryEntitiesBySphere(
				playerPos,
				SPAWN_DISTANCE,
				LootSpawner.HouseCallback
			);
		}

		CheckDespawn(playerPositions);
	}

	static bool IsAnyPlayerTooClose(vector housePos)
	{
		array<int> players = {};
		GetGame().GetPlayerManager().GetPlayers(players);

		foreach (int playerId : players)
		{
			IEntity player = GetGame().GetPlayerManager().GetPlayerControlledEntity(playerId);

			if (!player)
				continue;

			if (vector.Distance(player.GetOrigin(), housePos) < MIN_SPAWN_DISTANCE)
				return true;
		}

		return false;
	}

	static void CheckDespawn(array<vector> playerPositions)
	{
		int currentTime = System.GetTickCount();

		foreach (string key, SpawnedHouseLoot data : LootSpawner.ActiveHouses)
		{
			if (!data || !data.IsSpawned)
				continue;

			bool playerNearby = false;

			foreach (vector playerPos : playerPositions)
			{
				if (vector.Distance(playerPos, data.HousePosition) <= DESPAWN_DISTANCE)
				{
					playerNearby = true;
					break;
				}
			}

			if (playerNearby)
			{
				data.LastPlayerNearbyTime = currentTime;
				continue;
			}

			if (data.LastPlayerNearbyTime <= 0)
				data.LastPlayerNearbyTime = currentTime;

			if (currentTime - data.LastPlayerNearbyTime < EMPTY_AREA_DESPAWN_MS)
				continue;

			Print("[Loot] Despawning loot for abandoned house: " + key);

			foreach (IEntity item : data.Items)
			{
				if (item)
					SCR_EntityHelper.DeleteEntityAndChildren(item);
			}

			data.Items.Clear();
			data.IsSpawned = false;
			data.LastDespawnTime = currentTime;
		}
	}
}