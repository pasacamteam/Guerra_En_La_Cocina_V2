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

void UAC_StatsComponent::UpgradeMovementSpeed()
{
}

void UAC_StatsComponent::UpgradeCooldownReduction()
{
}

void UAC_StatsComponent::UpgradeDamageMultiplier()
{
}

void UAC_StatsComponent::ResetStats()
{
    MovementSpeed = 1.0f;
    CooldownReduction = 1.0f;
    DamageMultiplier = 1.0f;
}