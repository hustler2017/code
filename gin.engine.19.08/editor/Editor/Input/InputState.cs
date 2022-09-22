using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Gin.Editor.Input.Controller;

namespace Gin.Editor.Input
{
    class InputState
    {
        public InputController m_controller;
        public InputState m_parent;
        public Dictionary<string, InputState> m_substates;
        public InputStateTree m_parent_tree;

        public InputState(InputState parent, InputController controller)
        {
            m_controller = controller;
            m_parent = parent;
            m_controller.state = this;
            m_substates = new Dictionary<string, InputState>();
        }

        public void exit()
        {
            m_parent_tree.exitState();
        }

        public void setSubstate(string key)
        {
            m_parent_tree.setSubstate(key);
        }

        public void addSubstate(string key, InputState state)
        {
            m_substates[key] = state;
        }

    }
}
