#pragma once

#include<DX3D/Graphics/GraphicsResource.h>
#include<DX3D/Core/Common.h>

namespace dx3d
{
	class GraphicsPipelineStates final: public GraphicsResource
	{
	public:
		GraphicsPipelineStates(const GraphicsPipelineStatesDesc& desc ,const GraphicsResourceDesc& gDesc);
	private:
		Microsoft::WRL::ComPtr<ID3D11VertexShader> m_vs;
		Microsoft::WRL::ComPtr<ID3D11PixelShader> m_ps;

		friend class DeviceContext;
	};
}
