#include <DX3D/Game/Game.h>
#include <DX3D/Window/Window.h>
#include<DX3D/Graphics/GraphicsEngine.h>

dx3d::Game::Game()
{

	m_graphicEngine = std::make_unique<GraphicsEngine>();
	m_Display = std::make_unique<Window>();
	
}

dx3d::Game::~Game()
{
}

