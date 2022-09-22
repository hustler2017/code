using System;
using System.Collections.Generic;
using System.Text;

namespace Gin.Controls.Interfaces
{
    public interface IActiveParameter
    {
        bool getActiveStatus();
        void setActiveStatus(bool status);
    }
}
