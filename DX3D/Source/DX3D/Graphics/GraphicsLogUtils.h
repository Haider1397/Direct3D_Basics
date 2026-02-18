#pragma once

#include <DX3D/Core/Logger.h>
#include<d3d11.h>

namespace dx3d 
{
	namespace GraphicLogUtils
	{
		inline void CheckShaderCommpile(Logger& logger, HRESULT hr, ID3DBlob* errorBlob)
		{
			auto errorMSG = errorBlob ? static_cast<const char*>(errorBlob->GetBufferPointer()) : nullptr ;
			if (FAILED(hr))
			{
				if (errorMSG)
				{
					DX3DLogThrow(logger,std::runtime_error , Logger::LogLevel::Error, errorMSG);
				}
				else
				{
					DX3DLogThrow(logger, std::runtime_error, Logger::LogLevel::Error, 
						"Shader compilation failed.");
				}
			}
			if(errorMSG)
			{
				DX3DLog(logger, Logger::LogLevel::Warning, errorMSG);
			}
		
		}
	}

}

#define DX3DGraphicsLogThrowOnFail(hr,message)\
	{\
		auto res = (hr);\
		if (FAILED(res))\
				DX3DLogThrowError(message);\
	}

#define DX3DGraphicsCheckShaderCommpile(hr, message)\
	{\
	auto res = (hr);\
	dx3d::GraphicLogUtils::CheckShaderCommpile(getLogger() , res , message);\
	}