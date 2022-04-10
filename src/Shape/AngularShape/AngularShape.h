#pragma once


#include <vector>

#include "../IShape.h"
#include "../../Point/Point.h"

/// <summary>
/// Stores all points
/// </summary>
using Vertices_t = std::vector<Point>;

/// <summary>
/// Abstract class for shape with angles. Stores all vertices
/// </summary>
class AngularShape : public IShape {
protected:
    const Vertices_t m_vertices;

public:
    /// <summary>
    /// Constructs object with given sequence (std::vector) of points
    /// </summary>
    /// <param name="vertices"></param>
    AngularShape(const Vertices_t& vertices);

    /// <summary>
    /// Virtual destructor
    /// </summary>
    virtual ~AngularShape() override;

    /// <summary>
    /// Provides read-only access to its vertices (points)
    /// </summary>
    /// <returns>
    /// A const reference to storage (std::vector) of vertices
    /// </returns>
    const Vertices_t& vertices() const;

    /// <summary>
    /// Outputs information about each vertex (point)
    /// in their order
    /// </summary>
    void print_vertices() const;
};

