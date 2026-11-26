#include "AC_StatsComponent.h"

UAC_StatsComponent::UAC_StatsComponent()
{
    PrimaryComponentTick.bCanEverTick = true;

}

void UAC_StatsComponent::BeginPlay()
{
    Super::BeginPlay();

}

void UAC_StatsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

float UAC_StatsComponent::GetMovementSpeed()
{
    return MovementSpeed;
}

float UAC_StatsComponent::GetCooldownReduction()
{
    return CooldownReduction;
}

float UAC_StatsComponent::GetDamageMultiplier()
{
    return DamageMultiplier;
}

void UAC_StatsComponent::UpgradeMovementSpeed(float MovementSpeedIncrease)
{
    MovementSpeed += MovementSpeedIncrease;
}

void UAC_StatsComponent::UpgradeCooldownReduction(float CooldownReductionIncrease)
{
    CooldownReduction += CooldownReductionIncrease;
}

void UAC_StatsComponent::UpgradeDamageMultiplier(float DamageMultiplierIncrease)
{
    DamageMultiplier += DamageMultiplierIncrease;
}

void UAC_StatsComponent::ResetStats()
{
    MovementSpeed = 1.0f;
    CooldownReduction = 1.0f;
    DamageMultiplier = 1.0f;
}