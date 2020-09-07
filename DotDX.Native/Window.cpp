#include "Window.h"
#include "System.h"
#include <msclr\marshal_cppstd.h>

namespace DotDX
{
    namespace Native
    {        
        public ref class Window
        {
        private:
            SystemClass* pSystem;

        public:

            Window() { }
            ~Window() {
                if (pSystem != nullptr) 
                {
                    pSystem->Shutdown();
                    delete pSystem;
                    pSystem = nullptr;
                }
            }

            void Initialize(bool fullScreen, System::String^ title, System::Numerics::Vector3 vec)
            {
                pSystem = new SystemClass();
                pSystem->Initialize();
                pSystem->Run();
                
                //std::wstring unmanaged = msclr::interop::marshal_as<std::wstring>(title);
                //pNativeWindow->Initialize(unmanaged.c_str());
            }        
        };        
    }
}