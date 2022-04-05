#pragma once

#include <cstddef>


class IShape {
public:
	virtual void print_info() const = 0;
	virtual ~IShape();
};

