#pragma once

#include<DX3D/Core/Core.h>
#include<DX3D/Core/Logger.h>
#include<DX3D/Math/Rect.h>

namespace dx3d 
{
	struct BaseDesc
	{
		Logger& logger;
	};
	struct WindowDesc
	{
		BaseDesc Base;
		Rect size{};
	};
	struct GraphicsEngineDesc
	{
		BaseDesc Base;
	};
	struct GraphicsDeviceDesc
	{
		BaseDesc Base;
	};
	struct DisplayDesc
	{
		WindowDesc Window;
		GraphicsDevice& graphicsDevice;
	};
	struct SwapChainDesc
	{
		void* winHandle{};
		Rect winSize{};
	};

	enum  class ShaderType{
		VertexShader = 0,
		PixelShader
	};
	struct ShaderCompileDesc 
	{
		const char* shaderSourceName{};
		const void* shaderSourceCode{};
		size_t shaderSourceCodeSize{};
		const char* shaderEntryPoint{};
		ShaderType shaderType{};
	};
	struct ShaderBinaryData
	{
		const void* data{};
		size_t dataSize{};
	};
	struct GraphicsPipelineStatesDesc
	{
		const ShaderBinary& vs;
		const ShaderBinary& ps;

	};
	struct VertexBufferDesc
	{
		const void* vertexList{};
		ui32 vertexListSize{};
		ui32 vertexSize{};

	};
	struct GameDesc
	{
		Rect windowSize{ 1280,720 };
		Logger::LogLevel logLevel = Logger::LogLevel::Error;
	};


}