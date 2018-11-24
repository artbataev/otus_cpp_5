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

        void import_document(const std::string& path);

        void export_document(const std::string& path);

        void add_primitive(std::shared_ptr<figures::CanvasPrimitive>& primitive);

        void remove_primitive(std::shared_ptr<figures::CanvasPrimitive>& primitive);

    private:
        GraphicDocument model;
        MainView view;
    };
}
