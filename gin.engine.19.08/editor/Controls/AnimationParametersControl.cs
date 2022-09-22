using System;
using System.IO;
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
    public partial class AnimationParametersControl : UserControl, IParametersControl
    {
        public OpenFileDialog dialog;
        private IAnimationParameter m_object;

        public bool setDataObject(object obj)
        {
            if (obj is IAnimationParameter)
            {
                m_object = (IAnimationParameter)obj;
                initControl();
                return true;
            }

            return false;
        }

        public void initControl() 
        {
            Controls.Clear();
            Controls.Add(AddAnimationButton);

            string animations_string = m_object.getAnimationNames();
            string[] animations = animations_string.Split(',');
            for (int i = 0; i < animations.Length; i++)
            {
                Button button = new Button();
                button.Text = animations[i];
                button.Tag = animations[i];
                button.Size = new Size(200, 55);
                button.Dock = DockStyle.Top;
                button.Click += new System.EventHandler(this.PlayButton_Click);
                Controls.Add(button);
            }
        }

        public AnimationParametersControl(OpenFileDialog dlg)
        {
            dialog = dlg;
            InitializeComponent();
        }

        private void PlayButton_Click(object sender, EventArgs e)
        {
            Button button = ((Button)sender);
            string animation = (string)button.Tag;
            m_object.playAnimation(animation);
        }

        private void AddAnimationButton_Click(object sender, EventArgs e)
        {
            if(dialog != null)
            {
                if (dialog.ShowDialog() == DialogResult.OK)
                {
                    string name = Path.GetFileNameWithoutExtension(dialog.FileName);

                    m_object.loadAnimation(dialog.FileName, name);
                    Button button = new Button();
                    button.Text = name;
                    button.Size = new Size(200, 55);
                    button.Dock = DockStyle.Top;
                    button.Tag = name;
                    button.Click += new System.EventHandler(this.PlayButton_Click);
                    Controls.Add(button);
                }
            }
        }

    }
}
