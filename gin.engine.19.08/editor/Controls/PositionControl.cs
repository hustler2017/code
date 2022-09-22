using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Gin.Controls.Interfaces;
using Gin.Engine;

namespace Gin.Controls
{
    public partial class PositionControl : UserControl, IParametersControl
    {
        private IPositionParameters m_object;

        public bool setDataObject(object obj)
        {
            if (obj is IPositionParameters)
            {
                m_object = (IPositionParameters)obj;
                initControl();
                return true;
            }

            return false;
        }


        public void initControl()
        {
            Vector3 pos = m_object.getPosition();

            positionX.Value = (decimal)pos.x;
            positionY.Value = (decimal)pos.y;
            positionZ.Value = (decimal)pos.z;

            Vector3 scl = m_object.getScale();

            scaleX.Value = (decimal)scl.x;
            scaleY.Value = (decimal)scl.y;
            scaleZ.Value = (decimal)scl.z;

            Vector3 rot = m_object.getRotation();

            rotationX.Value = (decimal)rot.x;
            rotationY.Value = (decimal)rot.y;
            rotationZ.Value = (decimal)rot.z;
        }


        public PositionControl()
        {
            InitializeComponent();
        }

        private void position_ValueChanged(object sender, EventArgs e)
        {
            Vector3 pos = new Vector3((Single)positionX.Value, (Single)positionY.Value, (Single)positionZ.Value);
            m_object.setPosition(pos.x, pos.y, pos.z);
        }

        private void rotation_ValueChanged(object sender, EventArgs e)
        {
            Vector3 rot = new Vector3((Single)rotationX.Value, (Single)rotationY.Value, (Single)rotationZ.Value);
            m_object.setRotation(rot.x, rot.y, rot.z);
        }

        private void scale_ValueChanged(object sender, EventArgs e)
        {
            Vector3 scl = new Vector3((Single)scaleX.Value, (Single)scaleY.Value, (Single)scaleZ.Value);
            m_object.setScale(scl.x, scl.y, scl.z);
        }
    }
}
