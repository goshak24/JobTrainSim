#include "Training/SubwayTrainingModule.h"
#include "Engine/World.h"

USubwayTrainingModule::USubwayTrainingModule()
{
	ModuleName = TEXT("Basic Training");
	Description = TEXT("Learn the fundamentals of sandwich preparation");
	PassingScore = 80.0f;
	bRequiresVR = false;
	MaxComplexity = EOrderComplexity::Standard;
	CurrentTaskIndex = 0;
	bModuleActive = false;
	ModuleStartTime = 0.0f;
	CurrentTimer = 0.0f;
	bTimerActive = false;
}


