using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Gin.Engine
{
    public class Agent : Entity
    {
        private IntPtr pAgent;

        public Agent(IntPtr handler)
        {
            pAgent = handler;
        }

        public IntPtr getPtr()
        {
            return pAgent;
        }

        public override EType getEntityType()
        {
            return EType.AGENT;
        }
    }
}
