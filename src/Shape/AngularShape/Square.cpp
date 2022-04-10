#include "Square.h"

Square::Square(const Point& upper_left, double side)
    : Rectangle(upper_left, side, side) {
}

Square::~Square() {
}

void Square::print_info() const {
    std::cout << "Square(";
    print_vertices();
    std::cout << ")\n";
}
