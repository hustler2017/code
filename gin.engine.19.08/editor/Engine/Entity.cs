using System.Collections.Generic;

namespace Gin.Engine
{
    public class Entity
    {
        public string name;
        
        virtual public EType getEntityType()
        {
            return EType.NONE;
        }
    }
}
