#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace editor {
    /**
     * Class to represent color (in RGB format)
     */
    class Color {
    public:
        Color();

        Color(const Color& rhs);

        Color(uint8_t r_, uint8_t g_, uint8_t b_);

    private:
        uint8_t r;
        uint8_t g;
        uint8_t b;
    };

    /**
     * 2d Coordinate (point)
     */
    struct Coordinate {
        int x;
        int y;
    };

    /**
     * Basic class for all primitives (figures)
     */
    class CanvasPrimitive {
    public:
        CanvasPrimitive() = default;
        explicit CanvasPrimitive(const Color& color_);
        CanvasPrimitive(const Color& color_, int z_index_);

        void move_to_z_index(int z_index_);

        virtual void render() = 0;
        virtual std::string serialize() = 0;
        virtual void deserialize(const std::string& data) = 0;

    private:
        Color color;
        int z_index = 0;
    };

    /**
     * Primitive - Line
     */
    class Line : CanvasPrimitive {
        Line(const Color& color_, const Coordinate& point1_, const Coordinate& point2_);

        void render() override;

    private:
        Coordinate point1;
        Coordinate point2;
    };

    /**
     * Primitive - Circle
     */
    class Circle : CanvasPrimitive {
        Circle(const Color& color_, const Coordinate& center_, double radius_);

        void render() override;

    private:
        Coordinate center;
        double radius;
    };

    /**
     * Primitive - Rectangle
     */
    class Rectangle : CanvasPrimitive {
        Rectangle(const Color& color_, const Coordinate& left_top_, const Coordinate& right_bottom_);

        void render() override;

    private:
        Coordinate left_top;
        Coordinate right_bottom;
    };

    /**
     * Primitive - Polygon
     */
    class Polygon : CanvasPrimitive {
        Polygon(const Color& color_);

        Polygon(const Color& color_, const std::vector<Coordinate>& points_);

        Polygon(const Color& color_, const Coordinate& start_point);

        void add_point(const Coordinate& point);

        void render() override;

    private:
        std::vector<Coordinate> points;
    };
}
