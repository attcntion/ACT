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

//�ڶ��°��ƶ����뺯����ʵ��
void AAT_Character::MoveForward(float value)
{
	FRotator ControlRot = GetControlRotation();
	ControlRot.Roll = 0.0f;
	ControlRot.Pitch = 0.0f;

	//Ŀ�����ǰ�����͵�����ת��.vector����
	
	AddMovementInput(ControlRot.Vector(), value);


}

void AAT_Character::MoveRight(float value)
{
	  FRotator ControlRot = GetControlRotation();
	  ControlRot.Roll = 0.0f;
	  ControlRot.Pitch = 0.0f;
	 
	  //��һ��������ת�壬�ڶ����Ƿ���
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

	//�ڶ��£��ƶ����βΣ����֣����󣬵��õĺ���). 
	PlayerInputComponent->BindAxis("MoveForward", this, &AAT_Character::MoveForward);
	
	PlayerInputComponent->BindAxis("MoveRight", this, &AAT_Character::MoveRight);

	//����APanw�Դ��ĺ�����
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Up", this, &APawn::AddControllerPitchInput);

}

