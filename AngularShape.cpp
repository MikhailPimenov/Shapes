#include "AngularShape.h"

AngularShape::AngularShape(const Vertices_t& vertices) : m_vertices{vertices} {

}

AngularShape::~AngularShape() {
}

const Vertices_t& AngularShape::vertices() const {
	return m_vertices;
}

//const AngularShape& AngularShape::draw(std::size_t rows, std::size_t columns) {
//	//Drawer field(rows, columns);
//	//draw(field);
//	initialize_field(rows, columns);
//	draw(m_field);
//	return *this;
//}

//const AngularShape& AngularShape::draw(Drawer& field) const {
//	for (std::size_t index = 0ull; index < m_vertices.size(); ++index)
//		field.draw_line(m_vertices.at(index), m_vertices.at((index + 1ull) % m_vertices.size()));
//	return *this;
//}
//
//void AngularShape::show() const {
//	std::cout << "AngularShape::show():\n";
//	if (m_field)
//		m_field.print_field();
//}
//
//void AngularShape::initialize_field(std::size_t rows, std::size_t columns) {
//	std::cout << "initialize_field() begin:\n";
//	
//	if (m_field)
//		return;
//
//	Drawer temporary(rows, columns);
//	m_field = std::move(temporary);
//	std::cout << "initialize_field() end:\n";
//}
