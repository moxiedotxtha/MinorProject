// Fill out your copyright notice in the Description page of Project Settings.


#include "CarGI.h"
#include "Misc/Paths.h"

// global variables
const float g_Start = 1.0f;
const float g_End = 0.01f;
const float g_Decay = 1e-4f;
const float g_Gamma = 0.95f;
const float g_LearningRate = 1e-3f;
bool  g_Resume = false; // to resume training // also make sure the previous model has the same architecture before setting it to "true"



const uint64 UCarGI::Capacity = 64 * 1024;
const int32 UCarGI::BatchSize = 128;
const int32 UCarGI::NumStates = 5;
const int32 UCarGI::NumActions = 3;
int32 UCarGI::EpochCount = 0;
int64 UCarGI::StepCount = 0;

const std::string UCarGI::RootPath = std::string(TCHAR_TO_UTF8(*FPaths::ProjectContentDir())) + "../SavedNets/";
const std::string UCarGI::FilePath = UCarGI::RootPath + "Policy.pt";

torch::Device UCarGI::Device = torch::kCPU; // using gpu is slower because UE4 also uses gpu (maybe)

// dont set these yet // crashes editor // smart pointers (policyNet and targetNet) not getting deallocated or had already been deallocated before destructor
//std::unique_ptr<ReplayMemory>     UCarGI::Mem = std::make_unique<ReplayMemory>(Capacity, NumStates, Device);
//std::unique_ptr<QAgent>           UCarGI::Agent = std::make_unique<QAgent>(NumActions, g_Start, g_End, g_Decay, Device);
//std::unique_ptr<NetworkInterface> UCarGI::Net = std::make_unique<NetworkInterface>(NumStates, NumActions, g_Gamma, g_LearningRate, Device);


UCarGI::UCarGI()
{
	UE_LOG(LogTemp, Warning, TEXT("CarGI Constructor"));

	//Net->Init();

	//// resume training
	//if (g_Resume)
	//{
	//	Net->LoadPolicyNet(FilePath);
	//	Net->LoadTargetNet(FilePath);
	//	Net->LoadOptimizer(RootPath + "Optimizer.pt");
	//	//Mem->LoadReplayMem(RootPath);
	//	// load hyperparameters
	//	g_Resume = false; // so that replay mem won't be loaded again
	//}
	//else
	//{
	//	// copying parameters of the policyNet to targetNet
	//	Net->CloneModel(FilePath);
	//	// LoadStateDict(m_TargetNet, m_PolicyNet); // doesnt work yet
	//}
	//UE_LOG(LogTemp, Warning, TEXT("Replay Mem size = %lld"), Mem->GetMemorySize());
}

UCarGI::~UCarGI()
{
	UE_LOG(LogTemp, Warning, TEXT("CarGI Destructor"));
	//UE_LOG(LogTemp, Warning, TEXT("Replay Mem size = %lld"), Mem->GetMemorySize());

	//Net->SavePolicyNet(FilePath);
	//Net->SaveOptimizer(RootPath + "Optimizer.pt");
	//Mem->SaveReplayMem(Mem->GetMemorySize(), RootPath);
	// serialize hyperparameters
}