#pragma once
#include <DX3D/Graphics/GraphicsResources.h>

namespace dx3d {

	class SwapChain final : public GraphicsResource
	{
	public:
		explicit SwapChain(const SwapChainDesc Desc, const GraphicsResourceDesc& gDesc);

	private:
		Microsoft::WRL::ComPtr<IDXGISwapChain> m_swapChain{};
	};
}

