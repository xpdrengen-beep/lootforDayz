# LootForDayZ server loot config

Use `LootTables.example.json` as a template for the server file:

```text
$profile:LootForDayZ/LootTables.json
```

## Important

JSON does not support real comments. The example file therefore uses safe README/example categories such as:

```json
{ "Category": "__README_WEIGHT_IS_RARITY_HIGHER_WEIGHT_MEANS_MORE_COMMON__", "Items": [] }
```

Empty `Items` categories are ignored by the addon loader.

## Enable the file

Set:

```json
"Enabled": true
```

If `Enabled` is `false`, the addon uses the hardcoded tables in `LootTables.c`.

## Add loot for all houses in a category

Use a normal category name:

```json
{
  "Category": "KITCHEN",
  "Items": [
    {
      "Prefab": "{128A19AA9F731095}Prefabs/Items/Food/MeatLeg_01.et",
      "Weight": 100
    }
  ]
}
```

This applies to every house that asks for `KITCHEN` loot unless that house has a more specific override.

## Add loot for one house only

Use this format:

```text
HOUSE_TYPE.CATEGORY
```

Example:

```json
{
  "Category": "HOUSE06.KITCHEN",
  "Items": [
    {
      "Prefab": "{128A19AA9F731095}Prefabs/Items/Food/MeatLeg_01.et",
      "Weight": 100
    }
  ]
}
```

This only applies to `HOUSE06` kitchen loot.

## Lookup order

When a house spawns loot, the addon checks tables in this order:

```text
1. HOUSE_TYPE.CATEGORY from JSON
2. CATEGORY from JSON
3. hardcoded LootTables.c fallback
```

Example for House06 kitchen loot:

```text
HOUSE06.KITCHEN
KITCHEN
LootTables.c fallback
```

## Weight / rarity

`Weight` is rarity. Higher weight means more common.

Example:

```json
{
  "Category": "WEAPON",
  "Items": [
    { "Prefab": "CommonGun.et", "Weight": 100 },
    { "Prefab": "RareGun.et", "Weight": 5 }
  ]
}
```

The common gun is much more likely than the rare gun. Weight does not control how many items spawn; house spawn chances control item amount.

## Current house type names

Use these names before the dot for house-specific tables:

```text
HOUSEWOODE1I01_P
HOUSEWOODE1I01
HOUSEWOODE1I03
HOUSETOWNE2I02Y
HOUSETOWNE2I02V2
HOUSETOWNE2I02B
HOUSETOWNE2I02
HOUSERAG
HOUSE08
HOUSE07
HOUSE06
HOUSE05
HOUSE05_02
HOUSE03
HOUSE02
```

Examples:

```text
HOUSE08.WEAPON
HOUSE07.BED
HOUSE06.KITCHEN
HOUSE05_02.MEDICAL
```
