#include "Window.h"
#include <msclr\marshal_cppstd.h>

namespace DotDX
{
    namespace Native
    {
        public class NativeWindow
        {
        private:
            HWND windowHandle;
            HINSTANCE instance;
        public:
            HRESULT Initialize(const wchar_t* title)
            {
                //// Continue from: https://www.rastertek.com/dx11s2tut02.html
                // TODO: follow the actual code from rastertek instead of this abomination
                instance = GetModuleHandle(NULL);

                const wchar_t CLASS_NAME[] = L"DotDX.Native";
                WNDCLASSEX wc = { };
                wc.lpfnWndProc = NativeWindow::WindowProc;
                wc.hInstance = instance;
                wc.lpszClassName = CLASS_NAME;

                HRESULT r = RegisterClassEx(&wc);

                windowHandle = CreateWindowEx(
                    0,
                    CLASS_NAME,
                    title,
                    WS_OVERLAPPEDWINDOW,
                    CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                    NULL,
                    NULL,
                    instance,
                    NULL
                );

                ShowWindow(windowHandle, SW_SHOW);
                DWORD error = GetLastError();
                return S_OK;
            }

            static LRESULT NativeWindow::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
            {
                switch (uMsg)
                {
                case WM_DESTROY:
                    PostQuitMessage(0);
                    return 0;

                case WM_PAINT:
                {
                    PAINTSTRUCT ps;
                    HDC hdc = BeginPaint(hwnd, &ps);

                    FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

                    EndPaint(hwnd, &ps);
                }
                return 0;

                }
                return DefWindowProc(hwnd, uMsg, wParam, lParam);
            }
        };

        public ref class Window
        {
        private:
            NativeWindow *pNativeWindow;

        public:

            Window() { }
            ~Window() { if (pNativeWindow != nullptr) { delete pNativeWindow; } }

            void Initialize(bool fullScreen, System::String^ title, System::Numerics::Vector3 vec)
            {
                pNativeWindow = new NativeWindow();

                std::wstring unmanaged = msclr::interop::marshal_as<std::wstring>(title);
                pNativeWindow->Initialize(unmanaged.c_str());
            }        
        };        
    }
}