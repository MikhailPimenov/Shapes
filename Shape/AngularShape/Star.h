#pragma once

#include <array>
#include <iostream>
#include <cmath>

#include "AngularShape.h"
#include "../../Point/Point.h"

using Star_angles_t = std::array<double, 5>;

//static const Star_angles_t g_angles;

class Star : public AngularShape {
public:
	Star();
	Star(const Point& center, double radius);
	virtual ~Star() override;

	virtual void print_info() const override;
};

