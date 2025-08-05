// Copyright Epic Games, Inc. All Rights Reserved.

#include "SherpaOnnxSpeech.h"

#include "Interfaces/IPluginManager.h"
#include "sherpa-onnx/c-api/cxx-api.h"

#define LOCTEXT_NAMESPACE "FSherpaOnnxSpeechModule"

void FSherpaOnnxSpeechModule::StartupModule()
{
	// 动态加载 DLL（可选，静态链接 .lib 时可不写）
	FString BaseDir = IPluginManager::Get().FindPlugin(TEXT("SherpaOnnxSpeech"))->GetBaseDir();
	FString DllPath = FPaths::Combine(*BaseDir, TEXT("ThirdParty/bin/sherpa-onnx-cxx-api.dll"));
	void* DllHandle = FPlatformProcess::GetDllHandle(*DllPath);

	// 检查 DLL 是否加载成功
	if (!DllHandle)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to load sherpa-onnx-cxx-api.dll"));
		return;
	}

	// 下面就可以直接 include 头文件并调用 sherpa-onnx 的 C++ API
	// 例如（伪代码，具体API参考头文件）：
	// sherpa_onnx::RecognizerConfig config;
	// sherpa_onnx::Recognizer recognizer(config);
}

void FSherpaOnnxSpeechModule::ShutdownModule()
{
	// 卸载 DLL（可选）
	// if (DllHandle)
	//     FPlatformProcess::FreeDllHandle(DllHandle);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSherpaOnnxSpeechModule, SherpaOnnxSpeech)