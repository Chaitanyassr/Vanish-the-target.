// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSBombActor.h"
#include "kismet/GameplayStatics.h"
#include "Engine/Engine.h"

// Sets default values
AFPSBombActor::AFPSBombActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ExplodeDelay = 2.0f;

}

void AFPSBombActor::Explode()
{
	UGameplayStatics::SpawnEmitterAtLocation(this, ExplosionTemplate, GetActorLocation());
	Destroy();
}

// Called when the game starts or when spawned
void AFPSBombActor::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle Explode_TimerHandle;
	GetWorldTimerManager().SetTimer(Explode_TimerHandle, this, &AFPSBombActor::Explode, ExplodeDelay, false);
	
}

// Called every frame
void AFPSBombActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

