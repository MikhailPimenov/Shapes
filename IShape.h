#pragma once

/// <summary>
/// Interface for every particular shape
/// </summary>
class IShape
{
public:
	virtual void draw(int rows, int columns) const = 0;
	virtual void print_info() const = 0;
	virtual ~IShape();
};

