#include "model.h"
#include "view.h"
#include "controller.h"
#include "canvas_primitives.h"
#include <memory>

 /**
 * Entry Point
 */
int main() {
    editor::GraphicDocument model{}; // create new document
    editor::MainView view{model};
    editor::CanvasController controller(model, view);

    controller.import_document("document.ed");
    controller.export_document("document_copy.ed");

    namespace ef = editor::figures;
    auto line = std::shared_ptr<ef::CanvasPrimitive>(
            new ef::Line{editor::Color{255, 255, 0}, editor::Coordinate{0, 0}, editor::Coordinate{1, 1}});
    controller.add_primitive(line);
    auto rectangle = std::shared_ptr<ef::CanvasPrimitive>(
            new ef::Rectangle{editor::Color{0, 255, 0}, editor::Coordinate{20, 20}, editor::Coordinate{100, 100}});
    controller.add_primitive(rectangle);

    controller.remove_primitive(line);
    controller.export_document("document_modified.ed");

    return 0;
}
