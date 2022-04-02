#pragma once

#include <iostream>

/// <summary>
/// Stores two coordinates.
/// </summary>
class Point
{
private:
	double m_x;
	double m_y;

public:
	Point();
	Point(double x, double y);

	double x() const;
	double y() const;

	friend std::ostream& operator<<(std::ostream& out, const Point& object);
};

