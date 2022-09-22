using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Gin.Editor
{
    class Helper
    {
        public static Engine.Object findObjectByPtr(IntPtr ptr, Dictionary<string, Engine.Object> objects)
        {
            foreach (KeyValuePair<string, Engine.Object> entry in objects)
            {
                if (entry.Value.getPtr() == ptr)
                {
                    return entry.Value;
                }
            }

            return null;
        }

        public static Engine.Agent findAgentByPtr(IntPtr ptr, Dictionary<string, Engine.Agent> agents)
        {
            foreach (KeyValuePair<string, Engine.Agent> entry in agents)
            {
                if (entry.Value.getPtr() == ptr)
                {
                    return entry.Value;
                }
            }

            return null;
        }

    }
}
