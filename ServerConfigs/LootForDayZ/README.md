# LootForDayZ server loot config

Use `LootTables.example.json` as a template for the server file:

```text
$profile:LootForDayZ/LootTables.json
```

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


## Runtime / performance settings

The JSON file can also tune the dynamic loot manager without rebuilding the addon:

```json
{
  "DebugLogging": false,
  "CheckIntervalMs": 5000,
  "SpawnDistance": 100.0,
  "DespawnDistance": 130.0,
  "MinSpawnDistance": 30.0,
  "MaxActiveLootItems": 4000,
  "RespawnCooldownMs": 0,
  "EmptyAreaDespawnMs": 10800000,
  "RecountIntervalMs": 60000,
  "InactiveHousePruneMs": 3600000,
  "MaxHousesToSpawnPerFlush": 0
}
```

Notes:

- `DebugLogging` controls verbose spawn/despawn logging. Failed prefab loads are still printed.
- `RecountIntervalMs` controls how often the active loot counter is rebuilt as a safety check. Spawn/despawn still updates the counter immediately.
- `InactiveHousePruneMs` removes old inactive house records after despawn so long-running servers do not keep every visited house forever. Set to `0` to disable pruning.
- `MaxHousesToSpawnPerFlush` limits how many queued houses can spawn in one manager tick. The default `0` keeps the old behavior and processes the full queue, so loot availability is unchanged unless server owners opt in to spawn budgeting.

Recommended high-pop starting point:

```json
{
  "DebugLogging": false,
  "MaxActiveLootItems": 2500,
  "RespawnCooldownMs": 1800000,
  "EmptyAreaDespawnMs": 1800000,
  "MaxHousesToSpawnPerFlush": 8
}
```

## Current house type names

Use these names before the dot for house-specific tables:

