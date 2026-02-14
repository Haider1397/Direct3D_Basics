#include <DX3D/Graphics/SwapChain.h>



dx3d::SwapChain::SwapChain(const SwapChainDesc Desc, const GraphicsResourceDesc& gDesc):
	GraphicsResource(gDesc)
{
	DXGI_SWAP_CHAIN_DESC dxgiDesc{};

	dxgiDesc.BufferDesc.Width = std::min(1, Desc.winSize.width);
	dxgiDesc.BufferDesc.Height = std::min(1, Desc.winSize.hight);
	dxgiDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	dxgiDesc.BufferCount = 2;
	dxgiDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	dxgiDesc.OutputWindow = static_cast<HWND>(Desc.winHandle);
	dxgiDesc.SampleDesc.Count = 1;
	dxgiDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
	dxgiDesc.Windowed = TRUE;


	DX3DGraphicLogUtilsErrorAndThrow(m_factory.CreateSwapChain(&m_device,&dxgiDesc,&m_swapChain),
		"Create SwapChain failed.");
}

