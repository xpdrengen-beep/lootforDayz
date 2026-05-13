# Zombie Animation Graph Notes

Dette dokument samler den fungerende opsætning for `Zombie_Main.aw` i Enfusion Workbench / Animation Editor, så projektet kan fortsættes uden at skulle rekonstruere hele samtalen.

> Fokus: AI-zombier/infected, ikke spillerstyrede karakterer.

## Kilder og Workbench-regler

Brug Bohemias officielle Animation Editor-dokumentation som reference:

- Animation Editor: <https://community.bohemia.net/wiki/Arma_Reforger:Animation_Editor>
- Animation Editor State Machine: <https://community.bohemia.net/wiki/Arma_Reforger:Animation_Editor:_State_Machine>
- Animation Editor Nodes: <https://community.bohemia.net/wiki/Arma_Reforger:Animation_Editor:_Nodes>

Vigtige regler fra dokumentationen og vores test:

- Animation Graph afspilles fra default/root node i preview.
- En State Machine skal have states; en tom State Machine giver fejl.
- Hver State skal have et child/link til en node, fx en Source node.
- `Duration` på transitions skal skrives som decimal, fx `0.2`, `1.0`, `0.0`; undgå heltal som `0` og `1`.
- Source node-navne er case-sensitive.
- One-shot states som `Scream`, `Attack`, `Hit` og `Death` bør testes med `Time Storage = Normalized Time`, da `Scream` først virkede korrekt med denne indstilling.

## Nuværende workspace

Arbejdsfil:

```text
Zombie_Main.aw
Zombie_Main.asi
Zombie_Main.agr
```

Animation Set:

```text
Locomotion
├── Idle
├── Scream
├── Walk
└── Run

Combat
├── Attack
├── Hit
└── Death
```

## Source nodes

Nuværende/forventede source nodes:

```text
Src_Idle
Source: Locomotion.Normal.Idle
Looptype: Loop

SRC_Scream
Source: Locomotion.Normal.Scream
Looptype: Once / No Loop, eller Loop midlertidigt til debugging

SRC_Walk
Source: Locomotion.Normal.Walk
Looptype: Loop

Src_Run
Source: Locomotion.Normal.Run
Looptype: Loop
```

Kommende combat source nodes:

```text
SRC_Attack
Source: Combat.Normal.Attack
Looptype: Once / No Loop

SRC_Hit
Source: Combat.Normal.Hit
Looptype: Once / No Loop

SRC_Death
Source: Combat.Normal.Death
Looptype: Once / No Loop / Hold, afhængigt af tilgængelige muligheder
```

## Main State Machine

Brug én hovedgraph og én hoved-State Machine til første version:

```text
Graph: Zombie_Main.agr
State Machine: SM_ZombieMain
```

Nuværende states:

```text
Idle
Scream
Walk
Run
```

Kommende states:

```text
Attack
Hit
Death
```

State child mapping:

```text
Idle   -> Src_Idle
Scream -> SRC_Scream
Walk   -> SRC_Walk
Run    -> Src_Run
Attack -> SRC_Attack
Hit    -> SRC_Hit
Death  -> SRC_Death
```

## Test controls

Midlertidige editor-controls:

```text
DoScream : bool
GoWalk   : bool
Speed    : float
```

Fortolkning:

- `DoScream` er kun en midlertidig one-shot test-trigger. Den må ikke stå `true` permanent under normal test.
- `GoWalk` betyder i praksis `ScreamDone`; navnet er misvisende, fordi `Scream` kan gå til `Idle`, `Walk` eller `Run`.
- `Speed` er en normaliseret testværdi, hvor `0.0` er idle og `1.0` er run.

Fremtidig AI-logik bør hellere bruge noget i stil med:

```text
Alerted
HasScreamed
ScreamDone
MoveSpeed
DoAttack / AttackCommand
AttackDone
WasHit / HitCommand
HitDone
IsDead
```

## Fungerende locomotion transitions

Brug hysteresis/buffer, så graphen ikke flipper mellem states.

```text
Idle -> Walk
Condition: Speed > 0.1
Duration: 0.2
```

```text
Walk -> Idle
Condition: Speed <= 0.05
Duration: 0.2
```

```text
Walk -> Run
Condition: Speed > 0.75
Duration: 0.2
```

```text
Run -> Walk
Condition: Speed < 0.65
Duration: 0.2
```

Undgå overlappende regler som dette:

```text
Idle -> Walk: Speed > 0.1
Walk -> Idle: Speed <= 0.5
```

Ved `Speed = 0.3` er begge true, og det giver loop.

## Fungerende scream transitions

```text
Idle -> Scream
Condition: DoScream
Duration: 0.2
```

```text
Scream -> Idle
Condition: GoWalk && Speed <= 0.05
Duration: 0.2
```

```text
Scream -> Walk
Condition: GoWalk && Speed > 0.1 && Speed <= 0.75
Duration: 0.2
```

```text
Scream -> Run
Condition: GoWalk && Speed > 0.75
Duration: 0.2
```

