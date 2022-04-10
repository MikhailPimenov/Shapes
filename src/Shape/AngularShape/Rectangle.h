#pragma once

#include <iostream>

#include "../AngularShape/AngularShape.h"
#include "../../Point/Point.h"


/// <summary>
/// Class to store information about rectangle.
/// Has exactly 4 vertices and all angles are 90 degrees
/// </summary>
class Rectangle : public AngularShape {
public:

    /// <summary>
    /// Constructs rectangle with given upper left point, width and height
    /// </summary>
    /// <param name="upper_left">
    /// A point, contains two coordinates for upper left point
    /// </param>
    /// <param name="width">
    /// A double, horizontal side
    /// </param>
    /// <param name="height">
    /// A double, vertical side
    /// </param>
    Rectangle(const Point& upper_left = Point(0.0, 0.0), double width = 10.0, double height = 8.0);

    /// <summary>
    /// Virtual destructor
    /// </summary>
    virtual ~Rectangle() override;

    /// <summary>
    /// Outputs information about this rectangle,
    /// such is information about each its vertex
    /// </summary>
    virtual void print_info() const;
};

