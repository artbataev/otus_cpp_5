#include "view.h"
#include "iostream"

namespace editor {
    MainView::MainView(const editor::GraphicDocument& model_): model{model_} {
        render();
    }

    void MainView::redraw() {
        render();
    }

    void MainView::render() {
        std::cout << "========================================" << std::endl;
        std::cout << "drawing canvas: ";
        const auto& representations = model.get_elements_representations();
        if(representations.empty())
            std::cout << "empty canvas" << std::endl;
        else {
            std::cout << std::endl;
            for (auto& representation: model.get_elements_representations())
                std::cout << representation << std::endl;
        }
        std::cout << "end drawing canvas" << std::endl;
        std::cout << "========================================" << std::endl;
    }
}
