#pragma once

#include "../../Point/Point.h"
#include "../IShape.h"

/// <summary>
/// Class to store information about circle.
/// Contains center point and radius and methods
/// to get read-only access to them
/// </summary>
class Circle : public IShape {
private:
    Point m_center;
    double m_radius;

public:
    /// <summary>
    /// Default constructor. Creates circle with zero-center
    /// and radius 1.0
    /// </summary>
    Circle();

    /// <summary>
    /// Constructs circle with given coordinates and radius
    /// </summary>
    /// <param name="x">
    /// A double, x-coordinate of the center of the circle
    /// </param>
    /// <param name="y">
    /// A double, y-coordinate of the center of the circle
    /// </param>
    /// <param name="radius">
    /// A double, radius of the circle
    /// </param>
    Circle(double x, double y, double radius);

    /// <summary>
    /// Constructs circle with given center point and radius
    /// </summary>
    /// <param name="center">
    /// Point object, center point. Contains x and y coordinates
    /// for the center of the circle
    /// </param>
    /// <param name="radius">
    /// A double, radius of the circle
    /// </param>
    Circle(const Point& center, double radius);

    /// <summary>
    /// Virtual destructor
    /// </summary>
    virtual ~Circle() override;

    /// <summary>
    /// Outputs information about the circle to console,
    /// such is its center and radius
    /// </summary>
    virtual void print_info() const override;

    /// <summary>
    /// Provides read-only access to center point of this circle
    /// </summary>
    /// <returns>
    /// A Point object, contains x and y coordinates of the center
    /// </returns>
    const Point& center() const;

    /// <summary>
    /// Provides read-only access to the radius of this circle
    /// </summary>
    /// <returns>
    /// A double, radius of the circle
    /// </returns>
    double radius() const;
};
