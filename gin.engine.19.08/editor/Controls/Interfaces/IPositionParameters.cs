
using System;
using Gin.Engine;

namespace Gin.Controls.Interfaces
{
    public interface IPositionParameters
    {
        Vector3 getPosition();
        Vector3 getRotation();
        Vector3 getScale();
        void setPosition(Single x, Single y, Single z);
        void setRotation(Single x, Single y, Single z);
        void setScale(Single x, Single y, Single z);
    }
}
