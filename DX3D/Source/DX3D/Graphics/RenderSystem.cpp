#include <DX3D/Graphics/RenderSystem.h>
#include <DX3D/Graphics/GraphicsLogUtils.h>
#include<DX3D/Graphics/SwapChain.h>

using namespace dx3d;

dx3d::RenderSystem::RenderSystem(const RenderSystemDesc& desc) : Base(desc.Base)
{
	D3D_FEATURE_LEVEL featureLevel{};
	UINT createDeviceFlags{};

#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif // _DEBUG

	 DX3DGraphicLogUtilsErrorAndThrow(D3D11CreateDevice(NULL,D3D_DRIVER_TYPE_HARDWARE,NULL,createDeviceFlags,
		 NULL,0,D3D11_SDK_VERSION,&m_d3dDevice,&featureLevel,&m_d3dContext),
		 "D3D11 initalization failed.");


	 DX3DGraphicLogUtilsErrorAndThrow( m_d3dDevice->QueryInterface(IID_PPV_ARGS(&m_dxgiDevice)),
		 "QueryInterface failed to retrive IDXGIDevice.");
	 
	 DX3DGraphicLogUtilsErrorAndThrow(m_dxgiDevice->GetParent(IID_PPV_ARGS(&m_dxgiAdapter)),
		 "GetParent failed to retrive IDXGIAdapter.");
	 
	 DX3DGraphicLogUtilsErrorAndThrow(m_dxgiDevice->GetParent(IID_PPV_ARGS(&m_dxgiFactory)),
		 "GetParent failed to retrive IDXGIFactory.");
}


dx3d::RenderSystem::~RenderSystem()
{
}

SwapChainPtr dx3d::RenderSystem::createSwapChain(const SwapChainDesc& Desc)
{
	return std::make_shared<SwapChain>(desc,);
}

GraphicsEngineDesc dx3d::RenderSystem::GetGraphicsResourcesDesc()
{
	return { {m_logger} ,*m_d3dDevice.Get() , *m_dxgiAdapter.Get()};
}
