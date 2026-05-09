When adding new house loot spawn classes:
- Always group coordinates by loot category: BED, KITCHEN, WEAPON, MEDICAL, TOOL.
- TOOL spawn points should be stored but not spawned unless tool loot support is explicitly requested.
- Always tune SpawnWeightedFromArray chance values based on number of spawn points.
- Large houses with many points should use lower chances to avoid flooding the house with loot.
- Update ServerConfigs/LootForDayZ/README.md with every new HOUSE_TYPE key.
