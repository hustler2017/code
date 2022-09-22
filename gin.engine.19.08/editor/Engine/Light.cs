using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
using Gin.Controls.Interfaces;

namespace Gin.Engine
{
    public class Light : Entity , ILightParameters, IPositionParameters
    {
        public IntPtr pEngine;
        public IntPtr pLight;

        public Light(IntPtr engine, IntPtr light)
        {
            pEngine = engine;
            pLight = light;
        }

        public Vector3 getDirection()
        {
            return engine_get_light_direction(pLight);
        }
        public void setDirection(Vector3 direction)
        {
            engine_set_light_direction(pLight, direction);
        }

        public Vector3 getColor()
        {
            return engine_get_light_color(pLight);
        }
        public void setColor(Vector3 color)
        {
            engine_set_light_color(pLight, color);
        }

        public Single getIntensity()
        {
            return engine_get_light_intensity(pLight);
        }
        public void setIntensity(Single intensity)
        {
            engine_set_light_intensity(pLight, intensity);
        }

        public override EType getEntityType()
        {
            return EType.LIGHT;
        }

        public Vector3 getPosition()
        {
            return engine_get_light_position(pLight);
        }
        public Vector3 getRotation()
        {
            return new Vector3(0, 0, 0);
        }
        public Vector3 getScale()
        {
            return new Vector3(1, 1, 1);
        }
        public void setPosition(Single x, Single y, Single z)
        {
            engine_set_light_position(pLight, new Vector3(x, y, z));
        }
        public void setRotation(Single x, Single y, Single z)
        {

        }
        public void setScale(Single x, Single y, Single z)
        {

        }



        [DllImport("warzone.dll")]
        private static extern Vector3 engine_get_light_direction(IntPtr light);

        [DllImport("warzone.dll")]
        private static extern void engine_set_light_direction(IntPtr light, Vector3 dir);

        [DllImport("warzone.dll")]
        private static extern Vector3 engine_get_light_color(IntPtr light);

        [DllImport("warzone.dll")]
        private static extern void engine_set_light_color(IntPtr light, Vector3 color);

        [DllImport("warzone.dll")]
        private static extern Vector3 engine_get_light_position(IntPtr light);

        [DllImport("warzone.dll")]
        private static extern void engine_set_light_position(IntPtr light, Vector3 pos);

        [DllImport("warzone.dll")]
        private static extern float engine_get_light_intensity(IntPtr light);

        [DllImport("warzone.dll")]
        private static extern void engine_set_light_intensity(IntPtr light, float intensity);






    }

}

