using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;
using Gin.Controls.Interfaces;
namespace Gin.Engine
{
    class Axis : Entity, IActiveParameter
    {
        public IntPtr pAxis;

        public Axis(IntPtr axis)
        {
            pAxis = axis;
        }


        public bool getActiveStatus()
        {
            return engine_get_axis_status(pAxis);
        }

        public void setActiveStatus(bool status)
        {
            engine_set_axis_status(pAxis, status);
        }

        public override EType getEntityType()
        {
            return EType.NONE;
        }

        public void activate()
        {
            
        }
        public void deactivate()
        {
            engine_set_axis_status(pAxis, false);
        }

        [DllImport("warzone")]
        private static extern void engine_set_axis_status(IntPtr owner, bool flag);
        
        [DllImport("warzone")]
        private static extern bool engine_get_axis_status(IntPtr axis);
    }
}
