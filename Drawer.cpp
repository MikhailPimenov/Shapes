#include "Drawer.h"



namespace DrawerDefaults {
	const char filled_symbol  = '.';
	const char empty_symbol   = ' ';

	const std::size_t rows    = 0u;
	const std::size_t columns = 0u;

	const double minimum_x    = 0.0;
	const double range_x      = 0.0;

	const double minimum_y    = 0.0;
	const double range_y      = 0.0;

	//  ratio to make vertical and horizontal gaps between points in console 
	//  equal to each other (to make circle look like circle, but not like ellips)
	const double ratio        = 0.575;
}


Drawer::Drawer(std::size_t rows, std::size_t columns)
	:
	m_filled_symbol{ DrawerDefaults::filled_symbol },
	m_empty_symbol{ DrawerDefaults::empty_symbol },
	m_rows{ rows },
	m_columns{ columns },
	m_minimum_x{ DrawerDefaults::minimum_x },
	m_range_x{ static_cast<double>(columns) * DrawerDefaults::ratio },
	m_minimum_y{ DrawerDefaults::minimum_y },
	m_range_y{ static_cast<double>(rows) }
{
	create_empty_field();
	create_definition_area();
}

Drawer::Drawer(
	std::size_t rows, 
	std::size_t columns, 
	char filled_symbol, 
	char empty_symbol, 
	double minimum_y, 
	double range_y,
	double minimum_x, 
	double range_x 
)
	:
	m_filled_symbol{ filled_symbol },
	m_empty_symbol{ empty_symbol },
	m_rows{ rows },
	m_columns{ columns },
	m_minimum_x{ minimum_x },
	m_range_x{ range_x },
	m_minimum_y{ minimum_y },
	m_range_y{ range_y }
{
	create_empty_field();
	create_definition_area();
}


void Drawer::print_field() const {
	for (const auto& line : m_field) {
		for (char symbol : line)
			std::cout << symbol;
		std::cout << '\n';
	}
}

void Drawer::create_empty_field() {
	m_field.resize(m_rows);
	for (auto& line : m_field)
		line.resize(m_columns, m_empty_symbol);
}

void Drawer::create_definition_area() {
	m_area_x.resize(m_columns);

	const double dx  = m_range_x / static_cast<double>(m_columns);
	double current_x = m_minimum_x;
	for (std::size_t column = 0ull; column < m_columns; ++column) {
		m_area_x[column] = current_x;
		current_x += dx;
	}

	m_area_y.resize(m_rows);

	const double dy  = m_range_y / static_cast<double>(m_rows);
	double current_y = m_minimum_y;
	for (std::size_t row = 0ull; row < m_rows; ++row) {
		m_area_y[row] = current_y;
		current_y += dy;
	}
}




void Drawer::draw_angularshape(const AngularShape& shape, char symbol) {
	const std::size_t size     = shape.vertices().size();
	const Vertices_t& vertices = shape.vertices();

	for (std::size_t index = 0ull; index < size; ++index)
		draw_line(vertices.at(index), vertices.at((index + 1ull) % size), symbol);
}

void Drawer::draw(const IShape& shape, char filled_symbol) {
	const Circle* circle = dynamic_cast<const Circle*>(&shape);
	if (circle) {
		draw_circle(*circle, filled_symbol);
		return;
	}

	const AngularShape* angular = dynamic_cast<const AngularShape*>(&shape);
	if (angular) {
		draw_angularshape(*angular, filled_symbol);
		return;
	}
}
void Drawer::draw(const IShape& shape) {
	draw(shape, m_filled_symbol);
}

static double get_distance(const Point& a, const Point& b) {
	return std::sqrt((a.x() - b.x()) * (a.x() - b.x()) + (a.y() - b.y()) * (a.y() - b.y()));
}
double Drawer::get_delta() const {
	const double dx = m_range_x / static_cast<double>(m_columns);
	const double dy = m_range_y / static_cast<double>(m_rows);
	return get_distance(Point(dx, dy), Point(0.0, 0.0));
}
static bool is_between(double x, double lower, double greater) {
	return (lower < x) && (x < greater);
}




void Drawer::draw_circle(const Circle& circle, char filled_symbol) {
	const double delta  = get_delta();
	const Point center(
		get_x_from_column(get_column_from_x(circle.center().x())),
		get_y_from_row(get_row_from_y(circle.center().y()))
	);
	const double radius = circle.radius();
	

	for (std::size_t row = 0u; row < m_rows; ++row) {
		const double y = get_y_from_row(row);

		for (std::size_t column = 0u; column < m_columns; ++column) {
			const double x = get_x_from_column(column);
			const Point point(x, y);
			const double distance = get_distance(center, point);

			if (is_between(distance, radius - delta / 3.0, radius + delta / 3.0)) {
				m_field[row][column] = filled_symbol;
			}
		}
	}
}



