// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	CurrentPosition = FVector2D(0, 0);
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	Move();
}

int32 AMyActor::Step()
{
	return FMath::RandRange(0, 1);
}	

void AMyActor:: Move()
{
	FVector2D PrePosition = CurrentPosition;
	float TotalDistance = 0; // 총 이동거리
	int32 EventCounter = 0; // 이벤트 발생 횟수
	
	for (int32 i = 0; i < 10; i++)
	{
		int32 XStep = Step();
		int32 YStep = Step();
	
		// 이동이 규칙에 맞는지 확인 : 각 좌표는 한 단계에 최대 1만큼만 이동!
		if (XStep <= 1 && YStep <= 1)
		{
			PrePosition = CurrentPosition; // 이전 위치 저장 후 이동함.
			CurrentPosition.X += XStep;
			CurrentPosition.Y += YStep;

			float StepDistance = FMath::Sqrt(FMath::Square(CurrentPosition.X - PrePosition.X) + FMath::Square(CurrentPosition.Y - PrePosition.Y));
			TotalDistance += StepDistance; // 총 이동거리 계산

			// 50% 확률로 이벤트 발생!
			bool Event = (FMath::RandRange(0, 1) == 1); // 0과 1중에 랜덤 발생, 그 난수가 1이면 true(즉, 50% 확률)
			if (Event)
			{
				EventCounter++;
				UE_LOG(LogTemp, Warning, TEXT("Step: %d, X: %f, Y: %f, Distance: %f, 이벤트 발생!"), i+1, CurrentPosition.X, CurrentPosition.Y, StepDistance);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Step: %d, X: %f, Y: %f, Distance: %f, 이벤트 없음!"), i+1, CurrentPosition.X, CurrentPosition.Y, StepDistance);
			}
		}
		else
		{
			--i; // 이동이 규칙에 맞지 않으면 다시 시도
		}
	}
	//최종 결과 출력
	UE_LOG(LogTemp, Warning, TEXT("[최종 결과] 총 이동거리 : %f, 이벤트 발생횟수: %d"), TotalDistance, EventCounter);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

