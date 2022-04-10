#include "Rectangle.h"

Rectangle::Rectangle(
    const Point& upper_left,
    double width,
    double height
) :
    AngularShape{ {
        upper_left,
        Point(upper_left.x() + width, upper_left.y()),
        Point(upper_left.x() + width, upper_left.y() + height),
        Point(upper_left.x(), upper_left.y() + height)
    } }
{
}

Rectangle::~Rectangle() {
}

void Rectangle::print_info() const {
    std::cout << "Rectangle(";
    print_vertices();
    std::cout << ")\n";
}