double Drawer::get_x_from_column(std::size_t column) const {
	return m_range_x * static_cast<double>(column) / static_cast<double>(m_columns);
}
double Drawer::get_y_from_row(std::size_t row) const {
	return m_range_y * static_cast<double>(row) / static_cast<double>(m_rows);
}
std::size_t Drawer::get_column_from_x(double x) const {
	return m_columns * (x - m_minimum_x) / m_range_x;
}
std::size_t Drawer::get_row_from_y(double y) const {
	return m_rows * (y - m_minimum_y) / m_range_y ;
}
static bool are_equal(double left, double right) {
	static const double epsilon = 1e-12;
	return (left > right) ? (left - right < epsilon) : (right - left < epsilon);
}
static double get_y_from_x(double x, const Point& first, const Point& second) {
	if (are_equal(first.x(), second.x())) {
		return first.y();
	}

	const double tan_alpha = (second.y() - first.y()) / (second.x() - first.x());
	return tan_alpha * (x - first.x()) + first.y();
}
static double get_x_from_y(double y, const Point& first, const Point& second) {
	if (are_equal(first.y(), second.y())) {
		return first.x();
	}

	const double tan_alpha = (second.x() - first.x()) / (second.y() - first.y());
	return tan_alpha * (y - first.y()) + first.x();
}
Drawer::Range Drawer::get_begin_and_end_rows(const Point& first, const Point& second) {
	const double lower   = first.y() <  second.y() ? first.y() : second.y();
	const double greater = first.y() >= second.y() ? first.y() : second.y();

	Range result;
	if (lower < m_minimum_y)
		result.m_begin = 0ull;
	else if (lower > m_minimum_y + m_range_y)
		result.m_begin = m_rows;
	else
		result.m_begin = get_row_from_y(lower);

	if (greater < m_minimum_y)
		result.m_end = 0ull;
	else if (greater > m_minimum_y + m_range_y)
		result.m_end = m_rows;
	else
		result.m_end = get_row_from_y(greater) + 1ull;

	return result;
}
Drawer::Range Drawer::get_begin_and_end_columns(const Point& first, const Point& second) {
	const double lower = first.x() < second.x() ? first.x() : second.x();
	const double greater = first.x() >= second.x() ? first.x() : second.x();

	Range result;
	if (lower < m_minimum_x)
		result.m_begin = 0ull;
	else if (lower > m_minimum_x + m_range_x)
		result.m_begin = m_columns;
	else
		result.m_begin = get_column_from_x(lower);

	if (greater < m_minimum_x)
		result.m_end = 0ull;
	else if (greater > m_minimum_x + m_range_x)
		result.m_end = m_columns;
	else
		result.m_end = get_column_from_x(greater) + 1ull;

	return result;
}
void Drawer::draw_horizontal_line(const Point& first, const Point& second, char filled_symbol) {
	const Range column_range = get_begin_and_end_columns(first, second);

	for (std::size_t column = column_range.m_begin; column < column_range.m_end; ++column) {
		const double y = get_y_from_x(m_area_x[column], first, second);
		const std::size_t row = get_row_from_y(y);

		if (0u <= row && row < m_rows) 
			m_field[row][column] = filled_symbol;
	}
}
void Drawer::draw_vertical_line(const Point& first, const Point& second, char filled_symbol) {
	const Range row_range = get_begin_and_end_rows(first, second);

	for (std::size_t row = row_range.m_begin; row < row_range.m_end; ++row) {
		const double x = get_x_from_y(m_area_y[row], first, second);
		const std::size_t column = get_column_from_x(x);

		if (0u <= column && column < m_columns) 
			m_field[row][column] = filled_symbol;
	}
}
bool is_line_vertical(const Point &first, const Point &second) {
	return std::abs(first.y() - second.y()) > std::abs(first.x() - second.x());
}
bool is_line_horizontal(const Point& first, const Point& second) {
	return !is_line_vertical(first, second);
}
void Drawer::draw_line(const Point& first, const Point& second, char filled_symbol) {
	if (is_line_vertical(first, second)) {
		draw_vertical_line(first, second, filled_symbol);
		return;
	}

	draw_horizontal_line(first, second, filled_symbol);
}
