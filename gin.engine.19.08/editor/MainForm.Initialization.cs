using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Gin.Controls;
using Gin.Editor.Input;
using Gin.Editor.Input.Controller;
using Gin.Engine;

namespace Gin
{
    public partial class MainForm
    {
        public WorkMode mode;
        private Terrain terrain;
        


        private void InitEditor()
        {
            InitCanvas();
            InitLists();
            InitEngine();
            InitParameterControls();
            LoadEntities();
            InitObjectsExplorer();
            InitControllers();
            createInputStateTree();
            LoadDemo();
        }

        private void InitLists()
        {
            models = new Dictionary<string, Model>();
            textures = new Dictionary<string, Texture>();
            objects = new Dictionary<string, Engine.Object>();
            agents = new Dictionary<string, Engine.Agent>();
            selectedAgents = new Editor.SelectedAgents();
        }

        private void InitCanvas()
        {
            (Canvas as Control).KeyDown += new KeyEventHandler(Canvas_onKeyDown);
            (Canvas as Control).KeyUp += new KeyEventHandler(Canvas_onKeyUp);
        }

        private void InitEngine()
        {
            Engine.EngineSettings settings = new EngineSettings();
            settings.modelsDirectory = "d:\\work\\projects\\warzone\\source\\Warzone\\data\\models\\";
            settings.texturesDirectory = "d:\\work\\projects\\warzone\\source\\Warzone\\data\\textures\\";
            settings.shadersDirectory = "d:\\work\\projects\\warzone\\source\\Warzone\\data\\shaders\\";
            settings.windowHandler = Canvas.Handle;

            engine = new Engine.Engine(settings);
        }

        private void InitParameterControls()
        {
            ObjectParameters.Controls.Add(new ActiveControl());
            ObjectParameters.Controls.Add(new PositionControl());
            ObjectParameters.Controls.Add(new DirectionControl());
            ObjectParameters.Controls.Add(new GridControl());
            ObjectParameters.Controls.Add(new TextureChannelsControl(openTextureFileDialog));
            ObjectParameters.Controls.Add(new AnimationParametersControl(modelOpenDialog));
        }


        private void LoadEntities()
        {
            manipulator = engine.getManipulator();
            axis = engine.getAxis();
            grid = engine.getGrid();
            camera = engine.getCamera();
            light = engine.getLight();
            terrain = engine.getTerrain();
        }

        public void InitObjectsExplorer()
        {

            TreeNode systemNode = ObjectsExplorer.Nodes.Add("system", "Системные объекты", 3);
            TreeNode objectsNode = ObjectsExplorer.Nodes.Add("objects", "Объекты", 3);

            TreeNode cameraNode = new TreeNode("Камера", 3, 3);
            cameraNode.Name = "camera";
            cameraNode.Tag = camera;

            TreeNode lightNode = new TreeNode("Освещение", 3, 3);
            lightNode.Name = "light";
            lightNode.Tag = light;

            TreeNode axisNode = new TreeNode("Оси", 3, 3);
            axisNode.Name = "axis";
            axisNode.Tag = axis;

            TreeNode gridNode = new TreeNode("Сетка", 3, 3);
            gridNode.Name = "grid";
            gridNode.Tag = grid;

            TreeNode terrainNode = new TreeNode("Ландшафт", 3, 3);
            terrainNode.Name = "terrain";
            terrainNode.Tag = terrain;

            systemNode.Nodes.Add(axisNode);
            systemNode.Nodes.Add(gridNode);
            systemNode.Nodes.Add(lightNode);
            systemNode.Nodes.Add(cameraNode);

            ObjectsExplorer.Nodes.Add(terrainNode);
            ObjectsExplorer.ImageList = icons;
            ObjectsExplorer.ExpandAll();
        }

        private void createInputStateTree()
        {
            BaseInputController baseInput = new BaseInputController(engine, manipulator, objects, Canvas);
            CameraMoveInputController cameraMove = new CameraMoveInputController(camera);
            ManipulatorInputController objectMove = new ManipulatorInputController(manipulator);

            InputState baseState = new InputState(null, baseInput);
            InputState cameraMoveState = new InputState(baseState, cameraMove);
            InputState objectMoveState = new InputState(baseState, objectMove);

            baseState.addSubstate("camera_move", cameraMoveState);
            baseState.addSubstate("object_move", objectMoveState);

            inputStateTree = new InputStateTree();
            inputStateTree.addState(baseState);
            inputStateTree.addState(cameraMoveState);
            inputStateTree.addState(objectMoveState);
            inputStateTree.m_current = baseState;
            
            GameModeBase gamebaseInput = new GameModeBase(engine, Canvas, selectedAgents, agents);
            CameraMoveInputController GcameraMove = new CameraMoveInputController(camera);
            InputState gameBaseState = new InputState(null, gamebaseInput);
            InputState gameCameraMoveState = new InputState(gameBaseState, GcameraMove);
            gameBaseState.addSubstate("camera_move", gameCameraMoveState);
            inputStateTreeGameMode = new InputStateTree();
            inputStateTreeGameMode.addState(gameBaseState);
            inputStateTreeGameMode.addState(gameCameraMoveState);
            inputStateTreeGameMode.m_current = gameBaseState;
            
            activeStateTree = inputStateTree;
        }

        public void InitControllers()
        {
            
        }

        private void LoadDemo()
        {
            Agent agent = engine.createAgent(0,0);
            agents.Add("agent", agent);
        }

        public void engineDestroy()
        {
            engine = null;
            GC.Collect();
        }

        public void engineUpdate()
        {
            engine.render();
        }


        private string getUniqueModelName()
        {
            for (int i = 0; i < 1000; i++)
            {
                String name = "Model" + i;
                if (!models.ContainsKey(name))
                {
                    return name;
                }
            }

            return "";
        }

        private string getUniqueObjectName()
        {
            for (int i = 0; i < 1000; i++)
            {
                String name = "Object" + i;
                if (!objects.ContainsKey(name))
                {
                    return name;
                }
            }

            return "";
        }
    }
}
