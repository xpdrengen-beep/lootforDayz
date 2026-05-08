class LootEntry
{
	string Prefab;
	float Weight;

	void LootEntry(string prefab, float weight)
	{
		Prefab = prefab;
		Weight = weight;
	}
}