```text
FARMHOUSEE1L01
FARMHOUSEE1L01_GREEN
FARMHOUSEE1L01_WOOD
BRICKBUILDING01
APARTMENTBUILDINGUSSR2I02_GREEN
APARTMENTBUILDINGUSSR2I02_YELLOW
HOUSE2FLOORS01
HOUSEVILLAGEE1I04S
HOUSEVILLAGEE1I05S
HOUSEVILLAGEE1I05T
HOUSEVILLAGEE1I06
HOUSEWOODE1I01_P
HOUSEWOODE1I01
HOUSEWOODE1I03
HOUSETOWNE2I01
HOUSETOWNE2I01_ORANGE
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

`HOUSEVILLAGEE1I04S` also covers the `House_Village_E_1I04t`, `House_Village_E_1I04sr`, and `House_Village_E_1I04sf` replica/color prefabs because they share the same interior loot coordinates.

Examples:

```text
FARMHOUSEE1L01.WEAPON
FARMHOUSEE1L01_GREEN.KITCHEN
BRICKBUILDING01.WEAPON
APARTMENTBUILDINGUSSR2I02_GREEN.MEDICAL
APARTMENTBUILDINGUSSR2I02_YELLOW.WEAPON
HOUSE2FLOORS01.KITCHEN
HOUSEVILLAGEE1I04S.KITCHEN
HOUSEVILLAGEE1I04S.WEAPON
HOUSEVILLAGEE1I05S.KITCHEN
HOUSEVILLAGEE1I05T.WEAPON
HOUSEVILLAGEE1I06.KITCHEN
HOUSETOWNE2I01.KITCHEN
HOUSETOWNE2I01_ORANGE.WEAPON
HOUSE08.WEAPON
HOUSE07.BED
HOUSE06.KITCHEN
HOUSE05_02.MEDICAL
```

## Workbench zombie zones

The zombie scripts live under:

```text
Scripts/Game/zmLootFordayz
```

The first zombie prototype uses Workbench-placed zone entities instead of JSON
coordinates. Zones automatically try multiple random positions and reject spots
that are too close to players or nearby objects.

1. Create/place an entity using the `LFZ_ZombieZoneEntity` script class.
2. Put the entity at the center of the town, village, or military area.
3. Set `ZoneName` to a unique readable name.
4. Set `ZoneType` to `Village`, `Town`, or `Military`.
5. Set `Radius` to the playable zombie area size.
6. Set `ZombiePrefab` to an unarmed standard character prefab while the zombie
   behaviour is still being prototyped.
7. Optional: override `MinZombies`, `MaxZombies`, `RespawnCooldownMs`,
   `ObjectClearanceRadius`, and `SpawnPositionAttempts` per zone. Leave zombie
   counts at `0` to use the defaults below.
8. Optional fallback only: set `UseSpawnPoints` to true if a special zone should
   prefer manual `LFZ_ZombieSpawnPointEntity` positions before automatic random
   positions.

Default zone difficulty values:

```text
Village:  3-6 zombies
Town:     5-10 zombies
Military: 8-14 zombies
```

Runtime manager defaults:

```text
CheckIntervalMs:      5000
MinSpawnDistance:    45.0
DespawnDistance:     350.0
EmptyAreaDespawnMs:  900000
MaxActiveZombies:    120
SpawnPositionAttempts: 48
```

The manager only evaluates registered `LFZ_ZombieZoneEntity` instances on the
server. A zone becomes active when a player is inside `Radius + ActivationBuffer`.
Zombies spawn automatically at random positions inside the zone radius. Each
zone tries up to `SpawnPositionAttempts` candidates, and individual attempts are
skipped when the selected position is too close to a player or when the
`ObjectClearanceRadius` sphere overlaps another render/object entity. Set
`ObjectClearanceRadius` to `0` on a zone if object checks are too conservative
for clutter-heavy areas.

### Automatic object-aware spawning

Manual spawn points are not required. By default, the spawner ignores registered
`LFZ_ZombieSpawnPointEntity` instances and uses automatic random placement inside
the zone. Automatic placement works like this:

1. pick a random candidate inside the zone radius;
2. reject it if a player is inside `MinSpawnDistance`;
3. reject it if a `QueryEntitiesBySphere` object query hits a render/object
   entity inside `ObjectClearanceRadius`;
4. retry until `SpawnPositionAttempts` is reached.

For dense towns, increase `SpawnPositionAttempts` before adding manual points.
Manual `LFZ_ZombieSpawnPointEntity` positions are now a special-case fallback:
set `UseSpawnPoints` to true on a zone only if a hand-authored area needs exact
spawn spots.

### Object-aware zombie spawning

The script performs a lightweight runtime object check before spawning each
zombie. For every automatic random candidate position, `ZombieSpawner` checks:

1. the position is not inside `MinSpawnDistance` of any player; and
2. a sphere query around the candidate does not hit a render/object entity inside
   the zone's `ObjectClearanceRadius`.

This prevents many bad spawns inside placed props, buildings, fences, vehicles,
and other runtime entities. It is not a full replacement for navmesh generation:
large buildings can still have origins or collision bounds that do not perfectly
match their walkable/blocked space, and AI movement still depends on a valid
`SCR_AIWorld` plus `Soldiers` navmesh. For the most reliable DayZ-like infected
setup, use all three together: valid navmesh, object clearance, and carefully
placed zombie zones.

### Target worlds without `SCR_AIWorld`

Zombie zones require the target world to have an AI world/navmesh setup. If the
world you are building on does not already contain `SCR_AIWorld`, the zombie
manager can still spawn character prefabs, but normal AI navigation will not work
until the world has a valid `SCR_AIWorld` entity with `NavmeshWorldComponent`
configuration.

Recommended Workbench setup for a world that is not yours:

1. Create a modded/inherited version or editable layer of the target world in
   your project; do not edit the original dependency directly.
2. Add the `SCR_AIWorld.et` prefab to the world's default/editable layer. Only
   one AI world should exist per loaded world.
3. Configure the first `NavmeshWorldComponent` for `Soldiers`; this is the
   navmesh project used by on-foot AI such as the first zombie prototypes.
4. Create or assign the `Soldiers` navmesh file/config (`.nmn` through a
   navmesh files config).
5. Generate and save a navmesh for the areas where zombies should walk. For
   small custom maps, full generation can be acceptable; for large dependency
   maps, generate only the changed/needed area and ship that navmesh data in
   your modded world setup.
6. Reload the world and verify the `Soldiers` navmesh is visible under your
   zombie zones before testing zombie movement in-game.

If you cannot add `SCR_AIWorld` or a `Soldiers` navmesh to the loaded world, the
current zombie system should be treated as spawn/despawn-only for that world; the
spawned characters will not have reliable pathfinding for DayZ-like infected
behaviour.
