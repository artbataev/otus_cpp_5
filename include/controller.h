#pragma once

#include <string>
#include "document_model.h"
#include "view.h"

namespace editor {
    class CanvasController {
    public:
        CanvasController(GraphicDocument& model_, MainView& view_);
    private:
        GraphicDocument model;
        MainView view;
    };
}
