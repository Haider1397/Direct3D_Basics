#
#include <DX3D/Game/Game.h>
#include<DX3D/Graphics/GraphicsEngine.h>
#include<DX3D/Game/Display.h>
#include<DX3D/Core/Logger.h>

dx3d::Game::Game(const GameDesc& desc):
	Base({ *std::make_unique<Logger>(desc.logLevel).release()}),
	m_loggerPtr(&m_logger)
	
{
	m_graphicEngine = std::make_unique<GraphicsEngine>(GraphicsEngineDesc{m_logger});
	m_Display = std::make_unique<Display>(DisplayDesc{ {m_logger,desc.windowSize} , m_graphicEngine->GetGraphicsDevice()});
	
	DX3DLogInfo("Game Initalized.");
}


dx3d::Game::~Game()
{
	DX3DLogInfo("Game is Shutting Down.");
}

void dx3d::Game::onInternaUpdate()
{
	m_graphicEngine->render(m_Display->getSwapChain());
}


