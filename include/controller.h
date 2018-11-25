#pragma once

#include <string>
#include "model.h"
#include "view.h"

namespace editor {
    class CanvasController {
    public:
        /**
         * Construct controller with model and view
         */
        CanvasController(GraphicDocument& model_, MainView& view_);

        /**
         * Load document from file and draw
         */
        void import_document(const std::string& path);

        /**
         * Save document to file
         */
        void export_document(const std::string& path);

        /**
         * Add figure and redraw canvas
         */
        void add_primitive(std::shared_ptr<figures::CanvasPrimitive>& primitive);

        /**
         * Remove figure and redraw canvas
         */
        void remove_primitive(std::shared_ptr<figures::CanvasPrimitive>& primitive);

    private:
        GraphicDocument& model;
        MainView view;
    };
}
