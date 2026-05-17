class LFZ_ZombieAnimControllerComponentClass : ScriptComponentClass
{
}

class LFZ_ZombieAnimControllerComponent : ScriptComponent
{
	[Attribute("0", UIWidgets.CheckBox, "If enabled, StartAttack/StartHit/StartScream automatically calls the matching Finish method after the configured duration. Use animation events later for exact timing.")]
	bool UseFallbackTimers;

	[Attribute("1000", UIWidgets.EditBox, "Fallback attack duration in milliseconds. Only used when UseFallbackTimers is enabled.")]
	int AttackDurationMs;

	[Attribute("600", UIWidgets.EditBox, "Fallback hit reaction duration in milliseconds. Only used when UseFallbackTimers is enabled.")]
	int HitDurationMs;

	[Attribute("1300", UIWidgets.EditBox, "Fallback scream duration in milliseconds. Only used when UseFallbackTimers is enabled.")]
	int ScreamDurationMs;

	protected CharacterAnimGraphComponent m_AnimGraph;
	protected bool m_IsBound;

	protected int m_iDoScream;
	protected int m_iScreamDone;
	protected int m_iGoWalk;
	protected int m_iSpeed;
	protected int m_iDoAttack;
	protected int m_iAttackDone;
	protected int m_iIsDead;
	protected int m_iWasHit;
	protected int m_iHitDone;

	override void OnPostInit(IEntity owner)
	{
		BindAnimationGraph(owner);
		ResetAnimationState();
	}

	protected void BindAnimationGraph(IEntity owner)
	{
		if (!owner)
			return;

		m_AnimGraph = CharacterAnimGraphComponent.Cast(owner.FindComponent(CharacterAnimGraphComponent));

		if (!m_AnimGraph)
		{
			Print("[LFZ Zombies] Missing CharacterAnimGraphComponent on zombie prefab. Add it before using LFZ_ZombieAnimControllerComponent.", LogLevel.WARNING);
			return;
		}

		m_iDoScream = m_AnimGraph.BindBoolVariable("DoScream");
		m_iScreamDone = m_AnimGraph.BindBoolVariable("ScreamDone");
		m_iGoWalk = m_AnimGraph.BindBoolVariable("GoWalk");
		m_iSpeed = m_AnimGraph.BindFloatVariable("Speed");
		m_iDoAttack = m_AnimGraph.BindBoolVariable("DoAttack");
		m_iAttackDone = m_AnimGraph.BindBoolVariable("AttackDone");
		m_iIsDead = m_AnimGraph.BindBoolVariable("IsDead");
		m_iWasHit = m_AnimGraph.BindBoolVariable("WasHit");
		m_iHitDone = m_AnimGraph.BindBoolVariable("HitDone");
		m_IsBound = true;
	}

	bool IsReady()
	{
		return m_IsBound && m_AnimGraph != null;
	}

	void ResetAnimationState()
	{
		if (!IsReady())
			return;

		m_AnimGraph.SetBoolVariable(m_iDoScream, false);
		m_AnimGraph.SetBoolVariable(m_iScreamDone, false);
		m_AnimGraph.SetBoolVariable(m_iGoWalk, false);
		m_AnimGraph.SetFloatVariable(m_iSpeed, 0.0);
		m_AnimGraph.SetBoolVariable(m_iDoAttack, false);
		m_AnimGraph.SetBoolVariable(m_iAttackDone, false);
		m_AnimGraph.SetBoolVariable(m_iIsDead, false);
		m_AnimGraph.SetBoolVariable(m_iWasHit, false);
		m_AnimGraph.SetBoolVariable(m_iHitDone, false);
	}

	void SetMovement(float speed, bool goWalk)
	{
		if (!IsReady())
			return;

		m_AnimGraph.SetFloatVariable(m_iSpeed, speed);
		m_AnimGraph.SetBoolVariable(m_iGoWalk, goWalk);
	}

	void StartAttack()
	{
		if (!IsReady())
			return;

		m_AnimGraph.SetBoolVariable(m_iAttackDone, false);
		m_AnimGraph.SetBoolVariable(m_iDoAttack, true);

		if (UseFallbackTimers)
			GetGame().GetCallqueue().CallLater(FinishAttack, GetSafeDuration(AttackDurationMs), false);
	}

	void FinishAttack()
	{
		if (!IsReady())
			return;

		m_AnimGraph.SetBoolVariable(m_iDoAttack, false);
		m_AnimGraph.SetBoolVariable(m_iAttackDone, true);
	}

	void StartHit()
	{
		if (!IsReady())
			return;

		m_AnimGraph.SetBoolVariable(m_iHitDone, false);
		m_AnimGraph.SetBoolVariable(m_iWasHit, true);

		if (UseFallbackTimers)
			GetGame().GetCallqueue().CallLater(FinishHit, GetSafeDuration(HitDurationMs), false);
	}

	void FinishHit()
	{
		if (!IsReady())
			return;

		m_AnimGraph.SetBoolVariable(m_iWasHit, false);
		m_AnimGraph.SetBoolVariable(m_iHitDone, true);
	}

	void StartScream()
	{
		if (!IsReady())
			return;

		m_AnimGraph.SetBoolVariable(m_iScreamDone, false);
		m_AnimGraph.SetBoolVariable(m_iDoScream, true);

		if (UseFallbackTimers)
			GetGame().GetCallqueue().CallLater(FinishScream, GetSafeDuration(ScreamDurationMs), false);
	}

	void FinishScream()
	{
		if (!IsReady())
			return;

		m_AnimGraph.SetBoolVariable(m_iDoScream, false);
		m_AnimGraph.SetBoolVariable(m_iScreamDone, true);
	}

	void Die()
	{
		SetDead(true);
	}

	void SetDead(bool isDead)
	{
		if (!IsReady())
			return;

		m_AnimGraph.SetBoolVariable(m_iIsDead, isDead);

		if (!isDead)
			return;

		m_AnimGraph.SetBoolVariable(m_iDoAttack, false);
		m_AnimGraph.SetBoolVariable(m_iAttackDone, false);
		m_AnimGraph.SetBoolVariable(m_iWasHit, false);
		m_AnimGraph.SetBoolVariable(m_iHitDone, false);
		m_AnimGraph.SetBoolVariable(m_iDoScream, false);
		m_AnimGraph.SetBoolVariable(m_iScreamDone, false);
		m_AnimGraph.SetBoolVariable(m_iGoWalk, false);
		m_AnimGraph.SetFloatVariable(m_iSpeed, 0.0);
	}

	protected int GetSafeDuration(int durationMs)
	{
		if (durationMs < 1)
			return 1;

		return durationMs;
	}
}
