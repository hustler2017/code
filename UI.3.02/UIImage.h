#pragma once
#include "UIElement.h"

namespace UI
{
    class UIImage : public UIElement
    {
        ID2D1SolidColorBrush* m_pBorderBrush = nullptr;
        Graphics::Image2D* m_pImage = nullptr;
        void createResources();
        void deleteResources();
    public:
        UIImage(Graphics::Direct2D* d2d);
        void setImage(Graphics::Image2D* pImage);
        void render();
        ~UIImage();
    };
}
