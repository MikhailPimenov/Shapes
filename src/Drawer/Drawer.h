#pragma once
#include <iostream>
#include <vector>

#include "../Math/MathFunctions.h"
#include "../Point/Point.h"
#include "../Shape/AngularShape/AngularShape.h"
#include "../Shape/Circle/Circle.h"
#include "../Shape/IShape.h"

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



/// <summary>
/// 
/// </summary>
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

	/// <summary>
	/// Constructs Drawer object with feild inside. 
	/// Definition area is automatically scaled not 
	/// to distort shapes
	/// </summary>
	/// <param name="rows">
	/// An unsigned integer, number of horizontal lines,
	/// vertical resolution
	/// </param>
	/// <param name="columns">
	/// An unsigned integer, number of vertical lines,
	/// horizontal resolution
	/// </param>
	Drawer(std::size_t rows, std::size_t columns);

	/// <summary>
	/// Constructs Drawer object with field inside
	/// </summary>
	/// <param name="rows">
	/// An unsigned integer, number of horizontal lines,
	/// vertical resolution
	/// </param>
	/// <param name="columns">
	/// An unsigned integer, number of vertical lines,
	/// horizontal resolution
	/// </param>
	/// <param name="filled_symbol">
	/// A char, symbol which will be used for drawing
	/// </param>
	/// <param name="empty_symbol">
	/// A char, symbol which will represent the obsence
	/// of shape or just empty place
	/// </param>
	/// <param name="minimum_y">
	/// A double, represents actual coordinate for the 
	/// very first line (upper line) of the field
	/// </param>
	/// <param name="range_y">
	/// A double, represents what continuous values are
	/// shown on the field from up to down. It is the
	/// difference between actual value for the very 
	/// first and the very last line of the field
	/// </param>
	/// <param name="minimum_x">
	/// A double, represents actual coordinate for the 
	/// very first column (left column) of the field
	/// </param>
	/// <param name="range_x">
	/// A double, represents what continuous values are
	/// shown on the field from left to right. It is the
	/// difference between actual value for the very 
	/// first (left) and the very last (right) column 
	/// of the field
	/// </param>
	Drawer(
		std::size_t rows,
		std::size_t columns,
		char filled_symbol,
		char empty_symbol,
		double minimum_y, 
		double range_y,
		double minimum_x,
		double range_x
	);

	/// <summary>
	/// Places the shape on the field using symbol 
	/// </summary>
	/// <param name="shape">
	/// Shape to be placed on the field
	/// </param>
	/// <param name="filled_symbol">
	/// A char, symbol which will be used to draw this
	/// shape on the field
	/// </param>
	void draw(const IShape& shape, char filled_symbol);
	
	/// <summary>
	/// Places the shape on the field
	/// </summary>
	/// <param name="shape">
	/// Shape to be placed on the field
	/// </param>
	void draw(const IShape& shape);

	/// <summary>
	/// Outputs field to console
	/// </summary>
	void print() const;


