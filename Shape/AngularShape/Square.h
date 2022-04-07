#pragma once

#include "../../Point/Point.h"
#include "Rectangle.h"

class Square : public Rectangle {
public:
	Square(const Point& upper_left = Point(0.0, 0.0), double side = 5.0);
	virtual ~Square() override;

	virtual void print_info() const override;

};

