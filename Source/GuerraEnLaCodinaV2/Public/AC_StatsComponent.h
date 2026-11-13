#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_StatsComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GUERRAENLACODINAV2_API UAC_StatsComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UAC_StatsComponent();

protected:
    virtual void BeginPlay() override;

public:
    //Comento el knockback resistance por ahora, pero lo dejo por si en un futuro se quiere implementar
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
    //UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    //float KnockbackResistance;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float MovementSpeed;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float CooldownReduction;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float DamageMultiplier;

    //UFUNCTION(BlueprintCallable, Category = "Stats")
    //float GetKnockbackResistance();
    UFUNCTION(BlueprintCallable, Category = "Stats")
    float GetMovementSpeed();
    UFUNCTION(BlueprintCallable, Category = "Stats")
    float GetCooldownReduction();
    UFUNCTION(BlueprintCallable, Category = "Stats")
    float GetDamageMultiplier();

    //Las mejoras deben de acumularse sin reescribir las stars base

    //UFUNCTION(BlueprintCallable, Category = "Upgrade")
    //void UpgradeKnockbackResistance();
    UFUNCTION(BlueprintCallable, Category = "Upgrade")
    void UpgradeMovementSpeed();
    UFUNCTION(BlueprintCallable, Category = "Upgrade")
    void UpgradeCooldownReduction();
    UFUNCTION(BlueprintCallable, Category = "Upgrade")
    void UpgradeDamageMultiplier();

    UFUNCTION(BlueprintCallable, Category = "Stats")
    void ResetStats();

};