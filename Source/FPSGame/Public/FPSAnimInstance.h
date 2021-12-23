// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "FPSAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class FPSGAME_API UFPSAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

	FRotator SwayOldRotation;

protected:

	UPROPERTY(EditAnywhere, Category = "Arm Sway")
	float MaxSwayRotation;

	UPROPERTY(EditAnywhere, Category = "Arm Sway")
	float SwaySpeed;

	// This is the final value you need to plug into the Transform Bone node ( you don't need to clamp/swizzle this, it's ready as-is )
	UPROPERTY(BlueprintReadOnly, Category ="ArmsAnimInstance")
	FRotator SwayDeltaRotation;

	UPROPERTY(BlueprintReadOnly, Category = "ArmsAnimInstance")
	FVector SwayDeltaTranslation;

	UFUNCTION(BlueprintCallable, Category = "ArmsAnimInstance")
	void CalcWeaponSway(float DeltaTime);

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UFPSAnimInstance();
};
