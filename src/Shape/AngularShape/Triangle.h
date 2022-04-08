#pragma once

#include <cmath>

#include "AngularShape.h"
#include "../../Point/Point.h"

/// <summary>
/// Class to store information about triangle.
/// Has exactly 3 vertices
/// </summary>
class Triangle : public AngularShape {
public:

	/// <summary>
	/// Constructs triangle with given side and upper point.
	/// All angles are 60 degrees. All sides are euqal
	/// </summary>
	/// <param name="upper">
	/// A point, contains two coordinates for upper vertex
	/// </param>
	/// <param name="side">
	/// A double, length of the side.
	/// </param>
	Triangle(const Point& upper = Point(0.0, 0.0), double side = 5.0);

	/// <summary>
	/// Constructs arbitrary triangle using 3 given points.
	/// Order of the points does not matter
	/// </summary>
	/// <param name="a">
	/// A point, stores two coordinates for the first vertex
	/// </param>
	/// <param name="b">
 	/// A point, stores two coordinates for the second vertex
	/// </param>
	/// <param name="c">
	/// A point, stores two coordinates for the third vertex
	/// </param>
	Triangle(const Point &a, const Point &b, const Point &c);

	/// <summary>
	/// Virtual destructor
	/// </summary>
	virtual ~Triangle() override;

	/// <summary>
	/// Outputs information about the triangle to console,
	/// such is information about its 3 points
	/// </summary>
	virtual void print_info() const override;
};

