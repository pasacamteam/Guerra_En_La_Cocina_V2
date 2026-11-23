#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawnPoint.generated.h"

UCLASS(Blueprintable)
class GUERRAENLACODINAV2_API AEnemySpawnPoint : public AActor
{
	GENERATED_BODY()

public:
	AEnemySpawnPoint();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnPoint")
	bool bIsUnlocked = true;

	// Revisa si en tu equipo prefieren UnlockSpawPoint / LockSpawPoint (como en el UML)
	UFUNCTION(BlueprintCallable, Category = "SpawnPoint")
	void UnlockSpawPoint();

	UFUNCTION(BlueprintCallable, Category = "SpawnPoint")
	void LockSpawPoint();
};