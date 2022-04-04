#include "Triangle.h"

Triangle::Triangle() : AngularShape{ {Point(0.0, 0.0), Point(5.0, 0.0), Point(5.0, 5.0) } } {
	
}

Triangle::Triangle(const Point& a, const Point& b, const Point& c) : AngularShape{ {a, b, c} } {

}

Triangle::~Triangle() {

}

//void Triangle::draw(std::size_t rows, std::size_t columns) const {
//	Drawer field(24u, 88u, '*', '.', 0.0, 24.0, 0.0, 88.0);
//
//	for (std::size_t index = 0u; index < m_vertices.size(); ++index)
//		field.draw_line(m_vertices.at(index), m_vertices.at((index + 1u) % m_vertices.size()));
//
//	field.print_field();
//}

void Triangle::print_info() const {
	std::cout << "Triangle(";

	for (auto iterator = m_vertices.cbegin(); iterator != m_vertices.cend() - 1; ++iterator)
		std::cout << *iterator << ", ";

	std::cout << m_vertices.back() << ")\n";
}
