using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Gin.Editor.Input
{
    class InputStateTree
    {
        public InputState m_current;

        public void addState(InputState state)
        {
            state.m_parent_tree = this;
        }

        public void shutsown()
        {
            while(m_current.m_parent != null)
            {
                exitState();
            }   
        }

        public InputStateTree()
        {

        }

        public void exitState()
        {
            m_current.m_controller.onTerminate();
            m_current = m_current.m_parent;
        }

        public void setSubstate(string key)
        {
            m_current = m_current.m_substates[key];
            m_current.m_controller.onActivate();
        }

        public Input.Controller.InputController getController()
        {
            return m_current.m_controller;
        }
    }
}
