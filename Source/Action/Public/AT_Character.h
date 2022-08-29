#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AT_Character.generated.h"

class UCameraComponent;
class USpringArmComponent;


UCLASS()
class ACTION_API AAT_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAT_Character();

protected:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CarmerComp;


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//第二章绑定移动输入
	void MoveForward(float value);

	void MoveRight(float value);



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
