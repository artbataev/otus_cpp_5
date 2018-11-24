#pragma once

#include <string>
#include <vector>
#include <memory>
#include "canvas_primitives.h"

namespace editor {
    class GraphicDocument {
    public:
        /**
         * Construct empty document
         */
        GraphicDocument() = default;

        /**
         * Load document from file
         */
        GraphicDocument(const std::string& path);

        /**
         * Reload current document from (other) file
         */
        void load_document(const std::string& path);

        /**
         * Add primitive (figure) to document
         */
        void add_primitive_to_document(std::shared_ptr<figures::CanvasPrimitive>& primitive);

        /**
         * Remove primitive (figure) from document
         */
        void remove_primitive_from_document(std::shared_ptr<figures::CanvasPrimitive>& primitive);

        /**
         * Save document to file
         */
        void save_document(const std::string& path);

    private:
        std::vector<std::shared_ptr<figures::CanvasPrimitive>> elements; // using raw address as hash
    };
}
