#include "Gui.hpp"

namespace px {

    void Gui::init(){
        this->layer = &getModule<Renderer>().getLayer(Renderer::Layer::GUI);
    }

    void Gui::draw(){
    }

}