#pragma once
#include <cassert>
#include <iostream>
#include <vector>

#include "AngularShape.h"
#include "Circle.h"
#include "IShape.h"
#include "Point.h"


using Field_t = std::vector<std::vector<char>>;
using Area_t  = std::vector<double>;

namespace DrawerDefaults {
	const extern char filled_symbol;
	const extern char empty_symbol;

	const extern std::size_t rows;
	const extern std::size_t columns;

	const extern double minimum_x;
	const extern double range_x;

	const extern double minimum_y;
	const extern double range_y;

	const extern double ratio;
};




class Drawer {
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
	Area_t  m_area_x;
	Area_t  m_area_y;

	struct Range {
		std::size_t m_begin;
		std::size_t m_end;
	};


public:
	Drawer(std::size_t rows, std::size_t columns);
	Drawer(std::size_t rows, std::size_t columns, char filled_symbol, char empty_symbol, double minimum_y, double range_y, double minimum_x, double range_x);

	void print_field() const;




private:
	double get_delta() const;

	void create_empty_field();
	void create_definition_area();

	double get_x_from_column(std::size_t column) const;
	double get_y_from_row(std::size_t row) const;
	std::size_t get_row_from_y(double y) const;
	std::size_t get_column_from_x(double x) const;


	void draw_line(const Point &first, const Point &second, char filled_symbol); //  private
	
	void draw_horizontal_line(const Point& left, const Point& right, char filled_symbol); //  private  
	void draw_vertical_line(const Point& left, const Point& right, char filled_symbol);   //  private

	Range get_begin_and_end_rows(const Point& first, const Point& second);     //  private
	Range get_begin_and_end_columns(const Point& first, const Point& second);  //  private

	void draw_angularshape(const AngularShape& shape, char filled_symbol);   //  private
	void draw_circle(const Circle& circle, char filled_symbol);              //  private



public:
	void draw(const IShape& shape, char filled_symbol);
	void draw(const IShape& shape);
};

