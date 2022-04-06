#pragma once

#include <iostream>

#include "AngularShape.h"
#include "Point.h"

class Rectangle : public AngularShape {
public:
	Rectangle();
	virtual ~Rectangle() override;

	virtual void print_info() const;
};

