using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Gin.Editor
{
    public class SelectedAgents
    {
        private List<Engine.Agent> agents;

        public SelectedAgents()
        {
            agents = new List<Engine.Agent>();
        }

        public void selectAgent(Engine.Agent agent)
        {
            clearSelected();
            agents.Add(agent);
        }
        public List<Engine.Agent> getSelectedAgents()
        {
            return agents;
        }

        public void clearSelected()
        {
            agents.Clear();
        }
    }
}
