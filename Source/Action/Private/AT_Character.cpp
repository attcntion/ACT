// Fill out your copyright notice in the Description page of Project Settings.


#include "AT_Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


// Sets default values
AAT_Character::AAT_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->SetupAttachment(RootComponent);


	CarmerComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CarmerComp->SetupAttachment(SpringArmComp);
}

// Called when the game starts or when spawned
void AAT_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

//第二章绑定移动输入函数的实现
void AAT_Character::MoveForward(float value)
{
	FRotator ControlRot = GetControlRotation();
	ControlRot.Roll = 0.0f;
	ControlRot.Pitch = 0.0f;

	//目标的向前向量就等于旋转体.vector（）
	
	AddMovementInput(ControlRot.Vector(), value);


}

void AAT_Character::MoveRight(float value)
{
	  FRotator ControlRot = GetControlRotation();
	  ControlRot.Roll = 0.0f;
	  ControlRot.Pitch = 0.0f;
	 
	  //第一个参数旋转体，第二个是方向。
	 FVector RightVector =  FRotationMatrix(ControlRot).GetScaledAxis(EAxis::Y);

	 AddMovementInput(RightVector, value);
}




// Called every frame
void AAT_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAT_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//第二章：移动：形参（名字，对象，调用的函数). 
	PlayerInputComponent->BindAxis("MoveForward", this, &AAT_Character::MoveForward);
	
	PlayerInputComponent->BindAxis("MoveRight", this, &AAT_Character::MoveRight);

	//这是APanw自带的函数。
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Up", this, &APawn::AddControllerPitchInput);

}

