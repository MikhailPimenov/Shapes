#pragma once

#include <array>
#include <iostream>
#include <cmath>

#include "AngularShape.h"
#include "../../Point/Point.h"

using Star_angles_t = std::array<double, 5>;

/// <summary>
/// Class to store information about 5 vertices star.
/// Has exactly 5 vertices with equal angles, this star 
/// is symmetrical
/// </summary>
class Star : public AngularShape {
public:

    /// <summary>
    /// Constructs start with given center and a distance between its 
    /// center and its vertices
    /// </summary>
    /// <param name="center">
    /// A point, contains two coordinates of geometrical center of
    /// the star. This point will not be shown during rendering
    /// </param>
    /// <param name="radius">
    /// A double, distance between center and any of vertices
    /// </param>
    Star(const Point& center = Point(0.0, 0.0), double radius = 1.0);

    /// <summary>
    /// Virtual destructor
    /// </summary>
    virtual ~Star() override;

    /// <summary>
    /// Outputs information about this star,
    /// such is information about each of its 5 vertices
    /// </summary>
    virtual void print_info() const override;
};

