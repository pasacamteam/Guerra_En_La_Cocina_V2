#include "EnemySpawnPoint.h"

AEnemySpawnPoint::AEnemySpawnPoint()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsUnlocked = true;
}

void AEnemySpawnPoint::UnlockSpawPoint()
{
	bIsUnlocked = true;
}

void AEnemySpawnPoint::LockSpawPoint()
{
	bIsUnlocked = false;
}