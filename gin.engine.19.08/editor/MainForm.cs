using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Gin.Editor.Input;
using Gin.Editor;

namespace Gin
{
    public enum WorkMode
    {
        EDIT_MODE,
        PLAY_MODE
    }


    public partial class MainForm : Form
    {
        private Engine.Engine engine;
        private Engine.Manipulator manipulator;
        private Engine.Axis axis;
        private Engine.Grid grid;
        private Engine.Camera camera;
        private Engine.Light light;

        private Dictionary<string, Engine.Model> models;
        private Dictionary<string, Engine.Texture> textures;
        private Dictionary<string, Engine.Object> objects;
        private Dictionary<string, Engine.Agent> agents;
        private SelectedAgents selectedAgents;

        private InputStateTree inputStateTree;
        private InputStateTree inputStateTreeGameMode;

        private InputStateTree activeStateTree;

        public MainForm()
        {
         //   mode = WorkMode.EDIT_MODE;
         //   this.FormBorderStyle = FormBorderStyle.FixedToolWindow;

            InitializeComponent();
            InitEditor();
        }

        private void ActivatePlayMode()
        {
            mode = WorkMode.PLAY_MODE;
            PlayModeButton.Image = global::Gin.Properties.Resources.stop;
            engine.startGame();
            inputStateTree.shutsown();
            activeStateTree = inputStateTreeGameMode;
        }

        private void ActivateEditMode()
        {
            mode = WorkMode.EDIT_MODE;
            PlayModeButton.Image = global::Gin.Properties.Resources.play;
            engine.stopGame();
            inputStateTreeGameMode.shutsown();
            activeStateTree = inputStateTree;
        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            
        }

        private void tableLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void splitContainer1_Panel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void пустоъToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void toolStripComboBox1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void panel1_MouseDown(object sender, MouseEventArgs e)
        {
            
        }

        private void panel1_MouseLeave(object sender, EventArgs e)
        {
            
        }

        private void panel1_MouseUp(object sender, MouseEventArgs e)
        {
            
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            
        }

        private void panel1_MouseMove(object sender, MouseEventArgs e)
        {

        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void numericUpDown12_ValueChanged(object sender, EventArgs e)
        {

        }

        private void menuItemModel_Load_Click(object sender, EventArgs e)
        {
            if (modelOpenDialog.ShowDialog() == DialogResult.OK)
            {
                Engine.Model model = engine.loadModel(modelOpenDialog.FileName);
                model.filename = modelOpenDialog.FileName;
                model.name = getUniqueModelName();
                models.Add(model.name, model);
                string previewImageFile = model.filename + ".png";

                PictureBox picbox = new PictureBox();
                picbox.Size = new System.Drawing.Size(100, 100);
                picbox.ImageLocation = previewImageFile;
                picbox.Tag = model.name;
                
                picbox.DoubleClick += new System.EventHandler(this.modelPictureBoxDblClick);

                ModelsWindow.Controls.Add(picbox);
            }
        }

        private void modelPictureBoxDblClick(object sender, EventArgs e)
        {
            string modelName = ((PictureBox)sender).Tag.ToString();

            Engine.Object obj = engine.CreateObject(models[modelName]);
            obj.name = getUniqueObjectName();
            objects[obj.name] = obj;

            TreeNode objNode = new TreeNode(obj.name, 4, 4);
            objNode.Name = obj.name;
            objNode.Tag = obj;

            TreeNode[] nodes = ObjectsExplorer.Nodes.Find("objects", true);
            
            if(nodes.Count() > 0)
            {
                nodes[0].Nodes.Add(objNode);
            }
            else
            { 
                Console.WriteLine("не найдено выделенных объектов =( ");  
            }
        }

        private void ObjectsExplorer_AfterSelect(object sender, TreeViewEventArgs e)
        {
            if(e.Node.Tag != null)
            {
                Engine.Entity entity = (Engine.Entity)e.Node.Tag;
                UpdateParameterControls(entity);
                if(entity.getEntityType() == Engine.EType.OBJECT)
                {
                    if((entity as Engine.Object).manipulable == true)
                    {
                        manipulator.setTargetObject((entity as Engine.Object));
                    }
                }
            }
        }

        void UpdateParameterControls(Engine.Entity obj)
        {
            foreach (Control control in ObjectParameters.Controls)
            {
                if (control is Controls.Interfaces.IParametersControl)
                {
                    if (((Controls.Interfaces.IParametersControl)control).setDataObject(obj))
                    {
                        control.Visible = true;
                    }
                    else
                    {
                        control.Visible = false;
                    }
                }
            }
        }

        private void playModeButton_Click(object sender, EventArgs e)
        {
            if(mode == WorkMode.PLAY_MODE)
            {
                ActivateEditMode();
            }
            else
            {
                ActivatePlayMode();
            }
        }

        private void Canvas_onKeyDown(Object sender, KeyEventArgs e)
        {
            activeStateTree.getController().onKeyDown(e);
        }

        private void Canvas_onKeyUp(Object sender, KeyEventArgs e)
        {
            activeStateTree.getController().onKeyUp(e);
        }

        private void Canvas_MouseDown(object sender, MouseEventArgs e)
        {
            if(e.Button == MouseButtons.Left)
            {
                activeStateTree.getController().onMouseDownLeft(e.X, e.Y);
            }

            if (e.Button == MouseButtons.Right)
            {
                activeStateTree.getController().onMouseDownRight(e.X, e.Y);
            }

            if (e.Button == MouseButtons.Middle)
            {
                activeStateTree.getController().onMouseDownMiddle(e.X, e.Y);
            }
        }



        private void Canvas_MouseLeave(object sender, EventArgs e)
        {

        }

        private void Canvas_MouseMove(object sender, MouseEventArgs e)
        {
            activeStateTree.getController().onMouseMove(e.X, e.Y);
        }

        private void Canvas_MouseUp(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                activeStateTree.getController().onMouseLeftUp(e.X, e.Y);
            }

            if (e.Button == MouseButtons.Right)
            {
                activeStateTree.getController().onMouseRightUp(e.X, e.Y);
            }

            if (e.Button == MouseButtons.Middle)
            {
                activeStateTree.getController().onMouseMiddleUp(e.X, e.Y);
            }
        }

        private void Canvas_OnFocusEnter(object sender, EventArgs e)
        {

        }

        private void Canvas_OnFocusLeave(object sender, EventArgs e)
        {

        }

        private void Canvas_MouseHover(object sender, EventArgs e)
        {

        }

        private void Canvas_MouseEnter(object sender, EventArgs e)
        {

        }

        public void IdleTime()
        {
            activeStateTree.getController().Idle();
            engineUpdate();
        }
    }

}
