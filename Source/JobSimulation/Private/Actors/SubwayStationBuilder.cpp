#include "Actors/SubwayStationBuilder.h"
#include "GeometryScript/MeshPrimitiveFunctions.h"
#include "GeometryScript/MeshBasicEditFunctions.h"
#include "DynamicMesh/DynamicMesh3.h"

ASubwayStationBuilder::ASubwayStationBuilder()
{
	PrimaryActorTick.bCanEverTick = false;

	StationMesh = CreateDefaultSubobject<UDynamicMeshComponent>(TEXT("StationMesh"));
	RootComponent = StationMesh;

	ComponentsToGenerate = {
		EStationComponentType::BreadDisplay,
		EStationComponentType::MeatCooler,
		EStationComponentType::VeggieStation,
		EStationComponentType::SauceDispensers,
		EStationComponentType::Toaster
	};
}

void ASubwayStationBuilder::BeginPlay()
{
	Super::BeginPlay();
}

void ASubwayStationBuilder::BuildCompleteStation()
{
	ClearStation();

	CreateCounterBase();

	for (EStationComponentType Component : ComponentsToGenerate)
	{
		switch (Component)
		{
			case EStationComponentType::BreadDisplay:
				CreateBreadDisplay();
				break;
			case EStationComponentType::MeatCooler:
				CreateMeatCooler();
				break;
			case EStationComponentType::VeggieStation:
				CreateVeggieStation();
				break;
			case EStationComponentType::SauceDispensers:
				CreateSauceDispensers();
				break;
			case EStationComponentType::Toaster:
				CreateToaster();
				break;
			default:
				break;
		}
	}

	StationMesh->NotifyMeshUpdated();
}

void ASubwayStationBuilder::ClearStation()
{
	UDynamicMesh* DynamicMesh = StationMesh->GetDynamicMesh();
	if (DynamicMesh)
	{
		DynamicMesh->Clear();
	}
}

void ASubwayStationBuilder::CreateCounterBase()
{
	UDynamicMesh* DynamicMesh = StationMesh->GetDynamicMesh();
	if (!DynamicMesh) return;

	FGeometryScriptPrimitiveOptions PrimOptions;
	FTransform BaseTransform = FTransform(FVector(0, 0, 45));

	UGeometryScriptLibrary_MeshPrimitiveFunctions::AppendBox(
		DynamicMesh,
		PrimOptions,
		BaseTransform,
		300.0f, 80.0f, 90.0f
	);

	FTransform SurfaceTransform = FTransform(FVector(0, 20, 95));
	UGeometryScriptLibrary_MeshPrimitiveFunctions::AppendBox(
		DynamicMesh,
		PrimOptions,
		SurfaceTransform,
		300.0f, 60.0f, 5.0f
	);
}

void ASubwayStationBuilder::CreateBreadDisplay()
{
	UDynamicMesh* DynamicMesh = StationMesh->GetDynamicMesh();
	if (!DynamicMesh) return;

	FGeometryScriptPrimitiveOptions PrimOptions;

	FTransform DisplayTransform = FTransform(FVector(-100, -40, 120));
	UGeometryScriptLibrary_MeshPrimitiveFunctions::AppendBox(
		DynamicMesh,
		PrimOptions,
		DisplayTransform,
		80.0f, 30.0f, 40.0f
	);
}

void ASubwayStationBuilder::CreateMeatCooler()
{
	UDynamicMesh* DynamicMesh = StationMesh->GetDynamicMesh();
	if (!DynamicMesh) return;

	FGeometryScriptPrimitiveOptions PrimOptions;

	FTransform CoolerTransform = FTransform(FVector(0, -30, 85));
	UGeometryScriptLibrary_MeshPrimitiveFunctions::AppendBox(
		DynamicMesh,
		PrimOptions,
		CoolerTransform,
		200.0f, 40.0f, 15.0f
	);

	for (int32 Index = 0; Index < 5; Index++)
	{
		FVector ContainerPos = FVector(-80 + (Index * 40), -30, 93);
		FTransform ContainerTransform = FTransform(ContainerPos);

		UGeometryScriptLibrary_MeshPrimitiveFunctions::AppendCylinder(
			DynamicMesh,
			PrimOptions,
			ContainerTransform,
			15.0f, 12.0f,
			16, 1
		);
	}
}

void ASubwayStationBuilder::CreateVeggieStation()
{
	UDynamicMesh* DynamicMesh = StationMesh->GetDynamicMesh();
	if (!DynamicMesh) return;

	FGeometryScriptPrimitiveOptions PrimOptions;

	for (int32 i = 0; i < 8; i++)
	{
		int32 Row = i / 4;
		int32 Col = i % 4;

		FVector ContainerPos = FVector(
			-60 + (Col * 40),
			10 + (Row * 25),
			100
		);

		FTransform ContainerTransform = FTransform(ContainerPos);

		UGeometryScriptLibrary_MeshPrimitiveFunctions::AppendCylinder(
			DynamicMesh,
			PrimOptions,
			ContainerTransform,
			12.0f, 10.0f,
			12, 1
		);
	}
}

void ASubwayStationBuilder::CreateSauceDispensers()
{
	UDynamicMesh* DynamicMesh = StationMesh->GetDynamicMesh();
	if (!DynamicMesh) return;

	FGeometryScriptPrimitiveOptions PrimOptions;

	for (int32 Index = 0; Index < 4; Index++)
	{
		FVector DispenserPos = FVector(80 + (Index * 20), 15, 110);
		FTransform DispenserTransform = FTransform(DispenserPos);

		UGeometryScriptLibrary_MeshPrimitiveFunctions::AppendCylinder(
			DynamicMesh,
			PrimOptions,
			DispenserTransform,
			5.0f, 25.0f,
			8, 2
		);
	}
}

void ASubwayStationBuilder::CreateToaster()
{
	UDynamicMesh* DynamicMesh = StationMesh->GetDynamicMesh();
	if (!DynamicMesh) return;

	FGeometryScriptPrimitiveOptions PrimOptions;

	FTransform ToasterTransform = FTransform(FVector(120, -20, 105));
	UGeometryScriptLibrary_MeshPrimitiveFunctions::AppendBox(
		DynamicMesh,
		PrimOptions,
		ToasterTransform,
		40.0f, 35.0f, 25.0f
	);
}


