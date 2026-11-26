#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.generated.h"

class UButton;

UCLASS()
class GUERRAENLACODINAV2_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* Start;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* Quit;

	UFUNCTION()
	void OnStartClicked();

	UFUNCTION()
	void OnQuitClicked();
};