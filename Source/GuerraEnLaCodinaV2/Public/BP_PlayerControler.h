
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "BP_PlayerControler.generated.h"

UCLASS()
class GUERRAENLACODINAV2_API ABP_PlayerControler : public APlayerController
{
    GENERATED_BODY()

public:

    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, Category = "Input")
    TObjectPtr<UInputMappingContext> InputContext;

    UPROPERTY(EditAnywhere, Category = "Input")
    TObjectPtr<UInputAction> MoveAction;

    UPROPERTY(EditAnywhere, Category = "Input")
    TObjectPtr<UInputAction> JumpAction;

    virtual void SetupInputComponent() override;

    void Move(const FInputActionValue& Value);
    void Jump();
};
