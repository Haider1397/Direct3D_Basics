#pragma once
#include<DX3D/Core/Core.h>
#include<DX3D/Window/Window.h>

namespace dx3d {

	class Display final: public Window
	{
	public:
		explicit Display(const DisplayDesc& desc);

		SwapChain& getSwapChain() const noexcept;

	private:
		SwapChainPtr m_swapChain{};
	};

}

