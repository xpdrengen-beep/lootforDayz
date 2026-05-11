class LFZ_ZombieSpawnPointEntityClass : GenericEntityClass
{
}

class LFZ_ZombieSpawnPointEntity : GenericEntity
{
	[Attribute("", UIWidgets.EditBox, "Optional zone name. If empty, this spawn point can be used by any zombie zone whose radius contains it.")]
	string ZoneName;

	[Attribute("1", UIWidgets.EditBox, "Set to false to temporarily disable this spawn point.")]
	bool Enabled;

	void LFZ_ZombieSpawnPointEntity(IEntitySource src, IEntity parent)
	{
		SetEventMask(EntityEvent.INIT);
	}

	override void EOnInit(IEntity owner)
	{
		if (Replication.IsRunning() && !Replication.IsServer())
			return;

		LFZ_ZombieZoneRegistry.RegisterSpawnPoint(this);
	}

	void ~LFZ_ZombieSpawnPointEntity()
	{
		if (Replication.IsRunning() && !Replication.IsServer())
			return;

		LFZ_ZombieZoneRegistry.UnregisterSpawnPoint(this);
	}

	bool CanBeUsedByZone(LFZ_ZombieZoneEntity zone)
	{
		if (!Enabled || !zone)
			return false;

		if (ZoneName != "")
			return ZoneName == zone.ZoneName;

		return vector.Distance(GetOrigin(), zone.GetOrigin()) <= zone.GetEffectiveRadius();
	}

	string GetDisplayName()
	{
		if (ZoneName != "")
			return ZoneName;

		return ToString();
	}
}
