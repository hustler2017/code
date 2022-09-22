using System;
using System.Windows.Forms;

namespace Gin.Editor.Input.Controller
{
    class CameraMoveInputController : InputController
    {
        Engine.Camera m_camera;

        private Single cursorX;
        private Single cursorY;

        private bool key_w;
        private bool key_a;
        private bool key_s;
        private bool key_d;
        private float speed;

        public CameraMoveInputController(Engine.Camera camera)
        {
            m_camera = camera;
            speed = 1.5f;
        }

        public override void onActivate()
        {

            cursorX = System.Windows.Forms.Cursor.Position.X;
            cursorY = System.Windows.Forms.Cursor.Position.Y;

            key_w = false;
            key_a = false;
            key_s = false;
            key_d = false;
        }

        public override void onTerminate()
        {
            System.Windows.Forms.Cursor.Show();
        }

        public override void onMouseMove(int x, int y)
        {
            Single deltaX = System.Windows.Forms.Cursor.Position.X - cursorX;
            Single deltaY = System.Windows.Forms.Cursor.Position.Y - cursorY;

            System.Windows.Forms.Cursor.Position = new System.Drawing.Point((int)cursorX, (int)cursorY);

            Single multiplyer = 0.01f;

            m_camera.turn(-deltaY * multiplyer, 0, -deltaX * multiplyer);
        }

        public override void onMouseMiddleUp(int x, int y)
        {
            state.exit();
        }

        public override void onKeyDown(KeyEventArgs e)
        {
            switch(e.KeyCode)
            {
                case Keys.W: key_w = true; break;
                case Keys.A: key_a = true; break;
                case Keys.S: key_s = true; break;
                case Keys.D: key_d = true; break;
            }
        }

        public override void onKeyUp(KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.W: key_w = false; break;
                case Keys.A: key_a = false; break;
                case Keys.S: key_s = false; break;
                case Keys.D: key_d = false; break;
            }
        }

        public override void Idle()
        {
            if (key_w) m_camera.move(0.0f, 0.0f, speed);
            if (key_a) m_camera.move(-speed, 0.0f, 0.0f);
            if (key_s) m_camera.move(0.0f, 0.0f, -speed);
            if (key_d) m_camera.move(speed, 0.0f, 0.0f);

        }
    }
}
