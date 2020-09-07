#pragma once

#pragma warning(push)
#pragma warning(disable: 4793) // methods are compiled as native (clr warning)
#include <d3d11.h>
#pragma warning(pop)
#include <fstream>

namespace DotDX
{
	namespace Native
	{
		class TextureClass
		{
		private:
			struct TargaHeader
			{
				unsigned char data1[12];
				unsigned short width;
				unsigned short height;
				unsigned char bpp;
				unsigned char data2;
			};

		public:
			TextureClass();

			bool Initialize(ID3D11Device*, ID3D11DeviceContext*, wchar_t*);
			void Shutdown();

			ID3D11ShaderResourceView* GetTexture();

		private:
			bool LoadTarga(wchar_t*, int&, int&);
			unsigned char* m_targaData;
			ID3D11Texture2D* m_texture;
			ID3D11ShaderResourceView* m_textureView;
		};
	}
}