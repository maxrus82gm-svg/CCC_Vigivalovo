// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once //— это защита от повторного подключения одного и того же заголовочного файла.

#include "CoreMinimal.h"  //подключаем базовый инструментарий Unreal Engine.
#include "GameFramework/Character.h" // Подключаем базовый класс персонажа Unreal
#include "Logging/LogMacros.h"
#include "Components/SpotLightComponent.h"
#include "CCC_VigivalovoCharacter.generated.h"  //мост между нашим C++ классом и внутренней системой Unreal Engine. И важное правило: этот include обычно должен быть последним среди #include в .h файле.

class UInputComponent;
class USkeletalMeshComponent;
class UCameraComponent;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

/**
 *  A basic first person character
 */
UCLASS(abstract)  // компоненты
class ACCC_VigivalovoCharacter : public ACharacter  //«Создаём класс ACCC_VigivalovoCharacter, который наследуется от ACharacter.»
{
	GENERATED_BODY()


	//EditAnywhere позволяет менять класс компонента и наименование, BlueprintReadWrite позволяет менять переменную-ссылку в блюпринтах.
	// VisibleAnywhere не дает менять класс компонента и наименование, BlueprintReadOnly относится прежде всего к переменной-ссылке, а не делает весь объект «неизменяемым»., meta = (AllowPrivateAccess = "true") 
	// позволяет использовать компонент в блюпринтах, но не дает менять его там.

	/** Pawn mesh: first person view (arms; seen only by self) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* FirstPersonMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USpotLightComponent* SvetFonarikaPersonazha; // добавляем компонент фонарика

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;

protected:
	/** Действие ввода для фонарика */
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* FonarikAction;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, Category ="Input")
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, Category ="Input")
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, Category ="Input")
	class UInputAction* LookAction;

	/** Mouse Look Input Action */
	UPROPERTY(EditAnywhere, Category ="Input")
	class UInputAction* MouseLookAction;
	
public:
	ACCC_VigivalovoCharacter();

protected:

	/** Called from Input Actions for movement input */
	void MoveInput(const FInputActionValue& Value);

	/** Called from Input Actions for looking input */
	void LookInput(const FInputActionValue& Value);

	/** Handles aim inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoAim(float Yaw, float Pitch);

	/** Handles move inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoMove(float Right, float Forward);

	/** Handles jump start inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoJumpStart();

	/** Handles jump end inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoJumpEnd();

	void PerekluchitFonarik();

protected:

	/** Set up input action bindings */ 
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	

public:

	/** Returns the first person mesh **/
	USkeletalMeshComponent* GetFirstPersonMesh() const { return FirstPersonMesh; }

	/** Returns first person camera component **/
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

};

