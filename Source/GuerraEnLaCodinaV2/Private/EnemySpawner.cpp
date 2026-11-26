#include "EnemySpawner.h"
#include "EnemySpawnPoint.h"
#include "Engine/World.h"

UEnemySpawner::UEnemySpawner()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	RefreshAvailableSpawnPoints();
}

void UEnemySpawner::RefreshAvailableSpawnPoints()
{
	AvailableSpawnPoints.Empty();

	for (const TSoftObjectPtr<AEnemySpawnPoint>& Point : Spawnpoints)
	{
		TObjectPtr<AEnemySpawnPoint> SpawnPoint = Point.Get();
		if (!SpawnPoint && !Point.IsNull())
		{
			SpawnPoint = Point.LoadSynchronous();
		}

		if (IsValid(SpawnPoint) && SpawnPoint->bIsUnlocked)
		{
			AvailableSpawnPoints.Add(SpawnPoint);
		}
	}
}

void UEnemySpawner::SpawnEnemy()
{
	UWorld* World = GetWorld();
	if (!SelectedEnemyClass || !World)
	{
		return;
	}

	RefreshAvailableSpawnPoints();

	if (AvailableSpawnPoints.Num() == 0)
	{
		return;
	}

	const int32 RandomIndex = FMath::RandRange(0, AvailableSpawnPoints.Num() - 1);
	TObjectPtr<AEnemySpawnPoint> ChosenPoint = AvailableSpawnPoints[RandomIndex];

	if (!IsValid(ChosenPoint) || !ChosenPoint->bIsUnlocked)
	{
		return;
	}

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	World->SpawnActor<AActor>(
		SelectedEnemyClass,
		ChosenPoint->GetActorLocation(),
		ChosenPoint->GetActorRotation(),
		SpawnParams
	);
}