using System;
using System.Windows.Forms;
using Gin.Controls.Interfaces;
using Gin.Engine;

namespace Gin.Controls
{
    public partial class DirectionControl : UserControl, IParametersControl
    {
        private ILightParameters m_object;

        public bool setDataObject(object obj)
        {
            if (obj is ILightParameters)
            {
                m_object = (ILightParameters)obj;
                initControl();
                return true;
            }

            return false;
        }

        private void initControl() 
        {
            Vector3 dir = m_object.getDirection();
            directionX.Value = (decimal)dir.x;
            directionY.Value = (decimal)dir.y;
            directionZ.Value = (decimal)dir.z;
        }
        public DirectionControl()
        {
            InitializeComponent();
        }

        private void direction_ValueChanged(object sender, EventArgs e)
        {
            Vector3 direction = new Vector3((Single)directionX.Value, (Single)directionY.Value, (Single)directionZ.Value);
            m_object.setDirection(direction);
        }
    }
}
