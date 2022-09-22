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

namespace Gin.Controls
{
    public partial class LightControl : UserControl, IParametersControl
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
            IntensityField.Value = (decimal)m_object.getIntensity();
            Gin.Engine.Vector3 v = m_object.getDirection();

            directionX.Value = (decimal)v.x;
            directionY.Value = (decimal)v.y;
            directionZ.Value = (decimal)v.z;

            Gin.Engine.Vector3 c = m_object.getColor();
            Color pickerColor = Color.FromArgb((int)(256 * c.x), (int)(256 * c.y), (int)(256 * c.x));
            ColorPick.BackColor = pickerColor;

            colorDialog.AllowFullOpen = false;
        }
        public LightControl()
        {
            InitializeComponent();
        }

        private void ColorPick_MouseClick(object sender, MouseEventArgs e)
        {
            if(colorDialog.ShowDialog() == DialogResult.OK)
            {
                ColorPick.BackColor = colorDialog.Color;
                m_object.setColor(
                    new Engine.Vector3(
                        ColorPick.BackColor.R,
                        ColorPick.BackColor.G,
                        ColorPick.BackColor.B
                        )
                    );
            }
        }

        private void direction_ValueChanged(object sender, EventArgs e)
        {
            m_object.setDirection(
                new Engine.Vector3(
                    (Single)directionX.Value,
                    (Single)directionY.Value,
                    (Single)directionZ.Value
                    )
                );
        }

        private void intensityField_ValueChanged(object sender, EventArgs e)
        {
            m_object.setIntensity((Single)IntensityField.Value);
        }
    }
}
