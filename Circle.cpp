#include "Circle.h"

Circle::Circle() : m_center { 0.0, 0.0 }, m_radius {} {
}

Circle::Circle(double x, double y, double radius) : m_center { x, y }, m_radius { radius } {
}

Circle::Circle(const Point& center, double radius) : m_center { center }, m_radius { radius } {
}

Circle::~Circle() {
}

void Circle::print_info() const {
	std::cout << "Circle(" << m_center << ", " << m_radius << ")\n";
}

const Point& Circle::center() const {
	return m_center;
}

double Circle::radius() const {
	return m_radius;
}
