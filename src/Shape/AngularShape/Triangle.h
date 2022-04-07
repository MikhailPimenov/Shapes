#pragma once

#include "AngularShape.h"
#include "../../Point/Point.h"

class Triangle : public AngularShape {
public:
	//Triangle();
	Triangle(const Point& upper = Point(0.0, 0.0), double side = 5.0);
	Triangle(const Point &a, const Point &b, const Point &c);
	virtual ~Triangle() override;

	virtual void print_info() const override;
};

