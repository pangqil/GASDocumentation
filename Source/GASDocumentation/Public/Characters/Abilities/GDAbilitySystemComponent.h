// Copyright 2020 Dan Kestranek.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GDAbilitySystemComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FReceivedDamageDelegate, UGDAbilitySystemComponent*, SourceASC, float, UnmitigatedDamage, float, MitigatedDamage);

/**
 * 
 */
UCLASS()
class GASDOCUMENTATION_API UGDAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
	bool bCharacterAbilitiesGiven = false;
	bool bStartupEffectsApplied = false;
	//bool방식으로 RaceCondition문제를 해결하려고 한다. Possessby<->OnRep 이 시점
	//IAbilitySystemInterface가 나오며 InitAbilityActorInfo 시퀀스로 제어한다.
	//혹은 HasMatchingGameplayTag로 정상적으로 받았는지에 대해 태그로 확인한다.
	FReceivedDamageDelegate ReceivedDamage;

	// Called from GDDamageExecCalculation. Broadcasts on ReceivedDamage whenever this ASC receives damage.
	virtual void ReceiveDamage(UGDAbilitySystemComponent* SourceASC, float UnmitigatedDamage, float MitigatedDamage);
	//Exec에서 데미지 계산이 끝남녀 Receive가 직접호출되어 델리게이트 되는 시스템이었다.
	//Casting을 반드시 해야하는 강한결합이라는 단점이 생긴다.
	//AS의 PostGameplayEffectExecute에서 감지하거나 event.damage.Received를 발생.
	//컴포넌트간 의존성 없이 사용하는 플러그인 사용하기도 한다.
	
};
