using System;
using System.IO;
using System.Runtime.InteropServices;
using Gin.Controls.Interfaces;

namespace Gin.Engine
{
    public class Object : Entity, IPositionParameters, IAnimationParameter
    {


        public IntPtr pEngine;
        public IntPtr pObject;

        public bool manipulable;

        public Object(IntPtr engine, IntPtr obj)
        {
            pObject = obj;
            pEngine = engine;
            manipulable = true;
        }

        ~Object()
        {

        }


        public IntPtr getPtr()
        {
            return pObject;
        }

        public override EType getEntityType()
        {
            return EType.OBJECT;
        }
        public Vector3 getPosition()
        {
            return engine_get_object_position(pEngine, pObject);
        }
        public Vector3 getRotation()
        {
            return engine_get_object_rotation(pEngine, pObject);
        }
        public Vector3 getScale()
        {
            return engine_get_object_scale(pEngine, pObject);
        }
        public void setPosition(Single x, Single y, Single z)
        {
            engine_set_object_position(pEngine, pObject, new Vector3(x, y, z));
        }
        public void setRotation(Single x, Single y, Single z)
        {
            engine_set_object_rotation(pEngine, pObject, new Vector3(x,y,z));
        }
        public void setScale(Single x, Single y, Single z)
        {
            engine_set_object_scale(pEngine, pObject, new Vector3(x, y, z));
        }



        public string getAnimationNames()
        {
            return engine_get_object_animation_names(pObject);
        }
        public void loadAnimation(string filename, string name)
        {
            engine_load_object_animation(pEngine, pObject, filename, name);
        }
        public void playAnimation(string key)
        {
            engine_play_object_animation(pObject, key);
        }


        [DllImport("warzone.dll")]
        private static extern Vector3 engine_get_object_position(IntPtr engine, IntPtr obj);

        [DllImport("warzone.dll")]
        private static extern void engine_set_object_position(IntPtr engine, IntPtr obj, Vector3 pos);

        [DllImport("warzone.dll")]
        private static extern Vector3 engine_get_object_rotation(IntPtr engine, IntPtr obj);

        [DllImport("warzone.dll")]
        private static extern void engine_set_object_rotation(IntPtr engine, IntPtr obj, Vector3 rot);

        [DllImport("warzone.dll")]
        private static extern Vector3 engine_get_object_scale(IntPtr engine, IntPtr obj);

        [DllImport("warzone.dll")]
        private static extern void engine_set_object_scale(IntPtr engine, IntPtr obj, Vector3 scale);




        [DllImport("warzone.dll")]
        [return: MarshalAs(UnmanagedType.BStr)]
        private static extern string engine_get_object_animation_names(IntPtr obj);

        [DllImport("warzone.dll")]
        private static extern int engine_load_object_animation(IntPtr engine, IntPtr obj, [MarshalAs(UnmanagedType.LPStr)] string filename, [MarshalAs(UnmanagedType.LPStr)] string name);

        [DllImport("warzone.dll")]
        private static extern void engine_play_object_animation(IntPtr obj, [MarshalAs(UnmanagedType.LPStr)] string key);

    }


}



