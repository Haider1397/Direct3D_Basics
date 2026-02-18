#include <DX3D/Graphics/GraphicsPipelineStates.h>
#include<DX3D/Graphics/ShaderBinary.h>


dx3d::GraphicsPipelineStates::GraphicsPipelineStates(const GraphicsPipelineStatesDesc& desc, const GraphicsResourceDesc& gDesc):
	
	GraphicsResource(gDesc)
{
	if (desc.vs.getType() != dx3d::ShaderType::VertexShader)
		DX3DLogThrowInvalidArg("Invalid Argument vs");

	if (desc.ps.getType() != dx3d::ShaderType::PixelShader)
		DX3DLogError("Invalid Argument ps");

	auto vs = desc.vs.getData();
	auto ps = desc.ps.getData();

	DX3DGraphicsLogThrowOnFail(m_device.CreateVertexShader(vs.data,vs.dataSize,nullptr,&m_vs),
		"CreateVertexShader failed.");

	DX3DGraphicsLogThrowOnFail(m_device.CreatePixelShader(ps.data,ps.dataSize,nullptr,&m_ps),
		"CreatePixelShader failed.");
}
