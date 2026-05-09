modded class SCR_ChimeraCharacter
{
	override void EOnInit(IEntity owner)
	{
		super.EOnInit(owner);

		GetGame().GetCallqueue().CallLater(StartLootSystem, 3000, false);
	}

	void StartLootSystem()
	{
		if (Replication.IsRunning() && !Replication.IsServer())
			return;

		LootSpawner.DebugPrint("STARTING DYNAMIC LOOT");
		DynamicLootManager.Start();
	}
}
