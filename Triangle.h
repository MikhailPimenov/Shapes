#pragma once

#include "AngularShape.h"
#include "Drawer.h"
#include "Point.h"

class Triangle : public AngularShape {
public:
	Triangle();
	Triangle(const Point &a, const Point &b, const Point &c);
	virtual ~Triangle() override;

	virtual void print_info() const override;
};

