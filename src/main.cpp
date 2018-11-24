#include "document_model.h"
#include "view.h"
#include "controller.h"

 /**
 * Entry Point
 */
int main() {
    editor::GraphicDocument model{}; // create new document
    editor::MainView view{model};
    editor::CanvasController controller(model, view);

    return 0;
}
