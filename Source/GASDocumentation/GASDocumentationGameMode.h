// Copyright 2020 Dan Kestranek.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GASDocumentationGameMode.generated.h"

UCLASS(minimalapi)
class AGASDocumentationGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGASDocumentationGameMode();

	void HeroDied(AController* Controller);
	//Respawn로직을 GameState로 옮겨야 한다.
	//RespawnComponent를 만들어 gameMode에 부착한다
protected:
	float RespawnDelay;

	TSubclassOf<class AGDHeroCharacter> HeroClass;
	//Experience System(Lyra) - 어떤캐릭터를 스폰할지 PawnData라는 DataAsset을 미리 정의해둔다.
	//
	AActor* EnemySpawnPoint;

	virtual void BeginPlay() override;

	void RespawnHero(AController* Controller);
};
