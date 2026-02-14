#pragma once

#include<DX3D/Core/Base.h>
#include<DX3D/Core/Common.h>
#include<DX3D/Graphics/GraphicsLogUtils.h>
#include<d3d11.h>
#include<wrl.h>

namespace dx3d {

	struct GraphicsResourceDesc
	{
		BaseDesc Base;
		IDXGIDevice& device;
		IDXGIFactory& factory;
		
	
	};

	class GraphicsResource: public Base 
	{
	public:
		explicit GraphicsResource(const GraphicsResourceDesc& Desc):
			Base(Desc.Base),
			m_device(Desc.device),
			m_factory(Desc.factory)
		{

		}

	protected:

		IDXGIFactory& m_factory;
		IDXGIDevice& m_device;
	};
}