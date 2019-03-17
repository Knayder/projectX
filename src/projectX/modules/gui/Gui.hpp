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
        //Raw pointer is used here on purpose, because smart pointers cause segmentation fault
        sf::RenderTexture* layer;
    };

}