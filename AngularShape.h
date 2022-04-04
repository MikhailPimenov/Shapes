#pragma once


#include <vector>

#include "Drawer.h"
#include "IShape.h"
#include "Point.h"

using Vertices_t = std::vector<Point>;

class AngularShape : public IShape {
protected:
	const Vertices_t m_vertices;
	
public:
	AngularShape(const Vertices_t& vertices);
	virtual ~AngularShape() override;

	virtual const AngularShape& draw(std::size_t rows, std::size_t columns) const override;
	virtual const AngularShape& draw(Drawer &drawer) const override;
	virtual void show() const override;
	//virtual void print_info() const override;

//protected:
public:
	void initialize_field(std::size_t rows, std::size_t columns);
};

