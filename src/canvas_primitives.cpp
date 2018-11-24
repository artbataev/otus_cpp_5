#include "canvas_primitives.h"

namespace editor {
    Color::Color() : r{0}, g{0}, b{0} {} // black
    Color::Color(const Color& rhs) {
        r = rhs.r;
        g = rhs.g;
        b = rhs.b;
    }

    Color::Color(uint8_t r_, uint8_t g_, uint8_t b_) : r{r_}, g{g_}, b{b_} {}
}

namespace editor::figures {
    CanvasPrimitive::CanvasPrimitive(const Color& color_) : color{color_}, z_index{0} {}

    CanvasPrimitive::CanvasPrimitive(const Color& color_, int z_index_) : color{color_}, z_index{z_index_} {}

    void CanvasPrimitive::move_to_z_index(int z_index_) {
        z_index = z_index_;
    }


    Line::Line(const Color& color_, const Coordinate& point1_, const Coordinate& point2_) :
            CanvasPrimitive(color_), point1{point1_}, point2{point2_} {}

    void Line::render() {
        std::cout << "draw line from ("
                  << point1.x << "," << point1.y << ") to ("
                  << point2.x << "," << point2.y << ")" << std::endl;
    }


    Circle::Circle(const Color& color_, const Coordinate& center_, double radius_) :
            CanvasPrimitive(color_), center{center_}, radius{radius_} {}

    void Circle::render() {
        std::cout << "draw circle with center in ("
                  << center.x << "," << center.y << ") with radius " << radius << std::endl;
    }


    Rectangle::Rectangle(const Color& color_, const Coordinate& left_top_, const Coordinate& right_bottom_) :
            CanvasPrimitive(color_), left_top{left_top_}, right_bottom{right_bottom_} {}

    void Rectangle::render() {
        std::cout << "draw rectangle, left top: ("
                  << left_top.x << "," << left_top.y << "), right bottom: ("
                  << right_bottom.x << "," << right_bottom.y << ")" << std::endl;
    }

    Polygon::Polygon(const Color& color_) : CanvasPrimitive(color_), points{} {}

    Polygon::Polygon(const Color& color_, const std::vector<Coordinate>& points_) : CanvasPrimitive(color_),
                                                                                    points{points_} {}

    Polygon::Polygon(const Color& color_, const Coordinate& start_point) : CanvasPrimitive(color_),
                                                                          points{start_point} {}

    void Polygon::add_point(const Coordinate& point) {
        points.emplace_back(point);
    }

    void Polygon::render() {
        std::cout << "draw polygon: ";
        for (const auto& point: points)
            std::cout << "(" << point.x << "," << point.y << ") ";
        std::cout << std::endl;
    }
}
