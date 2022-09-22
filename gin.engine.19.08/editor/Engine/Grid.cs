using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;
using Gin.Controls.Interfaces;


namespace Gin.Engine
{
    class Grid : Entity, IActiveParameter, IGridParameter
    {
        private IntPtr pGrid;
        public Grid(IntPtr grid)
        {
            pGrid = grid;
        }


        public override EType getEntityType()
        {
            return EType.NONE;
        }

        public Single getSize()
        {
            return engine_get_grid_size(pGrid);
        }

        public Single getDensity()
        {
            return engine_get_grid_density(pGrid);
        }
        public void setDensity(Single density)
        {
            engine_set_grid_density(pGrid, density);
        }

        public void setSize(Single size)
        {
            engine_set_grid_size(pGrid, size);
        }

        public bool getActiveStatus()
        {
            return engine_get_axis_status(pGrid);
        }
        public void setActiveStatus(bool status)
        {
            engine_set_axis_status(pGrid, status);
        }

        [DllImport("warzone")]
        private static extern void engine_set_grid_density(IntPtr grid, Single density);


        [DllImport("warzone")]
        private static extern Single engine_get_grid_density(IntPtr grid);

        [DllImport("warzone")]
        private static extern void engine_set_grid_size(IntPtr grid, Single size);

        [DllImport("warzone")]
        private static extern Single engine_get_grid_size(IntPtr grid);

        [DllImport("warzone")]
        private static extern bool engine_get_axis_status(IntPtr grid);

        [DllImport("warzone")]
        private static extern void engine_set_axis_status(IntPtr grid, bool status);

    }

}