`Scream` state-indstilling som virkede:

```text
Child: SRC_Scream
Time Storage: Normalized Time
Start Time: tom eller 0.0, afhængigt af hvad der virker bedst
Is Exit: false
Pass Through: false
```

## Gennemtestet normal flow

Følgende normaltests virkede:

```text
DoScream=false, GoWalk=false, Speed=0.0 -> Idle
Speed=0.2 -> Walk
Speed=0.6 -> Walk
Speed=1.0 -> Run
Speed=0.5 -> Walk
Speed=0.0 -> Idle
```

Scream-flow virkede:

```text
Idle -> Scream
Scream -> Idle
Scream -> Walk
Scream -> Run
```

Bad input-test fejlede forventeligt, fx:

```text
DoScream=true, GoWalk=true, Speed=0.0
```

Det kan give loop:

```text
Idle -> Scream -> Idle -> Scream ...
```

Dette er acceptabelt i editor-test, fordi `DoScream` er en test-bool. I et færdigt AI-setup bør scream styres af en one-shot command eller en gate som:

```text
Alerted && !HasScreamed
```

## Sådan bør Hit sættes op

`Hit` er en one-shot reaction state. Den skal kunne afbryde normal locomotion/scream/attack, men den skal ikke loope. Den bør efterfølgende vælge korrekt locomotion-state baseret på `Speed`.

### 1. Source node

Opret eller kontrollér:

```text
SRC_Hit
Source: Combat.Normal.Hit
Looptype: Once / No Loop
Interpolate: On
```

Test `SRC_Hit` alene først, før den kobles i State Machine.

### 2. State

Opret state i `SM_ZombieMain`:

```text
State: Hit
Child: SRC_Hit
Time Storage: Normalized Time
Start Time: tom eller 0.0
Is Exit: false
Pass Through: false
```

Brug `Normalized Time`, fordi `Hit` ligesom `Scream` er en one-shot state.

### 3. Test controls til Hit

Til editor-test:

```text
WasHit  : bool
HitDone : bool
```

`WasHit` bør behandles som one-shot trigger. Den må ikke stå `true` permanent, ellers kan graphen blive ved med at gå tilbage til `Hit`.

### 4. Indgange til Hit

Start med få transitions, ikke alle på én gang:

```text
Idle -> Hit
Condition: WasHit
Duration: 0.1
Priority: højere end locomotion/scream, hvis priority bruges
```

```text
Walk -> Hit
Condition: WasHit
Duration: 0.1
Priority: højere end locomotion
```

```text
Run -> Hit
Condition: WasHit
Duration: 0.1
Priority: højere end locomotion
```

Når det virker, kan du tilføje:

```text
Scream -> Hit
Condition: WasHit
Duration: 0.1
```

```text
Attack -> Hit
Condition: WasHit
Duration: 0.1
```

Beslut senere om `Hit` må afbryde `Attack`; nogle zombier bør færdiggøre attack, andre bør kunne staggeres.

### 5. Exits fra Hit

Brug samme ide som `Scream`: `Hit` skal ikke altid gå til Walk. Den skal vælge baseret på `Speed`.

```text
Hit -> Idle
Condition: HitDone && Speed <= 0.05
Duration: 0.2
```

```text
Hit -> Walk
Condition: HitDone && Speed > 0.1 && Speed <= 0.75
Duration: 0.2
```

```text
Hit -> Run
Condition: HitDone && Speed > 0.75
Duration: 0.2
```

Til test:

1. Start i `Idle`, `Walk` eller `Run`.
2. Sæt `WasHit=true`.
3. Bekræft at state skifter til `Hit`.
4. Sæt straks `WasHit=false`.
5. Sæt `Speed` til ønsket exit:
   - `0.0` for `Hit -> Idle`
   - `0.3` for `Hit -> Walk`
   - `1.0` for `Hit -> Run`
6. Sæt `HitDone=true`.
7. Bekræft korrekt exit.
8. Sæt `HitDone=false` bagefter.

### 6. Death skal senere overrule Hit

Når `Death` tilføjes, skal death have højeste prioritet:

```text
Any relevant state -> Death
Condition: IsDead
Priority: højeste
```

Hvis `IsDead=true`, skal graphen gå til `Death`, selv hvis `WasHit=true`, `DoScream=true` eller `DoAttack=true`.

## Anbefalet næste rækkefølge

1. Tilføj `Hit` med `WasHit` og `HitDone`.
2. Test `Hit -> Idle`, `Hit -> Walk`, `Hit -> Run`.
3. Tilføj `Death` med højeste prioritet og ingen exit tilbage.
4. Tilføj `Attack` og events/tags til damage timing.

## Reminder om animation graph vs AI

Animation Graph bestemmer kun, hvilken animation zombien spiller. Den bestemmer ikke navmesh/pathfinding. Roaming, target detection og navigation skal komme fra DayZ AI/CE/scripts. Graphen skal reagere på AI-signaler som movement speed, alerted, attack, hit og dead.
