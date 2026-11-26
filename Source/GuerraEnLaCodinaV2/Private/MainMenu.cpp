#include "MainMenu.h"
#include "Components/Button.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UMainMenu::NativeConstruct()
{
	Super::NativeConstruct();

	
	if (APlayerController* PC = GetOwningPlayer())
	{
		FInputModeUIOnly InputMode;
		InputMode.SetWidgetToFocus(TakeWidget());
		PC->SetInputMode(InputMode);
		PC->SetShowMouseCursor(true);
	}

	
	if (Start)
	{
		Start->OnClicked.AddDynamic(this, &UMainMenu::OnStartClicked);
	}


	if (Quit)
	{
		Quit->OnClicked.AddDynamic(this, &UMainMenu::OnQuitClicked);
	}
	
}

void UMainMenu::OnStartClicked()
{
	RemoveFromParent();

	if (APlayerController* PC = GetOwningPlayer())
	{
		PC->SetInputMode(FInputModeGameOnly());
		PC->SetShowMouseCursor(false);
	}

	
	//UGameplayStatics::OpenLevel(this, FName("GYM"));
}

void UMainMenu::OnQuitClicked()
{
	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(),
		EQuitPreference::Quit, false);
}