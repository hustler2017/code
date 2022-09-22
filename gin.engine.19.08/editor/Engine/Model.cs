using System;

namespace Gin.Engine
{
    class Model : Entity
    {
        public IntPtr pEngine;
        public IntPtr pModel;


        public string filename;

        public Model(IntPtr engine, IntPtr model)
        {
            pEngine = engine;
            pModel = model;


        }

        public override EType getEntityType()
        {
            return EType.MODEL;
        }

        ~Model()
        {
        }


    }
}


