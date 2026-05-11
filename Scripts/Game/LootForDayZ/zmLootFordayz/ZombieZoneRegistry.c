class LFZ_ZombieZoneRegistry
{
	static ref array<LFZ_ZombieZoneEntity> Zones = new array<LFZ_ZombieZoneEntity>();
	static ref array<LFZ_ZombieSpawnPointEntity> SpawnPoints = new array<LFZ_ZombieSpawnPointEntity>();

	static void RegisterZone(LFZ_ZombieZoneEntity zone)
	{
		if (!zone)
			return;

		if (Zones.Find(zone) >= 0)
			return;

		Zones.Insert(zone);
		ZombieSpawner.DebugPrint("[Zombies] Registered zone: " + zone.GetDisplayName());
	}

	static void UnregisterZone(LFZ_ZombieZoneEntity zone)
	{
		if (!zone)
			return;

		int index = Zones.Find(zone);

		if (index < 0)
			return;

		Zones.Remove(index);
		ZombieSpawner.DebugPrint("[Zombies] Unregistered zone: " + zone.GetDisplayName());
	}

	static array<LFZ_ZombieZoneEntity> GetZones()
	{
		return Zones;
	}

	static void RegisterSpawnPoint(LFZ_ZombieSpawnPointEntity spawnPoint)
	{
		if (!spawnPoint)
			return;

		if (SpawnPoints.Find(spawnPoint) >= 0)
			return;

		SpawnPoints.Insert(spawnPoint);
		ZombieSpawner.DebugPrint("[Zombies] Registered spawn point: " + spawnPoint.GetDisplayName());
	}

	static void UnregisterSpawnPoint(LFZ_ZombieSpawnPointEntity spawnPoint)
	{
		if (!spawnPoint)
			return;

		int index = SpawnPoints.Find(spawnPoint);

		if (index < 0)
			return;

		SpawnPoints.Remove(index);
		ZombieSpawner.DebugPrint("[Zombies] Unregistered spawn point: " + spawnPoint.GetDisplayName());
	}

	static array<LFZ_ZombieSpawnPointEntity> GetSpawnPoints()
	{
		return SpawnPoints;
	}
}
