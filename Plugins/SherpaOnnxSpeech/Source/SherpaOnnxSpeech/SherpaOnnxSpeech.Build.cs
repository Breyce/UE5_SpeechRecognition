// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class SherpaOnnxSpeech : ModuleRules
{
	public SherpaOnnxSpeech(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		// 插件/模块的头文件路径
		PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "../../ThirdParty/include"));

		// 链接 Sherpa-onnx 的 lib
		PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "../../ThirdParty/lib/sherpa-onnx-cxx-api.lib"));

		// 运行时加载 DLL 的路径
		string PluginBinDir = Path.Combine(ModuleDirectory, "../../ThirdParty/bin");
		RuntimeDependencies.Add("$(PluginDir)/ThirdParty/bin/sherpa-onnx-cxx-api.dll");
		RuntimeDependencies.Add("$(PluginDir)/ThirdParty/bin/onnxruntime.dll");

		// 让引擎在启动时自动拷贝 DLL 到 Binaries 目录
		PublicDelayLoadDLLs.Add("sherpa-onnx-cxx-api.dll");
		PublicDelayLoadDLLs.Add("onnxruntime.dll");
		
		PublicIncludePaths.AddRange(
			new string[] {
				Path.Combine(ModuleDirectory, "../../ThirdParty/include")
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"Projects"
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
