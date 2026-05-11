class LFZ_ZombieZoneEntityClass : GenericEntityClass
{
}

class LFZ_ZombieZoneEntity : GenericEntity
{
	[Attribute("ZombieZone", UIWidgets.EditBox, "Unique zone name shown in logs.")]
	string ZoneName;

	[Attribute("Village", UIWidgets.ComboBox, "Zone difficulty/type. Supported values: Village, Town, Military.", "Village Town Military")]
	string ZoneType;

	[Attribute("180", UIWidgets.EditBox, "Radius around this entity where zombies can spawn.")]
	float Radius;

	[Attribute("0", UIWidgets.EditBox, "Optional override. 0 uses defaults for ZoneType.")]
	int MinZombies;

	[Attribute("0", UIWidgets.EditBox, "Optional override. 0 uses defaults for ZoneType.")]
	int MaxZombies;

	[Attribute("900000", UIWidgets.EditBox, "Respawn cooldown after the zone despawns, in milliseconds.")]
	int RespawnCooldownMs;

	[Attribute("", UIWidgets.EditBox, "Character prefab to spawn for this zone. Use an unarmed standard character prefab for the first prototype.")]
	ResourceName ZombiePrefab;

	[Attribute("60", UIWidgets.EditBox, "How far from the zone center a player must be before this zone may spawn zombies.")]
	float ActivationBuffer;

	[Attribute("1.5", UIWidgets.EditBox, "Minimum object/entity clearance around each random zombie spawn position. Set to 0 to disable object checks.")]
	float ObjectClearanceRadius;

	[Attribute("48", UIWidgets.EditBox, "How many automatic random positions the spawner should test before giving up.")]
	int SpawnPositionAttempts;

	[Attribute("0", UIWidgets.EditBox, "Set to true only if this zone should use manual LFZ_ZombieSpawnPointEntity points before automatic random positions.")]
	bool UseSpawnPoints;

	void LFZ_ZombieZoneEntity(IEntitySource src, IEntity parent)
	{
		SetEventMask(EntityEvent.INIT);
	}

	override void EOnInit(IEntity owner)
	{
		if (Replication.IsRunning() && !Replication.IsServer())
			return;

		LFZ_ZombieZoneRegistry.RegisterZone(this);
	}

	void ~LFZ_ZombieZoneEntity()
	{
		if (Replication.IsRunning() && !Replication.IsServer())
			return;

		LFZ_ZombieZoneRegistry.UnregisterZone(this);
	}

	string GetZoneKey()
	{
		return ToString();
	}

	string GetDisplayName()
	{
		if (ZoneName != "")
			return ZoneName;

		return GetZoneKey();
	}

	float GetEffectiveRadius()
	{
		if (Radius > 0)
			return Radius;

		return 180.0;
	}

	float GetActivationDistance()
	{
		float buffer = ActivationBuffer;

		if (buffer < 0)
			buffer = 0;

		return GetEffectiveRadius() + buffer;
	}

	int GetEffectiveMinZombies()
	{
		if (MinZombies > 0)
			return MinZombies;

		if (ZoneType == "Military")
			return 8;

		if (ZoneType == "Town")
			return 5;

		return 3;
	}

	int GetEffectiveMaxZombies()
	{
		if (MaxZombies > 0)
			return MaxZombies;

		if (ZoneType == "Military")
			return 14;

		if (ZoneType == "Town")
			return 10;

		return 6;
	}

	int GetEffectiveRespawnCooldownMs()
	{
		if (RespawnCooldownMs >= 0)
			return RespawnCooldownMs;

		return 900000;
	}

	float GetEffectiveObjectClearanceRadius()
	{
		if (ObjectClearanceRadius < 0)
			return 0.0;

		return ObjectClearanceRadius;
	}

	int GetEffectiveSpawnPositionAttempts()
	{
		if (SpawnPositionAttempts > 0)
			return SpawnPositionAttempts;

		return 48;
	}

	bool ShouldUseSpawnPoints()
	{
		return UseSpawnPoints;
	}
}
