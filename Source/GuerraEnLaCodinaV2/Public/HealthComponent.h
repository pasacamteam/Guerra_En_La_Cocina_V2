// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GUERRAENLACODINAV2_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();
	UPROPERTY(BlueprintAssignable, Category = "Health")
	FOnDeath OnDeath;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float healthBase;

private:
	float maximumHealth;
	float currentHealth;
	float resistance;



protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void TakeDamage(float damage);
	void Heal(float healingAmount);
	void HealthUpgrade(float percentageUpgrade);
	void ResistanceUpgrade(float NewResistance);

	float GetHealthBase() const;
	//void SetHealthBase(float healthBase);
	
	float GetMaximumHealth() const;
	//void SetMaximumHealth(float maximumHealth);
	
	float GetCurrentHealth() const;
	//void SetCurrentHealth(float currentHealth);
	
	float GetResistance() const;
	//void SetResistance(float resistance);

		
};
