// Copyright 2020 Dan Kestranek.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"

#define ACTOR_ROLE_FSTRING *(FindObject<UEnum>(nullptr, TEXT("/Script/Engine.ENetRole"), true)->GetNameStringByValue(GetLocalRole()))
#define GET_ACTOR_ROLE_FSTRING(Actor) *(FindObject<UEnum>(nullptr, TEXT("/Script/Engine.ENetRole"), true)->GetNameStringByValue(Actor->GetLocalRole()))
//코드 내 매크로보다 UE의 Visual Logger 도구를 사용해 Role변화 관측 가능

UENUM(BlueprintType)
enum class EGDHitReactDirection : uint8
{
	// 0
	None			UMETA(DisplayName = "None"),
	// 1
	Left 			UMETA(DisplayName = "Left"),
	// 2
	Front 			UMETA(DisplayName = "Front"),
	// 3
	Right			UMETA(DisplayName = "Right"),
	// 4
	Back			UMETA(DisplayName = "Back")
};
//현재의 Enum방식보단 Tag활용 방향으로 State.HitReact.Front 이런식.

UENUM(BlueprintType)
enum class EGDAbilityInputID : uint8
{
	// 0 None
	None			UMETA(DisplayName = "None"),
	// 1 Confirm
	Confirm			UMETA(DisplayName = "Confirm"),
	// 2 Cancel
	Cancel			UMETA(DisplayName = "Cancel"),
	// 3 LMB
	Ability1		UMETA(DisplayName = "Ability1"),
	// 4 RMB
	Ability2		UMETA(DisplayName = "Ability2"),
	// 5 Q
	Ability3		UMETA(DisplayName = "Ability3"),
	// 6 E
	Ability4		UMETA(DisplayName = "Ability4"),
	// 7 R
	Ability5		UMETA(DisplayName = "Ability5"),
	// 8 Sprint
	Sprint			UMETA(DisplayName = "Sprint"),
	// 9 Jump
	Jump			UMETA(DisplayName = "Jump")
};//InputID를 Enum+정수매핑하는 방식으로 하는 경우는 현대에 와서 거의 쓰지 않는다.
//구형 BindAction -> 이제 EnhancedInputAction에서 한번에 할 수 있도록 되었다.
//InputConfig 데이터 에셋을 만들어 InputAction-GameplayTag를 1대1로 매핑한다.