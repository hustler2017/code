using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Gin.Editor.Input;

namespace Gin.Editor.Input.Controller
{
    class InputController
    {
        public InputState state;

        public virtual void onActivate() {}
        public virtual void onTerminate() {}

        public virtual void onMouseDownLeft(int x, int y) {}

        public virtual void onMouseMove(int x, int y) {}

        public virtual void onMouseMiddleUp(int x, int y) { }
        public virtual void onMouseDownMiddle(int x, int y) { }
        public virtual void onMouseLeftUp(int x, int y) {}
        public virtual void onMouseDownRight(int x, int y) {}

        public virtual void onMouseRightUp(int x, int y) {}

        public virtual void onKeyDown(KeyEventArgs e) {}
        public virtual void onKeyUp(KeyEventArgs e) {}

        public virtual void Idle() {}
    }
}
