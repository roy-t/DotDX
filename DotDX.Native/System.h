#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace DotDX 
{
	namespace Native
	{
		class InputClass;
		class GraphicsClass;

		public class SystemClass
		{
		public:
			SystemClass();

			bool Initialize(const wchar_t* title);
			void Shutdown();
			bool HandleMessages();
			bool RenderFrame();

			LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

		private:			
			void InitializeWindows(const wchar_t* title, int&, int&);
			void ShutdownWindows();

		private:
			LPCWSTR m_applicationName;
			HINSTANCE m_hinstance;
			HWND m_hwnd;

			InputClass* m_Input;
			GraphicsClass* m_Graphics;
		};

		static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

		static SystemClass* ApplicationHandle = 0;
	}
}