#pragma once

#include <cmath>

#include "../Point/Point.h"

namespace Math {

	double get_distance(const Point& a, const Point& b);

	bool is_between(double x, double lower, double greater);

	double get_delta(double range_x, std::size_t length_x, double range_y, std::size_t length_y);

	bool are_equal(double left, double right);

	double get_y_from_x_for_line(double x, const Point& first, const Point& second);

	double get_x_from_y_for_line(double y, const Point& first, const Point& second);

	bool is_line_vertical(const Point& first, const Point& second);

	bool is_line_horizontal(const Point& first, const Point& second);

	double get_continuous_from_discrete_coordinate(
		std::size_t discrete_coordinate,
		std::size_t discrete_range,
		double continuous_range
	);

	std::size_t get_discrete_from_continuous_coordinate(
		double continuous_coordinate,
		std::size_t discrete_range,
		double continuous_range,
		double continuous_minimum
	);
};