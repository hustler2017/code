using System;
using System.Windows.Forms;
using Gin.Controls.Interfaces;

namespace Gin.Controls
{
    public partial class TextureChannelsControl : UserControl, IParametersControl
    {
        public OpenFileDialog texFileDialog;
        private ILayerTextureParameters m_object;

        public bool setDataObject(object obj)
        {
            if (obj is ILayerTextureParameters)
            {
                m_object = (ILayerTextureParameters)obj;
                initControl();
                return true;
            }

            return false;
        }

        private void initControl() 
        {
            button1.Text = m_object.getChannelTexture(0);
            button2.Text = m_object.getChannelTexture(1);
            button3.Text = m_object.getChannelTexture(2);
            button4.Text = m_object.getChannelTexture(3);
            maskButton.Text = m_object.getChannelTexture(4);

            pictureBox1.ImageLocation = button1.Text;
            pictureBox2.ImageLocation = button2.Text;
            pictureBox3.ImageLocation = button3.Text;
            pictureBox4.ImageLocation = button4.Text;
            pictureBox5.ImageLocation = maskButton.Text;

            tileX_1.Value = (decimal)m_object.getChannelTilingX(0);
            tileY_1.Value = (decimal)m_object.getChannelTilingY(0);

            tileX_2.Value = (decimal)m_object.getChannelTilingX(1);
            tileY_2.Value = (decimal)m_object.getChannelTilingY(1);

            tileX_3.Value = (decimal)m_object.getChannelTilingX(2);
            tileY_3.Value = (decimal)m_object.getChannelTilingY(2);

            tileX_4.Value = (decimal)m_object.getChannelTilingX(3);
            tileY_4.Value = (decimal)m_object.getChannelTilingY(3);
        }

        

        public TextureChannelsControl(OpenFileDialog dlg)
        {
            texFileDialog = dlg;
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {

            if (texFileDialog.ShowDialog() == DialogResult.OK)
            {
                button1.Text = texFileDialog.FileName;
                pictureBox1.ImageLocation = texFileDialog.FileName;
                m_object.setChannelTexture(0, texFileDialog.FileName);
            }

        }
        private void button2_Click(object sender, EventArgs e)
        {
            if (texFileDialog.ShowDialog() == DialogResult.OK)
            {
                button2.Text = texFileDialog.FileName;
                pictureBox2.ImageLocation = texFileDialog.FileName;
                m_object.setChannelTexture(1, texFileDialog.FileName);
            }
        }



        private void button3_Click(object sender, EventArgs e)
        {
            if (texFileDialog.ShowDialog() == DialogResult.OK)
            {
                button3.Text = texFileDialog.FileName;
                pictureBox3.ImageLocation = texFileDialog.FileName;
                m_object.setChannelTexture(2, texFileDialog.FileName);
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (texFileDialog.ShowDialog() == DialogResult.OK)
            {
                button4.Text = texFileDialog.FileName;
                pictureBox4.ImageLocation = texFileDialog.FileName;
                m_object.setChannelTexture(3, texFileDialog.FileName);
            }
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void tileX_1_ValueChanged(object sender, EventArgs e)
        {
            m_object.setChannelTilingX(0, (Single)tileX_1.Value);
        }

        private void tileY_1_ValueChanged(object sender, EventArgs e)
        {
            m_object.setChannelTilingY(0, (Single)tileY_1.Value);
        }

        private void tileX_2_ValueChanged(object sender, EventArgs e)
        {
            m_object.setChannelTilingX(1, (Single)tileX_2.Value);
        }

        private void tileY_2_ValueChanged(object sender, EventArgs e)
        {
            m_object.setChannelTilingY(1, (Single)tileY_2.Value);
        }

        private void tileX_3_ValueChanged(object sender, EventArgs e)
        {
            m_object.setChannelTilingX(2, (Single)tileX_3.Value);
        }

        private void tileY_3_ValueChanged(object sender, EventArgs e)
        {
            m_object.setChannelTilingY(2, (Single)tileY_3.Value);
        }

        private void tileX_4_ValueChanged(object sender, EventArgs e)
        {
            m_object.setChannelTilingX(3, (Single)tileX_4.Value);
        }

        private void tileY_4_ValueChanged(object sender, EventArgs e)
        {
            m_object.setChannelTilingY(3, (Single)tileY_4.Value);
        }

        private void maskButton_Click(object sender, EventArgs e)
        {
            if (texFileDialog.ShowDialog() == DialogResult.OK)
            {
                maskButton.Text = texFileDialog.FileName;
                pictureBox5.ImageLocation = texFileDialog.FileName;
                m_object.setChannelTexture(4, texFileDialog.FileName);
            }
        }
    }
}
