using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Gin.Editor.Input;
using Gin.Engine;

namespace Gin.Editor.Input.Controller
{
    class BaseInputController : InputController
    {
        Engine.Engine engine;
        Engine.Manipulator manipulator;
        Dictionary<string, Engine.Object> objects;
        Panel mp;
        public BaseInputController(Engine.Engine e, Engine.Manipulator m, Dictionary<string, Engine.Object> objs, Panel p)
        {
            engine = e;
            manipulator = m;
            objects = objs;
            mp = p;
        }

        public override void onMouseDownLeft(int x, int y)
        {
            mp.Focus();

            Engine.Manipulator.ManipulatorElement elem = manipulator.getPickedElement(x, y);

            if(elem != 0)
            {
                manipulator.setControlElement(elem);
                state.setSubstate("object_move");
                return;
            }

            IntPtr ptr = engine.getPickedObject(x, y, 0);
            if(ptr != IntPtr.Zero)
            {
                Engine.Object obj = Editor.Helper.findObjectByPtr(ptr, objects);
                
                if(obj != null)
                {
                    manipulator.setTargetObject(obj);
                    return;
                }
            }

            manipulator.clearTarget();
        }

        public override void onMouseDownRight(int x, int y)
        {
            
        }

        public override void onKeyDown(KeyEventArgs e)
        {

        }

        public override void onMouseDownMiddle(int x, int y) 
        {
            mp.Focus();
            state.setSubstate("camera_move");
        }

    }
}
