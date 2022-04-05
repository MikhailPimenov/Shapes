#include "Drawer.h"



namespace DrawerDefaults {
	const char filled_symbol  = '*';
	const char empty_symbol   = '.';

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



Drawer::Drawer() 
	:
	m_filled_symbol{ DrawerDefaults::filled_symbol },
	m_empty_symbol{ DrawerDefaults::empty_symbol },
	m_rows{ DrawerDefaults::rows },
	m_columns{ DrawerDefaults::columns },
	m_minimum_x{ DrawerDefaults::minimum_x },
	m_range_x{ DrawerDefaults::range_x },
	m_minimum_y{ DrawerDefaults::minimum_y },
	m_range_y{ DrawerDefaults::range_y * DrawerDefaults::ratio }
	
{
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
	m_area.resize(m_columns);

	const double dx = m_range_x / static_cast<double>(m_columns);
	double current_x = m_minimum_x;
	for (std::size_t column = 0; column < m_columns; ++column) {
		m_area[column] = current_x;
		current_x += dx;
	}
}

std::size_t Drawer::get_row_from_y(double y) const {
	return m_rows * (y - m_minimum_y) / m_range_y ;
}

void Drawer::draw_angularshape(const AngularShape& shape) {
	const std::size_t size     = shape.vertices().size();
	const Vertices_t& vertices = shape.vertices();

	for (std::size_t index = 0ull; index < size; ++index)
		draw_line(vertices.at(index), vertices.at((index + 1ull) % size));
}

void Drawer::draw(const IShape& shape) {
	const Circle* circle = dynamic_cast<const Circle*>(&shape);
	if (circle) {
		draw_circle(*circle);
		return;
	}

	const AngularShape* angular = dynamic_cast<const AngularShape*>(&shape);
	if (angular) {
		draw_angularshape(*angular);
		return;
	}
}

double get_distance(const Point& a, const Point& b) {
	return std::sqrt((a.x() - b.x()) * (a.x() - b.x()) + (a.y() - b.y()) * (a.y() - b.y()));
}
void Drawer::draw_circle(const Point& center, double radius, char filled_symbol) {
	const double dx = m_range_x / static_cast<double>(m_columns);
	const double dy = m_range_y / static_cast<double>(m_rows);
	const double delta = get_distance(Point(dx, dy), Point(0.0, 0.0));

	for (std::size_t row = 0u; row < m_rows; ++row) {
		const double y = get_y_from_row(row);
		
		for (std::size_t column = 0u; column < m_columns; ++column) {
			const double x = get_x_from_column(column);
			const Point point(x, y);
			const double distance = get_distance(center, point);
			
			if (radius - delta / 3.0 < distance && distance < radius + delta / 3.0) {
				m_field[row][column] = filled_symbol;
			}
		}
	}
}
void Drawer::draw_circle(const Circle& circle) {
	draw_circle(circle.center(), circle.radius(), '*');
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

bool are_equal(double left, double right) {
	//std::cout << "are_equal():  left = " << left << " right = " << right << ' ';
	static const double epsilon = 1e-12;
	//std::cout << ((left > right) ? (left - right < epsilon) : (right - left < epsilon)) << '\n';
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

void Drawer::draw_horizontal_line(const Point& first, const Point& second, char filled_symbol) {
	const Range column_range = get_begin_and_end_columns(first, second);

	for (std::size_t column = column_range.m_begin; column < column_range.m_end; ++column) {
		const double y = get_y_from_x(m_area_x[column], first, second);
		const std::size_t row = get_row_from_y(y);

		//std::cout << m_area[column] << "\t\t" << y << "\t\t" << column << '\t' << row << '\n';
		if (0u <= row && row < m_rows && 0u <= column && column < m_columns)  //  get rid of column comparisson 
			m_field[row][column] = filled_symbol;
	}
}

//Drawer::Range Drawer::get_begin_and_end_rows(const Point& first, const Point& second) {
//	const Point lower = first.y() <  second.y() ? first : second;
//	const Point upper = first.y() >= second.y() ? first : second;
//
//	const std::size_t lower_row = get_row_from_y(lower.y());
//	const std::size_t upper_row = get_row_from_y(upper.y()) + 1ull;
//
//	Range result;
//	result.m_begin = lower_row >= 0ull   ? lower_row : 0ull;
//	result.m_end   = upper_row <= m_rows ? upper_row : m_rows;
//
//	return result;
//}

Drawer::Range Drawer::get_range(
	double first, 
	double second, 
	std::size_t length, 
	std::size_t (Drawer::*get_discrete_from_continuous)(double) const
) {
	const double lower   = first <  second ? first : second;
	const double greater = first >= second ? first : second;

	const std::size_t lower_discrete   = (this->*get_discrete_from_continuous)(lower);
	const std::size_t greater_discrete = (this->*get_discrete_from_continuous)(greater);
	
	Range result;
	result.m_begin = lower_discrete   >= 0ull   ? lower_discrete   : 0ull;
	result.m_end   = greater_discrete <= length ? greater_discrete : length;

	return result;
}
Drawer::Range Drawer::get_begin_and_end_rows(const Point& first, const Point& second) {
	return get_range(first.y(), second.y(), m_rows, &(Drawer::get_row_from_y));
}
//Drawer::Range Drawer::get_begin_and_end_columns(const Point& first, const Point& second) {
//	const Point left  = first.x() <  second.x() ? first : second;
//	const Point right = first.x() >= second.x() ? first : second;
//
//	const std::size_t left_column  = get_column_from_x(left.x());
//	const std::size_t right_column = get_column_from_x(right.x()) + 1ull;
//
//	Range result;
//	result.m_begin = left_column  >= 0ull      ? left_column  : 0ull;
//	result.m_end   = right_column <= m_columns ? right_column : m_columns;
//
//	return result;
//}

void Drawer::draw_vertical_line(const Point& first, const Point& second, char filled_symbol) {
	const Range row_range = get_begin_and_end_rows(first, second);

	for (std::size_t row = row_range.m_begin; row < row_range.m_end; ++row) {
		const double x = get_x_from_y(m_area_y[row], first, second);
		const std::size_t column = get_column_from_x(x);

		//std::cout << m_area[column] << "\t\t" << y << "\t\t" << column << '\t' << row << '\n';
		if (0u <= column && column < m_rows && 0u <= row && row < m_columns)  //  get rid of row comparisson 
			m_field[row][column] = filled_symbol;
	}
}

bool is_line_vertical(const Point &first, const Point &second) {
	return std::abs(first.y() - second.y()) > std::abs(first.x() - second.x());
}
bool is_line_horizontal(const Point& first, const Point& second) {
	return !is_line_vertical(first, second);
}


void Drawer::draw_line(const Point &first, const Point &second, char filled_symbol) {
	std::cout << "first: " << first << "; second: " << second << '\n';
	
	const Point  left_point = (first.x() <  second.x()) ? first : second;
	const Point right_point = (first.x() >= second.x()) ? first : second;

	const double  left_x = (left_point.x()  > m_minimum_x) ? left_point.x() : m_minimum_x;
	const double right_x = (right_point.x() <= m_minimum_x + m_range_x) ? right_point.x() : m_minimum_x + m_range_x;
	//std::cout << "left_x = " << left_x << " right_x = " << right_x << '\n';

	const std::size_t  left_column = get_column_from_x(left_x);
	const std::size_t right_column = get_column_from_x(right_x);
	//std::cout << "left_column = " << left_column << " right_column = " << right_x << '\n';

	//assert(0u <= left_column && "Left column should not be negative!");
	//assert(0u <= right_column && "Right column should not be negative!");
	//assert(left_column < m_columns && "Left column should be less than maximum column!");
	//assert(right_column <= m_columns && "Right column should not be greater than maximum column!");

	
	const Point upper_point = (first.y() >  second.y()) ? first : second;
	const Point lower_point = (first.y() <= second.y()) ? first : second;

	const double lower_y = (lower_point.y() > m_minimum_y) ? lower_point.y() : m_minimum_y;
	const double upper_y = (upper_point.y() <= m_minimum_y + m_range_y) ? upper_point.y() : m_minimum_y + m_range_y;

	const std::size_t upper_row = get_row_from_y(upper_y);
	const std::size_t lower_row = get_row_from_y(lower_y);

	const std::size_t length_row    = upper_row - lower_row + 1u;
	const std::size_t length_column = right_column - left_column + 1u;

	const bool straight_order = ((first.x() - second.x()) * (first.y() - second.y()) > 0.0);
	std::cout << "x\t\ty\t\tcolumn\trow\n";
	if (std::abs(first.y() - second.y()) > std::abs(first.x() - second.x())) {
		std::cout << (straight_order ? "straight" : "reversed") << '\n';
		std::cout << "vertical:\n";
		Area_t area;
		area.resize(length_row);
		
		const double dx = (straight_order ? 1 : -1) * (right_x - left_x) / static_cast<double>(length_row);
		double current_x = straight_order ? left_x : right_x;
		
		
		for (std::size_t index = 0u; index < length_row; ++index) {
			area[index] = current_x;
			current_x += dx;
		}
		for (std::size_t row = 0; row < length_row; ++row) {
			const double y = get_y_from_x(area[row], first, second);
			const std::size_t column = get_column_from_x(area[row]);

			std::cout << area[row] << "\t\t" << y << "\t\t" << column << '\t' << row + lower_row << '\n';
			if (0u <= column && column < m_columns && 0u <= lower_row + row && lower_row + row < m_rows)
				m_field[lower_row + row][column] = filled_symbol;
		}
	} else {
		std::cout << "horizontal:\n";
		for (std::size_t column = left_column; column < right_column; ++column) {
			const double y = get_y_from_x(m_area[column], first, second);
			const std::size_t row = get_row_from_y(y);

			std::cout << m_area[column] << "\t\t" << y << "\t\t" << column << '\t' << row << '\n';
			if (0u <= row && row < m_rows && 0u <= column && column < m_columns)
				m_field[row][column] = filled_symbol;
		} 
	}
}
