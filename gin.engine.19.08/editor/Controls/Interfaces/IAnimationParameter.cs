using System;
using System.Collections.Generic;
using System.Text;

namespace Gin.Controls.Interfaces
{
    public interface IAnimationParameter
    {
        string getAnimationNames();
        void loadAnimation(string filename, string name);
        void playAnimation(string name);
    }
}
