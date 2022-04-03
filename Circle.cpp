#include "Circle.h"

Circle::Circle() : m_center{ 0.0, 0.0 }, m_radius {}
{
}

Circle::Circle(double x, double y, double radius) : m_center {x, y}, m_radius { radius }
{
}

Circle::Circle(const Point& center, double radius) : m_center{center}, m_radius{radius}
{
}

Circle::~Circle()
{
}

void Circle::draw(int rows, int columns) const
{
}

void Circle::print_info() const
{
}

const Point& Circle::center() const {
	return m_center;
}

double Circle::radius() const {
	return m_radius;
}




//void Circle::draw(int rows, int columns, double x_range, double y_range) const {
//	const double dx = x_range / static_cast<double>(columns);
//	const double dy = y_range / static_cast<double>(rows);
//	for (int row = 0; row < rows; ++row) {
//		for (int column = 0; column < columns; ++column) {
//			//if ()
//		}
//	}
//}
