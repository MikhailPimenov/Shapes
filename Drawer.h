#pragma once
#include <cassert>
#include <iostream>
#include <vector>


#include "Circle.h"
#include "Point.h"

using Field_t = std::vector<std::vector<char>>;
using Area_t  = std::vector<double>;

class Drawer
{
private:
	char m_filled_symbol;
	char  m_empty_symbol;

	std::size_t m_rows;
	std::size_t m_columns;

	double m_minimum_x;
	double m_range_x;
	double m_minimum_y;
	double m_range_y;

	Field_t m_field;
	Area_t  m_area;
public:
	Drawer();
	//Drawer(std::size_t rows, std::size_t columns);
	//Drawer(std::size_t rows, std::size_t columns, char filled_symbol, char empty_symbol);
	Drawer(std::size_t rows, std::size_t columns, char filled_symbol, char empty_symbol, double minimum_y, double range_y, double minimum_x, double range_x);
	

	void print_field() const;
private:
	void create_empty_field();
	void create_definition_area();
	std::size_t get_row_from_y(double y) const;
	double get_x_from_column(std::size_t column) const;
	double get_y_from_row(std::size_t row) const;

	std::size_t get_column_from_x(double x) const;

public:
	void draw_line(const Point &first, const Point &second, char filled_symbol = '*');
	void draw_circle(const Circle& circle, char filled_symbol = '*');
};

