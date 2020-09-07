#pragma once

#pragma warning(push)
#pragma warning(disable: 4793) // methods are compiled as native (clr warning)
#include <d3d11.h>
#include <d3dcompiler.h>
#include <directxmath.h>
#pragma warning(pop)
#include <fstream>
using namespace DirectX;
using namespace std;

namespace DotDX
{
	namespace Native
	{
		class ColorShaderClass
		{
		private:
			struct MatrixBufferType
			{
				XMMATRIX world;
				XMMATRIX view;
				XMMATRIX projection;
			};

		public:
			ColorShaderClass();
			bool Initialize(ID3D11Device*, HWND);
			void Shutdown();
			bool Render(ID3D11DeviceContext*, int, XMMATRIX, XMMATRIX, XMMATRIX);

		private:
			bool InitializeShader(ID3D11Device*, HWND, WCHAR*, WCHAR*);
			void ShutdownShader();
			void OutputShaderErrorMessage(ID3D10Blob*, HWND, WCHAR*);

			bool SetShaderParameters(ID3D11DeviceContext*, XMMATRIX, XMMATRIX, XMMATRIX);
			void RenderShader(ID3D11DeviceContext*, int);

		private:
			ID3D11VertexShader* m_vertexShader;
			ID3D11PixelShader* m_pixelShader;
			ID3D11InputLayout* m_layout;
			ID3D11Buffer* m_matrixBuffer;
		};
	}
}