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

Rectangle::~Rectangle() {
}

void Rectangle::print_info() const {
	std::cout << "Rectagle(";
	print_vertices();
	std::cout << ")\n";
}
