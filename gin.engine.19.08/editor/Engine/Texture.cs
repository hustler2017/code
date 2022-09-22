using System;

namespace Gin.Engine
{
    class Texture : Entity
    {
        public readonly IntPtr pEngine;
        public readonly IntPtr pTexture;
        public readonly string filename;

        public Texture(IntPtr engine, IntPtr texture)
        {
            pEngine = engine;
            pTexture = texture;
        }

        public override EType getEntityType()
        {
            return EType.TEXTURE;
        }

    }
}
