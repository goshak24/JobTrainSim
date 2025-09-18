#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "DynamicMesh/DynamicMesh3.h"
#include "DynamicMeshComponent.h"
#include "SubwayStationBuilder.generated.h"

UENUM(BlueprintType)
enum class EStationComponentType : uint8
{
	BreadDisplay,
	MeatCooler,
	VeggieStation,
	SauceDispensers,
	Toaster,
	CashRegister
};

UCLASS(BlueprintType)
class JOBSIMULATION_API ASubwayStationBuilder : public AActor
{
	GENERATED_BODY()

public:
	ASubwayStationBuilder();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Station")
	UDynamicMeshComponent* StationMesh;

	UPROPERTY(EditAnywhere, Category = "Station Setup")
	TArray<EStationComponentType> ComponentsToGenerate;

	UFUNCTION(CallInEditor, Category = "Station Builder")
	void BuildCompleteStation();

	UFUNCTION(CallInEditor, Category = "Station Builder")
	void ClearStation();

protected:
	virtual void BeginPlay() override;

private:
	void CreateCounterBase();
	void CreateBreadDisplay();
	void CreateMeatCooler();
	void CreateVeggieStation();
	void CreateSauceDispensers();
	void CreateToaster();
};


