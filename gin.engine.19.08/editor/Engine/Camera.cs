using System;
using System.Runtime.InteropServices;
using Gin.Controls.Interfaces;


namespace Gin.Engine
{
    public class Camera : Entity, ICameraParameters, IPositionParameters 
    {
        private IntPtr pEngine;
        private IntPtr pCamera;

        
        public Camera(IntPtr engine, IntPtr camera)
        {
            pEngine = engine;
            pCamera = camera;
        }

        ~Camera()
        {
            //releaseCamera(pEngine, pCamera);
        }

        public override EType getEntityType()
        {
            return EType.CAMERA;
        }


        public void move(Single x, Single y, Single z)
        {
            camera_move(pCamera, x, y, z);
        }

        public void turn(Single x, Single y, Single z)
        {
            camera_turn(pCamera, x, y, z);
        }
        public void lookAt(Single x, Single y, Single z)
        {
            camera_look_at(pCamera, x, y, z);
        }



        public Single getFow()
        {
            return camera_get_fow(pCamera);
        }

        public void setFow(Single fow)
        {
            camera_set_fow(pCamera, fow);
        }
        public void setPosition(Single x, Single y, Single z)
        {
            camera_set_position(pCamera, x, y, z);
        }

        public Vector3 getPosition() {
            return camera_get_position(pCamera);
        }
        public Vector3 getRotation() 
        { 
            return camera_get_rotation(pCamera); 
        }
        
        public void setRotation(Single x, Single y, Single z) 
        {
            camera_set_rotation(pCamera, x, y, z);
        }

        public Vector3 getScale() { return new Vector3(1, 1, 1); }
        public void setScale(Single x, Single y, Single z) 
        {
        }




        [DllImport("warzone")]
        private extern static void camera_move(IntPtr pCamera, Single x, Single y, Single z);

        [DllImport("warzone")]
        private extern static void camera_turn(IntPtr pCamera, Single x, Single y, Single z);

        [DllImport("warzone")]
        private extern static void camera_look_at(IntPtr pCamera, Single x, Single y, Single z);
        
        [DllImport("warzone")]
        private extern static void camera_set_position(IntPtr pCamera, Single x, Single y, Single z);
        
        [DllImport("warzone")]
        private extern static void camera_set_rotation(IntPtr pCamera, Single x, Single y, Single z);

        [DllImport("warzone")]
        private extern static void camera_set_fow(IntPtr pCamera, Single fow);

        [DllImport("warzone")]
        private extern static Vector3 camera_get_position(IntPtr pCamera);

        [DllImport("warzone")]
        private extern static Vector3 camera_get_rotation(IntPtr pCamera);

        [DllImport("warzone")]
        private extern static Single camera_get_fow(IntPtr pCamera);

    }
}

