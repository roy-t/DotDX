using System.Numerics;
using DotDX.Native;

namespace DotDX.Interop
{
    public class GraphicsDevice
    {
        private Window window;

        public void Initialize()
        {
            this.window = new Window();
            this.window.Initialize(false, "Hello World!", new Vector3(0, 0, 0));
        }

        public void Shutdown() => this.window.Dispose();
    }
}
