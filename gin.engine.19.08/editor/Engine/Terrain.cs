using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;
using Gin.Controls.Interfaces;

namespace Gin.Engine
{
    public class Terrain : Entity, ILayerTextureParameters
    {
        public IntPtr pEngine;
        public IntPtr pTerrain;
        public Terrain(IntPtr engine, IntPtr terrain)
        {
            pEngine = engine;
            pTerrain = terrain;
        }

        public override EType getEntityType()
        {
            return EType.TERRAIN;
        }


        public int getChannelCount()
        {
            return engine_get_terrain_channels_count(pTerrain);
        }

        public string getChannelTexture(int channel)
        {
            return engine_get_terrain_channel_texture(pTerrain, channel);
        }

        public Single getChannelTilingX(int channel)
        {
            return engine_get_terrain_channel_tilingX(pTerrain, channel);
        }
        public Single getChannelTilingY(int channel)
        {
            return engine_get_terrain_channel_tilingY(pTerrain, channel);
        }
        public void setChannelTilingX(int channel, Single tiling)
        {
            engine_set_terrain_channel_tilingX(pTerrain, channel, tiling);
        }
        public void setChannelTilingY(int channel, Single tiling)
        {
            engine_set_terrain_channel_tilingY(pTerrain, channel, tiling);
        }
        public void setChannelTexture(int channel, string filename)
        {
            engine_set_terrain_channel_texture(pTerrain, channel, filename);
        }




        [DllImport("warzone.dll")]
        private static extern void engine_set_terrain_channel_texture(IntPtr pTerrain, int channel, [MarshalAs(UnmanagedType.LPStr)] string filename
        );

        [DllImport("warzone.dll")]
        [return: MarshalAs(UnmanagedType.BStr)]
        private static extern string engine_get_terrain_channel_texture(IntPtr pTerrain, int channel);


        [DllImport("warzone.dll")]
        private static extern Single engine_get_terrain_channel_tilingX(IntPtr pTerrain, int channel);

        [DllImport("warzone.dll")]
        private static extern Single engine_get_terrain_channel_tilingY(IntPtr pTerrain, int channel);


        [DllImport("warzone.dll")]
        private static extern void engine_set_terrain_channel_tilingX(IntPtr pTerrain, int channel, Single tiling);

        [DllImport("warzone.dll")]
        private static extern void engine_set_terrain_channel_tilingY(IntPtr pTerrain, int channel, Single tiling);


        [DllImport("warzone.dll")]
        private static extern int engine_get_terrain_channels_count(IntPtr pTerrain);

    }








}
