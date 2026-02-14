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
	};
	struct GraphicsEngineDesc
	{
		BaseDesc Base;
	};
	struct RenderSystemDesc
	{
		BaseDesc Base;
	};
	struct SwapChainDesc
	{
		void* winHandle{};
		Rect winSize{};
	};
	struct GameDesc
	{
		Logger::LogLevel logLevel = Logger::LogLevel::Error;
	};


}