#include "model.h"

namespace editor {
    GraphicDocument::GraphicDocument(const std::string& path) {
        load_document(path);
    }

    void GraphicDocument::load_document(const std::string& path) {
        elements.clear();
        // ... Read File and deserialize elements
    }

    void GraphicDocument::add_primitive_to_document(std::shared_ptr<figures::CanvasPrimitive>& primitive) {
        std::cout << "adding primitive " << primitive->get_representation() << "\n";
        elements.emplace_back(primitive);
    }

    void GraphicDocument::remove_primitive_from_document(std::shared_ptr<figures::CanvasPrimitive>& primitive) {
        auto position = std::find(elements.begin(), elements.end(), primitive);
        if (position != elements.end()) {
            std::cout << "removing primitive " << primitive->get_representation() << "\n";
            elements.erase(position);
        }
    }

    void GraphicDocument::save_document(const std::string& path) {
        for (const auto& element: elements) { ; // serialize and save element
        }
    }

    std::vector<std::string> GraphicDocument::get_elements_representations() const {
        std::vector<std::string> representations;
        for(const auto& element: elements)
            representations.emplace_back(element->get_representation());
        return representations;
    }
}
