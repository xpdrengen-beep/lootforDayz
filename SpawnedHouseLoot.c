class SpawnedHouseLoot
{
	vector HousePosition;
	ref array<IEntity> Items = {};

	bool IsSpawned = false;

	// Time when loot was last deleted
	int LastDespawnTime = 0;
	int LastPlayerNearbyTime = 0;
}