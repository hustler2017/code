using System;
using System.Windows.Forms;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Gin.Editor;

namespace Gin.Editor.Input.Controller
{
    class GameModeBase : InputController
    {
        Engine.Engine engine;
        SelectedAgents selectedAgents;
        Dictionary<string, Engine.Agent> agents;
        Panel mp;
        public GameModeBase(Engine.Engine e, Panel p, SelectedAgents selected, Dictionary<string, Engine.Agent> a)
        {
            engine = e;
            selectedAgents = selected;
            agents = a;
            mp = p;
        }

        public override void onMouseDownLeft(int x, int y)
        {
            mp.Focus();

            IntPtr ptr = engine.getPickedAgent(x, y, 0);
            if (ptr != IntPtr.Zero)
            {
                Engine.Agent obj = Editor.Helper.findAgentByPtr(ptr, agents);

                if (obj != null)
                {
                    selectedAgents.selectAgent(obj);
                    return;
                }
            }
            selectedAgents.clearSelected();

        }

        public override void onMouseDownRight(int x, int y)
        {
            Console.WriteLine("right click");
            engine.commnadMove(selectedAgents.getSelectedAgents(), x, y);
            
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
