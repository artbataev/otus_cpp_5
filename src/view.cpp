#include "view.h"

namespace editor {
    MainView::MainView(const editor::GraphicDocument& model_): model{model_} {
        render();
    }

    void MainView::redraw() {
        render();
    }

    void MainView::render() {

    }
}
