using System;
using System.Collections.Generic;
using System.Text;

namespace Gin.Controls.Interfaces
{
    public interface IGridParameter
    {
        void setSize(Single size);
        void setDensity(Single size);

        Single getSize();
        Single getDensity();
    }
}
