#include <DX3D/Graphics/GraphicsEngine.h>
#include<DX3D/Graphics/GraphicsDevice.h>
#include<DX3D/Graphics/DeviceContext.h>
#include<DX3D/Graphics/SwapChain.h>

using namespace dx3d;

dx3d::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc): Base(desc.Base)
	
{

	m_graphicsDevice = std::make_shared<GraphicsDevice>(GraphicsDeviceDesc{m_logger});

	auto& device = *m_graphicsDevice;
	m_deviceContext = device.createDeviceContext();

	constexpr char shaderSourceCode[] =
		R"(
void VSMain()
{

}
void PSMain()
{
}
)";

	constexpr char shaderSourceName[] = "Basic";
	constexpr auto shaderSourceSize = std::size(shaderSourceCode);

	auto vs =  device.CompileShader({shaderSourceName , shaderSourceCode , shaderSourceSize , 
		"VSMain"  , dx3d::ShaderType::VertexShader});

	auto ps =  device.CompileShader({shaderSourceName , shaderSourceCode , shaderSourceSize , 
		"PSMain"  , dx3d::ShaderType::PixelShader});

	m_Pipeline = device.createGraphicsPipelineStates({*vs , *ps});
}



dx3d::GraphicsEngine::~GraphicsEngine()
{
}

GraphicsDevice& dx3d::GraphicsEngine::GetGraphicsDevice() const noexcept
{
	return *m_graphicsDevice;
}

void dx3d::GraphicsEngine::render(SwapChain& swapChain)
{

	auto& context = *m_deviceContext;
	context.clearAndSetBackBuffer(swapChain, { 1,0,0,1 });
	context.setGraphicsPipelineStates(*m_Pipeline);

	auto& device = *m_graphicsDevice;
	device.executeCommandList(context);
	swapChain.present();
}
