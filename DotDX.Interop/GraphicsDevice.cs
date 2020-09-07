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
            this.window.Initialize(false, "Hello World!", Vector3.Zero);
        }

        public void Shutdown() => this.window.Dispose();
    }
}
