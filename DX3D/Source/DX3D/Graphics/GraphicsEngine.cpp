#include <DX3D/Graphics/GraphicsEngine.h>
#include<DX3D/Graphics/RenderSystem.h>

using namespace dx3d;

dx3d::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc): Base(desc.Base)
	
{




	m_renderSystem = std::make_shared<RenderSystem>(RenderSystemDesc{m_logger});
}



dx3d::GraphicsEngine::~GraphicsEngine()
{
}

RenderSystem& dx3d::GraphicsEngine::GetRenderSystem() const noexcept
{
	return *m_renderSystem;
}
