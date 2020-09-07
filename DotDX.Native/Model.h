#pragma once

#pragma warning(push)
#pragma warning(disable: 4793) // methods are compiled as native (clr warning)
#include <d3d11.h>
#include <directxmath.h>
#pragma warning(pop)

using namespace DirectX;

namespace DotDX
{
	namespace Native
	{
		class ModelClass
		{
		private:
			struct VertexType
			{
				XMFLOAT3 position;
				XMFLOAT4 color;
			};

		public:
			ModelClass();
			bool Initialize(ID3D11Device*);
			void Shutdown();
			void Render(ID3D11DeviceContext*);

			int GetIndexCount();

		private:
			bool InitializeBuffers(ID3D11Device*);
			void ShutdownBuffers();
			void RenderBuffers(ID3D11DeviceContext*);
		
		private:
			ID3D11Buffer* m_vertexBuffer, * m_indexBuffer;
			int m_vertexCount, m_indexCount;
		};
	}
}
