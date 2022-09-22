using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Input;
using Gin;

namespace Gin
{
    static class Program
    {
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            MainForm editor = new MainForm();
            editor.FormClosed += QuitLoop;
            editor.Show();

            do
            {
                Application.DoEvents();
                editor.IdleTime();
                System.Threading.Thread.Sleep(1);
            } while (!mQuit);

            editor.engineDestroy();
        }


        private static bool mQuit;
        private static void QuitLoop(object sender, FormClosedEventArgs e)
        {
            mQuit = true;
        }

        private static void updateCameraInput(Engine.Camera camera)
        {
            
        }

    }
}
