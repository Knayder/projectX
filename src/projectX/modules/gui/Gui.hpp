#pragma once

#include "projectX/modules/renderer/Renderer.hpp"

#include "GuiContainer.hpp"

namespace px {

    class Gui :public Module<Renderer>
    {
    public:
        Gui(){}

        void init();

        void draw();

        void input(const sf::Event& event);

    private:
        GuiContainer container;
        sf::RenderTexture* layer;
    };

}