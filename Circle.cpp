#include "Circle.h"

Circle::Circle() : m_center { 0.0, 0.0 }, m_radius {} {
}

Circle::Circle(double x, double y, double radius) : m_center { x, y }, m_radius { radius } {
}

Circle::Circle(const Point& center, double radius) : m_center { center }, m_radius { radius } {
}

Circle::~Circle() {
}

const Circle& Circle::draw(std::size_t rows, std::size_t columns) const {
	Drawer field(rows, columns, '*', '.', 0.0, static_cast<double>(rows), 0.0, static_cast<double>(columns));
	draw(field);
	return *this;
}

const Circle& Circle::draw(Drawer& field) const {
	field.draw_circle(m_center, m_radius);
	return *this;
}

void Circle::show() const {
	if (m_field)
		m_field.print_field();
}

void Circle::print_info() const {
}

const Point& Circle::center() const {
	return m_center;
}

double Circle::radius() const {
	return m_radius;
}
