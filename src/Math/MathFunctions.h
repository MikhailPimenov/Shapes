#pragma once

#include <cmath>

#include "../Point/Point.h"

/// <summary>
/// Some functions with calculations
/// </summary>
namespace Math {
	/// <summary>
	/// Calculates the distance between two points.
	/// Order of the points does not matter
	/// </summary>
	/// <param name="a">First Point, contains two coordinates of type double</param>
	/// <param name="b">Second Point, contains two coordinates of type double</param>
	/// <returns>A double which is the distance between points</returns>
	double get_distance(const Point& a, const Point& b);

	/// <summary>
	/// Checks if x is greater than lower and lower than greater
	/// lower < x < greater
	/// </summary>
	/// <param name="x">A double which will be checked if it is between
	/// lower and greater</param>
	/// <param name="lower">A double which is lower boundary</param>
	/// <param name="greater">A double which is greater boundary</param>
	/// <returns>A bool which is true if lower < x < greater, otherwise false</returns>
	bool is_between(double x, double lower, double greater);

	/// <summary>
	/// Calculates the biggest distance two neighbors can have in 
	/// two-dimensional array. It is diagonal line
	/// </summary>
	/// <param name="range_x">
	/// A double which contains horizontal range of continuous 
	/// values which is associated with the whole width
	/// </param>
	/// <param name="length_x">
	/// An unsigned integer which is a number of discrete elements 
	/// in horizontal dimension, discrete width
	/// </param>
	/// <param name="range_y">
	/// A double which contains vertical range of continuous 
	/// values which is associated with the whole height
	/// </param>
	/// <param name="length_y">
	/// An unsigned integer which is a number of discrete elements 
	/// in vertical dimension, discrete height
	/// </param>
	/// <returns>
	/// A double which represents the distance between two nearest 
	/// diagonally located neighbours
	/// </returns>
	double get_delta(double range_x, std::size_t length_x, double range_y, std::size_t length_y);

	/// <summary>
	/// Compares two numbers of double with some precision of epsilon
	/// </summary>
	/// <param name="left">
	/// A left double which will be compared with right one 
	/// </param>
	/// <param name="right">
	/// A left double which will be compared with right one 
	/// </param>
	/// <param name="epsilon">
	/// A double which is a minimal difference between left and right
	/// when they are considered as equal 
	/// </param>
	/// <returns>
	/// A bool which is true left and right are considered as equal, 
	/// otherwise is false
	/// </returns>
	bool are_equal(double left, double right, double epsilon = 1e-12);

	double get_y_from_x_for_line(double x, const Point& first, const Point& second);

	double get_x_from_y_for_line(double y, const Point& first, const Point& second);

	bool is_line_vertical(const Point& first, const Point& second);
	
	bool is_line_horizontal(const Point& first, const Point& second);
	
	double get_continuous_from_discrete_coordinate(
		std::size_t discrete_coordinate,
		std::size_t discrete_range,
		double continuous_range
	);

	std::size_t get_discrete_from_continuous_coordinate(
		double continuous_coordinate,
		std::size_t discrete_range,
		double continuous_range,
		double continuous_minimum
	);
};