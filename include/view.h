#pragma once

#include "document_model.h"

namespace editor {
    class MainView {
    public:
        /*
         * Constructor for main view (requires model), doesn't change model
         */
        explicit MainView(const GraphicDocument& model_);

        /*
         * Function to redraw picture, if data has changed
         */
        void redraw();
    private:
        const GraphicDocument& model;

        /*
         * Render current model
         */
        void render();
    };
}
