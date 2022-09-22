using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Gin.Editor.Input.Controller
{
    class ManipulatorInputController : InputController
    {
        private Engine.Manipulator m_manipulator;

        private int lastCursorX;
        private int lastCursorY;
        public ManipulatorInputController(Engine.Manipulator manipulator)
        {
            m_manipulator = manipulator;
        }

        public override void onActivate()
        {
            lastCursorX = System.Windows.Forms.Cursor.Position.X;
            lastCursorY = System.Windows.Forms.Cursor.Position.Y;
        }

        public override void onMouseMove(int x, int y)
        {
            int deltaX = System.Windows.Forms.Cursor.Position.X - lastCursorX;
            int deltaY = System.Windows.Forms.Cursor.Position.Y - lastCursorY;

            lastCursorX = System.Windows.Forms.Cursor.Position.X;
            lastCursorY = System.Windows.Forms.Cursor.Position.Y;

            m_manipulator.controlSelectedElement(deltaX, deltaY);
        }

        public override void onMouseLeftUp(int x, int y) 
        {
            state.exit();
        }
    }
}
