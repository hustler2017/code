using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace Gin.Engine
{
    class Manipulator
    {
        public IntPtr pManipulator;
        public IntPtr pEngine;
        public ManipulatorElement controlElement;
        public Object targetObject;
        private Single multiplier;

        private bool visible;
        public enum ManipulatorElement
        {
            NONE,
            MOVE_X,
            MOVE_Y,
            MOVE_Z,
            ROT_X,
            ROT_Y,
            ROT_Z,
            SCALE_X,
            SCALE_Y,
            SCALE_Z
        }


        public Manipulator(IntPtr engine, IntPtr manipulator)
        {
            pEngine = engine;
            pManipulator = manipulator;
            visible = false;
            multiplier = 0.05f;
        }

        public void setTargetObject(Object target)
        {
            targetObject = target;
            engine_manipulator_set_target(pManipulator, target.getPtr());
            setVisible(true);
        }

        public Manipulator.ManipulatorElement getPickedElement(int x, int y)
        {
            return (Manipulator.ManipulatorElement)engine_check_manipulator_picking(pManipulator, x, y);
        }

        public void setControlElement(ManipulatorElement elem)
        {
            controlElement = elem;
        }

        public void controlSelectedElement(Single dx, Single dy)
        {
            Vector3 vector;

            switch (controlElement)
            {
                case ManipulatorElement.MOVE_X:
                    vector = targetObject.getPosition();
                    targetObject.setPosition(vector.x + dy * multiplier, vector.y, vector.z);
                    break;
                case ManipulatorElement.MOVE_Y:
                    vector = targetObject.getPosition();
                    targetObject.setPosition(vector.x, vector.y + dy * multiplier, vector.z);
                    break;
                case ManipulatorElement.MOVE_Z:
                    vector = targetObject.getPosition();
                    targetObject.setPosition(vector.x, vector.y, vector.z + dy * multiplier);
                    break;
                case ManipulatorElement.ROT_X:
                    vector = targetObject.getRotation();
                    targetObject.setRotation(vector.x + dy * multiplier, vector.y, vector.z);
                    break;
                case ManipulatorElement.ROT_Y:
                    vector = targetObject.getRotation();
                    targetObject.setRotation(vector.x, vector.y + dy * multiplier, vector.z);
                    break;
                case ManipulatorElement.ROT_Z:
                    vector = targetObject.getRotation();
                    targetObject.setRotation(vector.x, vector.y, vector.z + dy * multiplier);
                    break;
                case ManipulatorElement.SCALE_X:
                    vector = targetObject.getScale();
                    targetObject.setScale(vector.x + dy * multiplier, vector.y, vector.z);
                    break;
                case ManipulatorElement.SCALE_Y:
                    vector = targetObject.getScale();
                    targetObject.setScale(vector.x, vector.y + dy * multiplier, vector.z);
                    break;
                case ManipulatorElement.SCALE_Z:
                    vector = targetObject.getScale();
                    targetObject.setScale(vector.x, vector.y, vector.z + dy * multiplier);
                    break;
            }

            

        }


        public void setVisible(bool flag)
        {
            visible = flag;
            engine_show_manipulator(pManipulator, flag);
        }

        public void clearTarget()
        {
            if (targetObject == null)
                return;

            targetObject = null;
            engine_manipulator_set_target(pManipulator, IntPtr.Zero);
            setVisible(false);
        }

        [DllImport("warzone")]
        private static extern int engine_check_manipulator_picking(IntPtr pManipulator, int x, int y);

        [DllImport("warzone")]
        private static extern int engine_show_manipulator(IntPtr pManipulator, bool flag);

        [DllImport("warzone")]
        private static extern IntPtr engine_get_manipulator(IntPtr pEngine);

        [DllImport("warzone")]
        private static extern void engine_manipulator_set_target(IntPtr pManipulator, IntPtr obj);
    }
}
