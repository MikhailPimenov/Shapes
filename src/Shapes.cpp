#include <iostream>
#include <memory>
#include <vector>

#include "Drawer/Drawer.h"
#include "Point/Point.h"
#include "Shape/IShape.h"
#include "Shape/AngularShape/Rectangle.h"
#include "Shape/AngularShape/Square.h"
#include "Shape/AngularShape/Star.h"
#include "Shape/AngularShape/Triangle.h"
#include "Shape/Circle/Circle.h"


using Shapes_t = std::vector<std::unique_ptr<IShape>>;

void print_shapes(const Shapes_t& shapes) {
    Drawer field(24ull, 88ull);
    for (const auto& shape : shapes) {
        shape->print_info();
        field.draw(*shape);
    }
    field.print();
}

int main() {
    Shapes_t shapes;

    shapes.push_back(std::make_unique<Triangle>(
        Point(0.0, 0.0),
        Point(8.0, 0.0),
        Point(0.0, 12.0)
        ));

    shapes.push_back(std::make_unique<Circle>(
        Point(10.0, 10.0),
        5.0
        ));

    shapes.push_back(std::make_unique<Triangle>(
        Point(10.0, 2.0),
        10.0
        ));

    shapes.push_back(std::make_unique<Circle>(
        Point(5.0, 15.0),
        3.0
        ));

    shapes.push_back(std::make_unique<Rectangle>(
        Point(12.0, 18.0),
        5.0,
        2.0
        ));

    shapes.push_back(std::make_unique<Square>(
        Point(5.0, 19.0),
        4.0
        ));

    shapes.push_back(std::make_unique<Star>(
        Point(30.0, 10.0),
        10.0
        ));

    print_shapes(shapes);
}