private:

	/// <summary>
	/// Calculates diagonal distance between two neighbour
	/// points on the field
	/// </summary>
	/// <returns> A double, diagonal distance</returns>
	double get_delta() const;

	/// <summary>
	/// Creates two-dimensional field with horizontal size columns
	/// and vertical size rows
	/// </summary>
	void create_empty_field();

	/// <summary>
	/// Creates array of x-values each of them corresponds
	/// to particular column of the field
	/// Creates array of y-values each of them corresponds
	/// to particular row of the field
	/// </summary>
	void create_definition_area();


	/// <summary>
	/// Calculates continuous value for current column
	/// on the field. It is where this column is
	/// located on a horizontal axis
	/// </summary>
	/// <param name="column">
	/// An unsigned integer, represents current column
	/// </param>
	/// <returns>
	/// A double, which is continuous value for current column
	/// </returns>
	double get_x_from_column(std::size_t column) const;

	/// <summary>
	/// Calculates continuous value for current row.
	/// It is where this row is located on a vertical axis
	/// </summary>
	/// <param name="row">
	/// An unsigned integer, represents current row
	/// </param>
	/// <returns>
	/// A double, which is continuous value for current row
	/// </returns>
	double get_y_from_row(std::size_t row) const;

	/// <summary>
	/// Calculates row which corresponds to this continuous 
	/// value on a vertical axis. If continuous value is
	/// not covered by the range, zero or maximal row will 
	/// be returned depending on the side where value is 
	/// relatively covering range
	/// </summary>
	/// <param name="y">
	/// A double, continuous value on vertical axis
	/// </param>
	/// <returns>
	/// An unsigned integer, row which corresponds given value
	/// </returns>
	std::size_t get_row_from_y(double y) const;

	/// <summary>
	/// Calculates column which corresponds to this continuous 
	/// value on a horizontal axis. If continuous value is
	/// not covered by the range, zero or maximal column will 
	/// be returned depending on the side where value is 
	/// relatively covering range
	/// </summary>
	/// <param name="x">
	/// A double, continuous value on horizontal axis
	/// </param>
	/// <returns>
	/// An unsigned integer, column which corresponds given value
	/// </returns>
	std::size_t get_column_from_x(double x) const;


	/// <summary>
	/// Places line between two points on the field using given symbol.
	/// Order of the points does not matter
	/// </summary>
	/// <param name="first">
	/// First point to connect on the field with line, contains two coordinates
	/// </param>
	/// <param name="second">
	/// Second point to connect on the field with line, contains two coordinates
	/// </param>
	/// <param name="filled_symbol">
	/// A char, symbol which will be used to draw line on the field
	/// </param>
	void draw_line(const Point& first, const Point& second, char filled_symbol); 
	
	/// <summary>
	/// Places line between two points on the field using given symbol.
	/// Order of the points does not matter.
	/// This function suits more horizontal line, in that case it garantees 
	/// that all the columns between points will be filled
	/// </summary>
	/// <param name="first">
	/// First point to connect on the field with line, contains two coordinates
	/// </param>
	/// <param name="second">
	/// Second point to connect on the field with line, contains two coordinates
	/// </param>
	/// <param name="filled_symbol">
	/// A char, symbol which will be used to draw line on the field
	/// </param>
	void draw_horizontal_line(const Point& first, const Point& second, char filled_symbol);  
	
	/// <summary>
	/// Places line between two points on the field using given symbol.
	/// Order of the points does not matter.
	/// This function suits more vertical line, in that case it garantees 
	/// that all the rows between points will be filled
	/// </summary>
	/// <param name="first">
	/// First point to connect on the field with line, contains two coordinates
	/// </param>
	/// <param name="second">
	/// Second point to connect on the field with line, contains two coordinates
	/// </param>
	/// <param name="filled_symbol">
	/// A char, symbol which will be used to draw line on the field
	/// </param>
	void draw_vertical_line(const Point& first, const Point& second, char filled_symbol);   


	/// <summary>
	/// Calculates vertical range for rows between two given points
	/// including these points: the very first row to begin with and 
	/// the row after the last row. The order of points does not matter
	/// </summary>
	/// <param name="first">
	/// First point, contains two coordinates
	/// </param>
	/// <param name="second">
	/// Second point, contains two coordinates
	/// </param>
	/// <returns>
	/// Object with two unsigned integers: row to begin with
	/// and row which goes after the last row included in range
	/// </returns>
	Range get_begin_and_end_rows(const Point& first, const Point& second);

	/// <summary>
	/// Calculates horizontal range for columns between two given points
	/// including these points: the very first column to begin with and 
	/// the column after the last column. The order of points does not matter
	/// </summary>
	/// <param name="first">
	/// First point, contains two coordinates
	/// </param>
	/// <param name="second">
	/// Second point, contains two coordinates
	/// </param>
	/// <returns>
	/// Object with two unsigned integers: column to begin with
	/// and column which goes after the last column included in range
	/// </returns>
	Range get_begin_and_end_columns(const Point& first, const Point& second);


	/// <summary>
	/// Places the shape with angles on the field using symbol 
	/// </summary>
	/// <param name="shape">
	/// Shape with angles to be placed on the field. Contains method
	/// to provide access to its vertices in some order
	/// </param>
	/// <param name="filled_symbol">
	/// A char, symbol which will be used to draw this
	/// shape on the field
	/// </param>
	void draw_angularshape(const AngularShape& shape, char filled_symbol);

	/// <summary>
	/// Places the shape with angles on the field using symbol 
	/// </summary>
	/// <param name="circle">
	/// Circle to be placed on the field. Contains methods to provide
	/// access to its center point and its radius
	/// </param>
	/// <param name="filled_symbol">
	/// A char, symbol which will be used to draw this
	/// circle on the field
	/// </param>
	void draw_circle(const Circle& circle, char filled_symbol);
	
};

