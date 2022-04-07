#include "Rectangle.h"

Rectangle::Rectangle() 
	: 
	AngularShape{{ 
			Point(0.0, 0.0), 
			Point(10.0, 0.0), 
			Point(10.0, 8.0), 
			Point(0.0, 8.0)
	}} 
{
}

Rectangle::Rectangle(
	const Point& upper_left,
	double width,
	double height
) :
	AngularShape{{
		upper_left, 
		Point(upper_left.x() + width, upper_left.y()),
		Point(upper_left.x() + width, upper_left.y() + height),
		Point(upper_left.x(), upper_left.y() + height)
	}} 
{
}

Rectangle::~Rectangle() {
}

void Rectangle::print_info() const {
	std::cout << "Rectangle(";
	print_vertices();
	std::cout << ")\n";
}
