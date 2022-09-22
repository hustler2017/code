using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace Gin.Engine
{
    [StructLayout(LayoutKind.Sequential)]
    public struct EngineSettings
    {
        [MarshalAs(UnmanagedType.LPStr)]
        public string modelsDirectory;
        [MarshalAs(UnmanagedType.LPStr)]
        public string texturesDirectory;
        [MarshalAs(UnmanagedType.LPStr)]
        public string shadersDirectory;
        public IntPtr windowHandler;
    }

    class Engine
    {
        private IntPtr pEngine;

        public Engine(EngineSettings settings)
        {
            pEngine = engine_create(settings);
        }

        ~Engine()
        {
            engine_delete(pEngine);
        }

        public void render()
        {
            engine_render(pEngine);
        }

        public Model loadModel(string filename)
        {
            return new Model(pEngine, engine_load_model(pEngine, filename));
        }

        public Light getLight()
        {
            return new Light(pEngine, engine_get_light(pEngine));
        }


        public Camera getCamera()
        {
            return new Camera(pEngine, engine_get_camera(pEngine));
        }

        public Object CreateObject(Model model)
        {
            return new Object(pEngine, engine_create_object(pEngine, model.pModel));
        }

        public Axis getAxis()
        {
            return new Axis(engine_get_axis_object(pEngine));
        }

        public Grid getGrid()
        {
            return new Grid(engine_get_grid_object(pEngine));
        }

        public Manipulator getManipulator()
        {
            return new Manipulator(pEngine, engine_get_manipulator(pEngine));
        }


        public void DeleteObject(Object obj)
        {
            engine_create_object(pEngine, obj.pObject);
        }


        public void SelectObject(Object obj)
        {
            engine_set_selected_object(pEngine, obj.pObject);
        }

        public Terrain getTerrain()
        {
            return new Terrain(pEngine, engine_get_terrain(pEngine));
        }

        public IntPtr getPickedObject(int x, int y, int type)
        {
            return engine_get_picked_object(pEngine, x,y);
        }

        public IntPtr getPickedAgent(int x, int y, int type)
        {
            return engine_get_picked_agent(pEngine, x, y);
        }

        public Agent createAgent(int x, int y)
        {
            return new Agent(engine_create_agent(pEngine, x, y));
        }

        public void startGame()
        {
            engine_start_game(pEngine);
        }

        public void stopGame()
        {
            engine_stop_game(pEngine);
        }


        public void commnadMove(List<Agent> selectedAgents, int x, int y)
        {
            if(selectedAgents.Count > 0)
            { 
                engine_command_move(pEngine, selectedAgents[0].getPtr(), x, y);
            }
                
        }

        [DllImport("warzone.dll")]
        private static extern IntPtr engine_create(EngineSettings settings);

        [DllImport("warzone.dll")]
        private static extern void engine_delete(IntPtr pEngine);

        [DllImport("warzone.dll")]
        private static extern void engine_render(IntPtr pEngine);

        [DllImport("warzone.dll")]
        private static extern IntPtr engine_load_model(IntPtr pEngine, [MarshalAs(UnmanagedType.LPStr)] string filename);

        [DllImport("warzone.dll")]

        private static extern IntPtr engine_create_object(IntPtr pEngine, IntPtr pModel);

        [DllImport("warzone.dll")]

        private static extern void engine_delete_object(IntPtr pEngine, IntPtr pObject);

        [DllImport("warzone.dll")]

        private static extern void engine_set_selected_object(IntPtr pEngine, IntPtr pObject);

        [DllImport("warzone.dll")]
        private static extern IntPtr engine_get_light(IntPtr pEngine);

        [DllImport("warzone.dll")]
        private static extern IntPtr engine_get_camera(IntPtr pEngine);

        [DllImport("warzone.dll")]
        private static extern IntPtr engine_get_grid_object(IntPtr pEngine);
        
        [DllImport("warzone.dll")]
        private static extern IntPtr engine_get_axis_object(IntPtr pEngine);

        [DllImport("warzone.dll")]
        private static extern IntPtr engine_get_terrain(IntPtr pEngine);

        [DllImport("warzone.dll")]
        private static extern IntPtr engine_get_manipulator(IntPtr pEngine);

        [DllImport("warzone.dll")]
        private static extern IntPtr engine_get_picked_object(IntPtr engine, int x, int y);

        [DllImport("warzone.dll")]
        private static extern IntPtr engine_get_picked_agent(IntPtr engine, int x, int y);


        [DllImport("warzone.dll")]
        private static extern IntPtr engine_create_agent(IntPtr engine, int x, int y);

        [DllImport("warzone.dll")]
        private static extern void engine_start_game(IntPtr engine);

        [DllImport("warzone.dll")]
        private static extern void engine_stop_game(IntPtr engine);

        [DllImport("warzone.dll")]
        private static extern void engine_command_move(IntPtr engine, IntPtr agent, int x, int y);

    }
}