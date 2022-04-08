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
	/// A right double which will be compared with left one 
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

	/// <summary>
	/// Calculates y-value from given x-value for line which passes through 
	/// two points given. The order of the points does not matter. 
	/// </summary>
	/// <param name="x">A double to calculate y-value for</param>
	/// <param name="first">
	/// First point which line passes through on a two-dimensional area, 
	/// contains two double coordinates
	/// </param>
	/// <param name="second">
 	/// Second point which line passes through on a two-dimensional area, 
	/// contains two double coordinates
	/// </param>
	/// <returns>A double y where y = f(x) </returns>
	double get_y_from_x_for_line(double x, const Point& first, const Point& second);

	/// <summary>
	/// Calculates x-value from given y-value for line which passes through 
	/// two points given. The order of the points does not matter. 
	/// </summary>
	/// <param name="y">A double to calculate x-value for</param>
	/// <param name="first">
	/// First point which line passes through on a two-dimensional area, 
	/// contains two double coordinates
	/// </param>
	/// <param name="second">
	/// Second point which line passes through on a two-dimensional area, 
	/// contains two double coordinates
	/// </param>
	/// <returns>A double x where x = f-1(y) </returns>
	double get_x_from_y_for_line(double y, const Point& first, const Point& second);

	/// <summary>
	/// Returns true if dy > dx else false
	/// Checks if the angle between the line and positive direction 
	/// of x-axis is more than 45 degrees and less than 135 degrees.
	/// Line is given by two points it passes through
	/// </summary>
	/// <param name="first">
	/// First point line passes through, 
	/// contains two coordinates
	/// </param>
	/// <param name="second">
	/// Second point line passes through, 
	/// contains two coordinates
	/// </param>
	/// <returns>
	/// A bool which is true if line given by two points 
	/// has angle between positive direction of x-axis
	/// within 45 and 135 degrees, otherwise false.
	/// </returns>
	bool is_line_vertical(const Point& first, const Point& second);
	
	/// <summary>
	/// Returns true if dy <= dx else false
	/// Checks if the angle between the line and positive direction 
	/// of x-axis is less than 45 degrees or more than 135 degrees.
	/// Line is given by two points it passes through
	/// </summary>
	/// <param name="first">
	/// First point line passes through, 
	/// contains two coordinates
	/// </param>
	/// <param name="second">
	/// Second point line passes through, 
	/// contains two coordinates
	/// </param>
	/// <returns>
	/// A bool which is true if line given by two points 
	/// has angle between positive direction of x-axis
	/// not within 45 and 135 degrees, otherwise false.
	/// </returns>
	bool is_line_horizontal(const Point& first, const Point& second);
	
	/// <summary>
	/// Calculates continuous value which relates to particular 
	/// discrete value and number of discrete values,
	/// range of continuous values and starting value of continuous values
	/// (shift from zero)  
	/// </summary>
	/// <param name="discrete_coordinate">
	/// An unsigned integer which is discrete value to be converted
	/// </param>
	/// <param name="discrete_range">
	/// An int number of possible discrete values
	/// </param>
	/// <param name="continuous_range">
	/// A double which is difference between maximal and minimal 
	/// continuous values
	/// </param>
	/// <param name="continuous_shift">
	/// A double which is minimal continuous value, same as shift
	/// </param>
	/// <returns>
	/// A double which corresponds to discrete_coordinate
	/// </returns>
	double get_continuous_from_discrete_coordinate(
		std::size_t discrete_coordinate,
		std::size_t discrete_range,
		double continuous_range,
		double continuous_shift = 0.0
	);

	/// <summary>
	/// Calculates discrete value from continuous value using 
	/// number of possible discrete values, range of possible continuous
	/// values and starting continuous value. Mathematically rounds 
	/// to the nearest integer. If continous coordinate
	/// is not within definition area for continuous values, zero or
	/// max discrete coordinate is returned. 
	/// </summary>
	/// <param name="continuous_coordinate">
	/// A double which is a continuous value to be converted
	/// </param>
	/// <param name="discrete_range">
	/// An unsigned integer which represents number of possible
	/// discrete values, discrete range which corresponds to 
	/// continuous range
	/// </param>
	/// <param name="continuous_range">
	/// A double which represents difference between maximal
	/// and minimal possible continuous values, continuous range
	/// </param>
	/// <param name="continuous_minimum">
	/// A double which represents shift of continuous values
	/// relatively zero, it is minimal possible continuous values.
	/// </param>
	/// <returns>
	/// An unsigned integer which corresponds to continuous value
	/// with given ranges and shift
	/// </returns>
	std::size_t get_discrete_from_continuous_coordinate(
		double continuous_coordinate,
		std::size_t discrete_range,
		double continuous_range,
		double continuous_minimum = 0.0
	);
};