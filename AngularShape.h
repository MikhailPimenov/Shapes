#pragma once


#include <vector>

#include "IShape.h"
#include "Point.h"

using Vertices_t = std::vector<Point>;

class AngularShape : public IShape {
protected:
	const Vertices_t m_vertices;
	
public:
	AngularShape(const Vertices_t& vertices);
	virtual ~AngularShape() override;

	const Vertices_t& vertices() const;
};

