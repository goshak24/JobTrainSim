#include "JobSimulation.h"

#define LOCTEXT_NAMESPACE "FJobSimulationModule"

void FJobSimulationModule::StartupModule()
{
    UE_LOG(LogTemp, Warning, TEXT("JobSimulation Module Started"));
}

void FJobSimulationModule::ShutdownModule()
{
    UE_LOG(LogTemp, Warning, TEXT("JobSimulation Module Shutdown"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FJobSimulationModule, JobSimulation)