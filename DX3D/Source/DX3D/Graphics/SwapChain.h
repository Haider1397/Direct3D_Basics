#pragma once
#include <DX3D/Graphics/GraphicsResource.h>

namespace dx3d {

	class SwapChain final : public GraphicsResource
	{
	public:
		explicit SwapChain(const SwapChainDesc Desc, const GraphicsResourceDesc& gDesc);


		void present(bool Sync = false);

	private:
		void reloadBuffers();

	private:
		Microsoft::WRL::ComPtr<IDXGISwapChain> m_swapChain{};
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> m_rtv{};


		friend class DeviceContext;
	};
}

