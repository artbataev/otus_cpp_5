#include "controller.h"

namespace editor {
    CanvasController::CanvasController(editor::GraphicDocument& model_, editor::MainView& view_) :
            model{model_}, view{view_} {

    }

    void CanvasController::import_document(const std::string& path) {

    }

    void CanvasController::export_document(const std::string& path) {

    }

    void CanvasController::add_primitive(std::shared_ptr<figures::CanvasPrimitive>& primitive) {
        model.add_primitive_to_document(primitive);
    }

    void CanvasController::remove_primitive(std::shared_ptr<editor::figures::CanvasPrimitive>& primitive) {
        model.remove_primitive_from_document(primitive);
    }

}
