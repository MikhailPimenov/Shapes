#pragma once

#include <iostream>

#include "../AngularShape/AngularShape.h"
#include "../../Point/Point.h"

class Rectangle : public AngularShape {
public:
	Rectangle();
	Rectangle(const Point& upper_left, double width, double height);
	virtual ~Rectangle() override;

	virtual void print_info() const;
};

