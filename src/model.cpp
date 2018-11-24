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
        elements.emplace_back(primitive);
    }

    void GraphicDocument::remove_primitive_from_document(std::shared_ptr<figures::CanvasPrimitive>& primitive) {
        // find primitive and remove
    }

    void GraphicDocument::save_document(const std::string& path) {
        for (const auto& element: elements) { ; // serialize and save element
        }
    }
}
