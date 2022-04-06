#include "Point.h"

Point::Point() : m_x { 0.0 }, m_y { 0.0 } {
}

Point::Point(double x, double y) : m_x { x }, m_y { y } {
}

double Point::x() const {
	return m_x;
}

double Point::y() const {
	return m_y;
}

std::ostream& operator<<(std::ostream& out, const Point& object) {
	out << "Point(" << object.m_x << ", " << object.m_y << ')';
	return out;
}
