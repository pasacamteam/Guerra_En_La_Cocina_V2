
#include "BP_PlayerControler.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"

void ABP_PlayerControler::BeginPlay()
{
    Super::BeginPlay();

    if (GetLocalPlayer())
    {
        UEnhancedInputLocalPlayerSubsystem* Subsystem =
            GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();

        if (Subsystem)
        {
            Subsystem->AddMappingContext(InputContext, 0);
        }
    }
}

void ABP_PlayerControler::SetupInputComponent()
{
    Super::SetupInputComponent();

    UEnhancedInputComponent* Input =
        Cast<UEnhancedInputComponent>(InputComponent);

    if (Input)
    {
        Input->BindAction(MoveAction, ETriggerEvent::Triggered, this,
            &ABP_PlayerControler::Move);

        Input->BindAction(JumpAction, ETriggerEvent::Started, this,
            &ABP_PlayerControler::Jump);
    }
}

//Move
void ABP_PlayerControler::Move(const FInputActionValue& Value)
{
    FVector2D Movement = Value.Get<FVector2D>();

    if (GetPawn())
    {
        GetPawn()->AddMovementInput(GetPawn()->GetActorForwardVector(), Movement.Y);
        GetPawn()->AddMovementInput(GetPawn()->GetActorRightVector(), Movement.X);
    }
}

// Jump
void ABP_PlayerControler::Jump()
{
    ACharacter* MyCharacter = Cast<ACharacter>(GetPawn());

    if (MyCharacter)
    {
        MyCharacter->Jump();
    }
}
