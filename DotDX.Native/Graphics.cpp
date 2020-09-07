#include "Graphics.h"

namespace DotDX
{
	namespace Native
	{

		GraphicsClass::GraphicsClass()
		{
		}

		bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
		{
			return true;
		}


		void GraphicsClass::Shutdown()
		{
			return;
		}


		bool GraphicsClass::Frame()
		{
			return true;
		}


		bool GraphicsClass::Render()
		{
			return true;
		}
	}
}