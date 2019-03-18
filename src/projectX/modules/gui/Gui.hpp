#pragma once

#include "projectX/modules/renderer/Renderer.hpp"

#include "Container.hpp"

namespace px {

    class Gui :public Module<Renderer>
    {
    public:
        Gui(){}

        void init();

        void draw();

        void input(const sf::Event& event);

    private:
        Container container;
        sf::RenderTexture* layer;
    };

}