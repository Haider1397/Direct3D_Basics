#include <DX3D/Graphics/GraphicsDevice.h>
#include <DX3D/Graphics/GraphicsLogUtils.h>
#include<DX3D/Graphics/SwapChain.h>

using namespace dx3d;

dx3d::GraphicsDevice::GraphicsDevice(const GraphicsDeviceDesc& desc) : Base(desc.Base)
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
	 



	 DX3DGraphicLogUtilsErrorAndThrow(m_dxgiAdapter->GetParent(IID_PPV_ARGS(&m_dxgiFactory)),
		 "GetParent failed to retrive IDXGIFactory.");
}


dx3d::GraphicsDevice::~GraphicsDevice()
{
}

SwapChainPtr dx3d::GraphicsDevice::createSwapChain(const SwapChainDesc& Desc) const
{
	return std::make_shared<SwapChain>(Desc,GetGraphicsResourcesDesc());
}

GraphicsResourceDesc dx3d::GraphicsDevice::GetGraphicsResourcesDesc() const noexcept
{
	return { {m_logger}, shared_from_this() ,*m_dxgiDevice.Get() , *m_dxgiFactory.Get()};
}

