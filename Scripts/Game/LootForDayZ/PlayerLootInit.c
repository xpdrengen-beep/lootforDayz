modded class SCR_ChimeraCharacter
{
	override void EOnInit(IEntity owner)
	{
		super.EOnInit(owner);

		Print("PLAYER INIT");

		GetGame().GetCallqueue().CallLater(StartLootSystem, 3000, false);
	}

	void StartLootSystem()
	{
		Print("STARTING DYNAMIC LOOT");
		DynamicLootManager.Start();
	}
}