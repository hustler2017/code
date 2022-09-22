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
    public partial class ActiveControl : UserControl, IParametersControl
    {
        private IActiveParameter m_object;

        public bool setDataObject(object obj)
        {
            if(obj is IActiveParameter)
            {
                m_object = (IActiveParameter)obj;
                initControl();
                return true;
            }
            return false;
        }

        private void initControl()
        {
            ActiveCheckbox.Checked = m_object.getActiveStatus();
        }

        public ActiveControl()
        {
            InitializeComponent();
        }

        private void ActiveCheckbox_CheckedChanged(object sender, EventArgs e)
        {
            m_object.setActiveStatus(ActiveCheckbox.Checked);
        }
    }
}
