#pragma once
#include<DX3D/Core/Base.h>
#include<DX3D/Core/Core.h>

namespace dx3d
{

	class Game : public Base
	{
	public:

		explicit Game(const GameDesc& desc);
		virtual ~Game() override;

		virtual void run() final;

	private:
		std::unique_ptr<Logger> m_loggerPtr{};
		std::unique_ptr<GraphicsEngine> m_graphicEngine{};
		std::unique_ptr<Display> m_Display{};
		bool m_isRunning{ true };
	};

}