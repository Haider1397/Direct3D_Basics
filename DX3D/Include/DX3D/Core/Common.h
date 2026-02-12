#pragma once

#include<DX3D/Core/Core.h>
#include<DX3D/Core/Logger.h>

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
	struct GameDesc
	{
		Logger::LogLevel logLevel = Logger::LogLevel::Error;
	};


}