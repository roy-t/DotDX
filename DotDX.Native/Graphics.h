#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace DotDX
{
	namespace Native
	{

		const bool FULL_SCREEN = false;
		const bool VSYNC_ENABLED = true;
		const float SCREEN_DEPTH = 1000.0f;
		const float SCREEN_NEAR = 0.1f;

		class GraphicsClass
		{
		public:
			GraphicsClass();

			bool Initialize(int, int, HWND);
			void Shutdown();
			bool Frame();

		private:
			bool Render();

		private:

		};
	}
}
