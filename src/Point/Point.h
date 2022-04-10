#pragma once

#include <iostream>

/// <summary>
/// Stores two coordinates.
/// </summary>
class Point {
private:
    double m_x;
    double m_y;

public:
    /// <summary>
    /// Default constructor. Creates object with zero coordinates
    /// </summary>
    Point();

    /// <summary>
    /// Constructs object with given x and y coordinates
    /// </summary>
    /// <param name="x">
    /// A double, coordinate on x-axis
    /// </param>
    /// <param name="y">
    /// A double, coordinate on y-axis
    /// </param>
    Point(double x, double y);

    /// <summary>
    /// Provides read-only access to x-coordinate
    /// </summary>
    /// <returns>
    /// A double, x-coordinate
    /// </returns>
    double x() const;

    /// <summary>
    /// Provides read-only access to y-coordinate
    /// </summary>
    /// <returns>
    /// A double, y-coordinate
    /// </returns>
    double y() const;

    /// <summary>
    /// Outputs point using operator<<
    /// </summary>
    /// <param name="out">
    /// Left operand of operator<<, object of output stream
    /// </param>
    /// <param name="object">
    /// Point to output
    /// </param>
    /// <returns></returns>
    friend std::ostream& operator<<(std::ostream& out, const Point& object);
};

