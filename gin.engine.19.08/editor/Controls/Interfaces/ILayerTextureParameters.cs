using System;

namespace Gin.Controls.Interfaces
{
    public interface ILayerTextureParameters
    {
        int getChannelCount();
        string getChannelTexture(int channel);
        Single getChannelTilingX(int channel);
        Single getChannelTilingY(int channel);
        void setChannelTilingX(int channel, Single tiling);
        void setChannelTilingY(int channel, Single tiling);
        void setChannelTexture(int channel, string filename);

    }
}
