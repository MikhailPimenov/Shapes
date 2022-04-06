#include "Triangle.h"

Triangle::Triangle() : AngularShape{ {Point(2.5, 0.0), Point(0.0, 4.33), Point(5.0, 4.33) } } {
	
}

Triangle::Triangle(const Point& a, const Point& b, const Point& c) : AngularShape{ {a, b, c} } {

}

Triangle::~Triangle() {

}

void Triangle::print_info() const {
	std::cout << "Triangle(";

	for (auto iterator = m_vertices.cbegin(); iterator != m_vertices.cend() - 1; ++iterator)
		std::cout << *iterator << ", ";

	std::cout << m_vertices.back() << ")\n";
}
