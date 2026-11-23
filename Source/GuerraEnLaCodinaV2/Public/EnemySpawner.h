#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemySpawner.generated.h"

class AEnemySpawnPoint;

UCLASS(ClassGroup = (Custom), Blueprintable, meta = (BlueprintSpawnableComponent))
class GUERRAENLACODINAV2_API UEnemySpawner : public UActorComponent
{
	GENERATED_BODY()

public:
	UEnemySpawner();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	TArray<TSoftObjectPtr<AEnemySpawnPoint>> Spawnpoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	TSubclassOf<AActor> SelectedEnemyClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawner")
	TArray<TObjectPtr<AEnemySpawnPoint>> AvailableSpawnPoints;

	UFUNCTION(BlueprintCallable, Category = "Spawner")
	void SpawnEnemy();

	UFUNCTION(BlueprintCallable, Category = "Spawner")
	void RefreshAvailableSpawnPoints();
};