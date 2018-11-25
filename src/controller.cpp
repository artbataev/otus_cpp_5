#include "controller.h"

namespace editor {
    CanvasController::CanvasController(editor::GraphicDocument& model_, editor::MainView& view_) :
            model{model_}, view{view_} {

    }

    void CanvasController::import_document(const std::string& path) {
        model.load_document(path);
        view.redraw();
    }

    void CanvasController::export_document(const std::string& path) {
        model.save_document(path);
    }

    void CanvasController::add_primitive(std::shared_ptr<figures::CanvasPrimitive>& primitive) {
        model.add_primitive_to_document(primitive);
        view.redraw(); // notify view to update canvas
    }

    void CanvasController::remove_primitive(std::shared_ptr<editor::figures::CanvasPrimitive>& primitive) {
        model.remove_primitive_from_document(primitive);
        view.redraw(); // notify view to update canvas
    }

}
