using System;
using Gin.Engine;

namespace Gin.Controls.Interfaces
{
    public interface ILightParameters
    {
        Vector3 getDirection();
        void setDirection(Vector3 direction);

        Vector3 getColor();
        void setColor(Vector3 color);

        Single getIntensity();
        void setIntensity(Single position);
    }
}
