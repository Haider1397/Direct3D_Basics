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
		std::shared_ptr<const GraphicsDevice> graphicsDevice;
		ID3D11Device& device;
		IDXGIFactory& factory;
		
	
	};

	class GraphicsResource: public Base 
	{
	public:
		explicit GraphicsResource(const GraphicsResourceDesc& Desc):
			Base(Desc.Base),
			m_graphicsDevice(Desc.graphicsDevice),
			m_device(Desc.device),
			m_factory(Desc.factory)
		{
		
		}

	protected:

		std::shared_ptr<const GraphicsDevice> m_graphicsDevice;
		IDXGIFactory& m_factory;
		ID3D11Device& m_device;
		
	};
}