#include <DX3D/Game/Display.h>
#include<DX3D/Graphics/GraphicsDevice.h>

dx3d::Display::Display(const DisplayDesc& desc):
	Window(desc.Window)
{
	m_swapChain = desc.GraphicsDevice.createSwapChain({m_handle,m_size});
}
