// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void HandleDestruction();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	void RotateTurret(FVector LookAtTarget); 

	void Fire();

private:
	UPROPERTY(VisibleAnywhere, Category = "Components", BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	class UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, Category = "Components", BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* BaseMesh;
	
	UPROPERTY(VisibleAnywhere, Category = "Components", BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* TurretMesh;
	
	UPROPERTY(EditAnywhere, Category = "Components", BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditDefaultsOnly, Category = "Combat", BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	TSubclassOf<class AProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Combat")
	class UParticleSystem* DeathParticles;

	UPROPERTY(EditAnywhere, Category = "Combat")
	class USoundBase* DeathSound;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TSubclassOf<class UCameraShakeBase> DeathCameraShakeClass;

};
