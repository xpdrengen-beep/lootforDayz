class DynamicLootManager
{
	static bool Started = false;

	static int CHECK_INTERVAL_MS = 5000;
	static float SPAWN_DISTANCE = 100.0;
	static float DESPAWN_DISTANCE = 130.0;
	static float MIN_SPAWN_DISTANCE = 30.0;

	static int MAX_ACTIVE_LOOT_ITEMS = 4000;
	static int RESPAWN_COOLDOWN_MS = 0;
	static int EMPTY_AREA_DESPAWN_MS = 10800000;
	static int RECOUNT_INTERVAL_MS = 60000;
	static int INACTIVE_HOUSE_PRUNE_MS = 3600000;

	static ref array<vector> CurrentPlayerPositions = new array<vector>();
	static int LastRecountTime = 0;

	static void Start()
	{
		GetGame().GetCallqueue().Remove(CheckPlayers);

		if (!Started)
		{
			Started = true;
			Print("[Loot] Dynamic loot manager started.");
			LootServerConfigManager.Load();
		}
		else
		{
			Print("[Loot] Dynamic loot manager scheduler refreshed.");
		}

		GetGame().GetCallqueue().CallLater(CheckPlayers, CHECK_INTERVAL_MS, true);
		GetGame().GetCallqueue().CallLater(CheckPlayers, 1000, false);
	}

	static void CheckPlayers()
	{
		LootSpawner.ClearQueuedHouses();

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

		CurrentPlayerPositions.Clear();

		foreach (vector playerPos : playerPositions)
			CurrentPlayerPositions.Insert(playerPos);

		MaybeRecountActiveLootItemCount();

		LootSpawner.FlushQueuedHouses();
		CheckDespawn(playerPositions);
		LootSpawner.PruneInactiveHouses(playerPositions);
		LootSpawner.EnforceLootCap(playerPositions);
	}

	static void MaybeRecountActiveLootItemCount()
	{
		int currentTime = System.GetTickCount();

		if (LastRecountTime > 0 && currentTime - LastRecountTime < RECOUNT_INTERVAL_MS)
			return;

		LastRecountTime = currentTime;
		LootSpawner.RecountActiveLootItemCount();
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

			if (IsAnyPlayerNearPosition(data.HousePosition, playerPositions, DESPAWN_DISTANCE))
			{
				data.LastPlayerNearbyTime = currentTime;
				continue;
			}

			if (data.LastPlayerNearbyTime <= 0)
				data.LastPlayerNearbyTime = currentTime;

			if (currentTime - data.LastPlayerNearbyTime < EMPTY_AREA_DESPAWN_MS)
				continue;

			LootSpawner.DespawnHouseLoot(key, data);
		}
	}

	static bool IsAnyPlayerNearPosition(vector position, array<vector> playerPositions, float distance)
	{
		foreach (vector playerPos : playerPositions)
		{
			if (vector.Distance(playerPos, position) <= distance)
				return true;
		}

		return false;
	}
}