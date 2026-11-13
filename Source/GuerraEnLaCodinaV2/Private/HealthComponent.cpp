// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	currentHealth = maximumHealth;
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::TakeDamage(float damage)
{
	currentHealth -= damage - damage * resistance;
	if (currentHealth<=0)
	{
		currentHealth = 0;
		OnDeath.Broadcast();
	}
}

void UHealthComponent::Heal(float healingAmount)
{
	currentHealth += healingAmount;
	if (currentHealth > maximumHealth)
	{
		currentHealth = maximumHealth;
	}
}

void UHealthComponent::HealthUpgrade(float percentageUpgrade)
{
	maximumHealth += healthBase * percentageUpgrade;
	Heal(healthBase * percentageUpgrade);
}

void UHealthComponent::ResistanceUpgrade(float NewResistance)
{
	if (NewResistance > 1) {
		resistance = 1;
	}
	else if (NewResistance<0)
	{
		resistance = 0;
	}
	else {
		resistance = NewResistance;
	}
}

float UHealthComponent::GetHealthBase() const
{
	return healthBase;
}

float UHealthComponent::GetMaximumHealth() const
{
	return maximumHealth;
}

float UHealthComponent::GetCurrentHealth() const
{
	return currentHealth;
}

float UHealthComponent::GetResistance() const
{
	return resistance;
}





