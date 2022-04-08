#include "AngularShape.h"

AngularShape::AngularShape(const Vertices_t& vertices) : m_vertices{vertices} {
}

AngularShape::~AngularShape() {
}

const Vertices_t& AngularShape::vertices() const {
	return m_vertices;
}

void AngularShape::print_vertices() const {
	for (auto iterator = m_vertices.cbegin(); iterator != m_vertices.cend() - 1; ++iterator)
		std::cout << *iterator << ", ";
	std::cout << m_vertices.back();
}
