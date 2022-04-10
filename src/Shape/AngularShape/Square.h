#pragma once

#include "../../Point/Point.h"
#include "Rectangle.h"

/// <summary>
/// Class to store information about square.
/// Has exactly 4 vertices and all angles are 90 degrees
/// and all sides are equal
/// </summary>
class Square : public Rectangle {
public:
    /// <summary>
    /// Constructs square with given upper left point and side
    /// </summary>
    /// <param name="upper_left">
    /// A point, contains two coordinates for upper left vertex
    /// </param>
    /// <param name="side">
    /// A double, side of the square
    /// </param>
    Square(const Point& upper_left = Point(0.0, 0.0), double side = 5.0);

    /// <summary>
    /// Virtual destructor
    /// </summary>
    virtual ~Square() override;

    /// <summary>
    /// Outputs information about this square,
    /// such is information about each its vertex
    /// </summary>
    virtual void print_info() const override;

};

