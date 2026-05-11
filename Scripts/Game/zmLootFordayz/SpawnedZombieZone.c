class SpawnedZombieZone
{
	vector ZonePosition;
	ref array<IEntity> Zombies = {};

	bool IsSpawned = false;
	int LastDespawnTime = 0;
	int LastPlayerNearbyTime = 0;
}
