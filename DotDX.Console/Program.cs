using DotDX.Interop;

namespace DotDX.Console
{
    class Program
    {
        static void Main(string[] args)
        {
            System.Console.WriteLine("Hello World!");
            var graphics = new GraphicsDevice();
            graphics.Initialize();

            System.Console.ReadLine();
            graphics.Shutdown();
        }
    }
}
