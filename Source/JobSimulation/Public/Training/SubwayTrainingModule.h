#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SubwayTrainingModule.generated.h"

UENUM(BlueprintType)
enum class EOrderComplexity : uint8
{
	Simple,
	Standard,
	Advanced
};

UCLASS(BlueprintType)
class JOBSIMULATION_API USubwayTrainingModule : public UObject
{
	GENERATED_BODY()

public:
	USubwayTrainingModule();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Training")
	FString ModuleName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Training")
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Training")
	float PassingScore;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Training")
	bool bRequiresVR;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Training")
	EOrderComplexity MaxComplexity;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Training")
	int32 CurrentTaskIndex;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Training")
	bool bModuleActive;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Training|Timer")
	float ModuleStartTime;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Training|Timer")
	float CurrentTimer;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Training|Timer")
	bool bTimerActive;
};


