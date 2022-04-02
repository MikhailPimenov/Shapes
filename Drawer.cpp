#include "Drawer.h"

Drawer::Drawer() 
	:
	m_filled_symbol{ '*' }, 
	m_empty_symbol{' '}, 
	m_rows{27u}, 
	m_columns{48u},
	m_minimum_x{0.0},
	m_range_x{16.0},
	m_minimum_y{0.0},
	m_range_y{9.0}
	
{
	create_empty_field();
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
	m_filled_symbol{filled_symbol},
	m_empty_symbol{empty_symbol},
	m_rows{rows},
	m_columns{columns},
	m_minimum_x{minimum_x},
	m_range_x{range_x},
	m_minimum_y{minimum_y},
	m_range_y{range_y}
{
	create_empty_field();
	create_definition_area();
}

//Drawer::Drawer(
//	std::size_t rows, 
//	std::size_t columns) 
//	: 
//	m_filled_symbol{ '*' }, 
//	m_empty_symbol{ ' ' }, 
//	m_rows{ rows }, 
//	m_columns{ columns }
//{
//	create_empty_field();
//}
//
//Drawer::Drawer(
//	std::size_t rows,
//	std::size_t columns,
//	char filled_symbol,
//	char empty_symbol)
//	:
//	m_filled_symbol{ filled_symbol },
//	m_empty_symbol{ empty_symbol },
//	m_rows{ rows },
//	m_columns{ columns }
//{
//	create_empty_field();
//}

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
std::size_t Drawer::get_column_from_x(double x) const {
	return m_columns * (x - m_minimum_x) / m_range_x;
}

bool are_equal(double left, double right) {
	//std::cout << "are_equal():  left = " << left << " right = " << right << ' ';
	static const double epsilon = 1e-12;
	//std::cout << ((left > right) ? (left - right < epsilon) : (right - left < epsilon)) << '\n';
	return (left > right) ? (left - right < epsilon) : (right - left < epsilon);
}
double f(double x, const Point& first, const Point& second) {
	//  TODO: Consider zero-division 
	if (are_equal(first.x(), second.x())) {
		//std::cout << "Zero-division prevented!\n";
		return first.y();
	}

	const double tan_alpha = (second.y() - first.y()) / (second.x() - first.x());

	return tan_alpha * (x - first.x()) + first.y();
}

void Drawer::draw_line(const Point &first, const Point &second, char filled_symbol) {
	const Point  left_point = (first.x() <  second.x()) ? first : second;
	const Point right_point = (first.x() >= second.x()) ? first : second;

	const double  left_x = (left_point.x()  > m_minimum_x) ? left_point.x() : m_minimum_x;
	const double right_x = (right_point.x() <= m_minimum_x + m_range_x) ? right_point.x() : m_minimum_x + m_range_x;
	//std::cout << "left_x = " << left_x << " right_x = " << right_x << '\n';

	const std::size_t  left_column = get_column_from_x(left_x);
	const std::size_t right_column = get_column_from_x(right_x);
	//std::cout << "left_column = " << left_column << " right_column = " << right_x << '\n';

	assert(0u <= left_column && "Left column should not be negative!");
	assert(0u <= right_column && "Right column should not be negative!");
	assert(left_column < m_columns && "Left column should be less than maximum column!");
	assert(right_column <= m_columns && "Right column should not be greater than maximum column!");

	
	const Point upper_point = (first.y() >  second.y()) ? first : second;
	const Point lower_point = (first.y() <= second.y()) ? first : second;

	const double lower_y = (lower_point.y() > m_minimum_y) ? lower_point.y() : m_minimum_y;
	const double upper_y = (upper_point.y() <= m_minimum_y + m_range_y) ? upper_point.y() : m_minimum_y + m_range_y;

	const std::size_t upper_row = get_row_from_y(upper_y);
	const std::size_t lower_row = get_row_from_y(lower_y);

	const std::size_t length_row    = upper_row - lower_row + 1u;
	const std::size_t length_column = right_column - left_column + 1u;

	std::cout << "x\t\ty\t\tcolumn\trow\n";
	//if (length_row > length_column) {
	if (std::abs(first.y() - second.y()) > std::abs(first.x() - second.x())) {
		std::cout << "vertical:\n";
		Area_t area;
		area.resize(length_row);
		const double dx = (right_x - left_x) / static_cast<double>(length_row);
		double current_x = left_x;

		for (std::size_t index = 0u; index < length_row; ++index) {
			area[index] = current_x;
			current_x += dx;
		}
		for (std::size_t row = 0; row < length_row; ++row) {
			const double y = f(area[row], first, second);
			const std::size_t column = get_column_from_x(area[row]);

			std::cout << area[row] << "\t\t" << y << "\t\t" << column << '\t' << row + lower_row << '\n';
			if (0u <= column && column < m_columns && 0u <= lower_row + row && lower_row + row < m_rows)
				m_field[lower_row + row][column] = filled_symbol;
		}

	} else {
		std::cout << "horizontal:\n";
		for (std::size_t column = left_column; column <= right_column; ++column) {
			const double y = f(m_area[column], first, second);
			const std::size_t row = get_row_from_y(y);

			std::cout << m_area[column] << "\t\t" << y << "\t\t" << column << '\t' << row << '\n';
			if (0u <= row && row < m_rows && 0u <= column && column < m_columns)
				m_field[row][column] = filled_symbol;
		} 
	}
}
