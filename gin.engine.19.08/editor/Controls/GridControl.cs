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
    public partial class GridControl : UserControl, IParametersControl
    {
        private IGridParameter m_object;

        public bool setDataObject(object obj)
        {
            if(obj is IGridParameter)
            {
                m_object = (IGridParameter)obj;
                initControl();
            }

            return false;
        }

        private void initControl()
        {
            GridSizeField.Value = (decimal)m_object.getSize();
            GridDensityField.Value = (decimal)m_object.getDensity();
        }


        public GridControl()
        {
            InitializeComponent();
        }

        private void GridDensityField_ValueChanged(object sender, EventArgs e)
        {
            m_object.setDensity((Single)GridDensityField.Value);            
        }

        private void GridSizeField_ValueChanged(object sender, EventArgs e)
        {
            m_object.setSize((Single)GridSizeField.Value);
        }
    }
}
