#pragma once

#include "projectX/modules/renderer/Renderer.hpp"

namespace px {

    class Gui :public Module<Renderer>
    {
    public:
        Gui(){}

        void init();

        void draw();

        //TODO: Implement Gui::input method
        void input(const sf::Event& event){}

    private:
        sf::RenderTexture* layer;
    };

}