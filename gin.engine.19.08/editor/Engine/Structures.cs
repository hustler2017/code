using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;



namespace Gin.Engine
{

    public enum EType
    {
        NONE,
        CAMERA,
        LIGHT,
        MODEL,
        OBJECT,
        TERRAIN,
        TEXTURE,
        AGENT
    }



    [StructLayout(LayoutKind.Sequential)]
    public struct Vector3
    {
        public Single x;
        public Single y;
        public Single z;

        public Vector3(Single _x, Single _y, Single _z)
        {
            x = _x;
            y = _y;
            z = _z;
        }

    }

    [StructLayout(LayoutKind.Sequential)]
    public struct Vector2
    {
        public Single x;
        public Single y;

        public Vector2(Single _x, Single _y)
        {
            x = _x;
            y = _y;
        }

    }
}



