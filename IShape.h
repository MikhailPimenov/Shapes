#pragma once

#include <cstddef>

#include "Drawer.h"


class IShape
{
protected:
	Drawer m_field;
public:
	virtual const IShape& draw(std::size_t rows, std::size_t columns) const = 0;
	virtual const IShape& draw(Drawer &field) const = 0;
	virtual void show() const = 0;
	virtual void print_info() const = 0;
	virtual ~IShape();
};

