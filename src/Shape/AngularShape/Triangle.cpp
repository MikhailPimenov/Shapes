#include "Triangle.h"

const double g_side_ratio_triangle1 = std::sqrt(3.0) / 2.0;
const double g_side_ratio_triangle2 = 0.5;

Triangle::Triangle(
    const Point& upper,
    double side
) : AngularShape{ {
        Point(
            upper.x() + side * g_side_ratio_triangle2,
            upper.y()
        ),
        Point(
            upper.x(),
            upper.y() + side * g_side_ratio_triangle1
        ),
        Point(
            upper.x() + side,
            upper.y() + side * g_side_ratio_triangle1
        ),
} } {

}

Triangle::Triangle(
    const Point& a,
    const Point& b,
    const Point& c
) : AngularShape{ {a, b, c} } {

}

Triangle::~Triangle() {

}

void Triangle::print_info() const {
    std::cout << "Triangle(";
    print_vertices();
    std::cout << ")\n";
}
