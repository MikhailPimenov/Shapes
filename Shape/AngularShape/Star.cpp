#include "Star.h"
//18 90 162 234 306


const double pi = std::acos(-1.0);
const double pi_devided_by_180 = pi / 180.0;

static const Star_angles_t g_angles{ 
	pi_devided_by_180 * (360.0 - 90.0), 
	pi_devided_by_180 * (360.0 - 306.0), 
	pi_devided_by_180 * (360.0 - 162.0), 
	pi_devided_by_180 * (360.0 - 18.0), 
	pi_devided_by_180 * (360.0 - 234.0) 
};


Star::Star() : AngularShape{ {
		Point(std::cos(g_angles[0ull]),  std::sin(g_angles[0ull])),
		Point(std::cos(g_angles[1ull]),  std::sin(g_angles[1ull])),
		Point(std::cos(g_angles[2ull]),  std::sin(g_angles[2ull])),
		Point(std::cos(g_angles[3ull]),  std::sin(g_angles[3ull])),
		Point(std::cos(g_angles[4ull]),  std::sin(g_angles[4ull]))
} } {
}

Star::Star(const Point& center, double radius) : AngularShape{ {
		Point(
			center.x() + radius * std::cos(g_angles[0ull]),
			center.y() + radius * std::sin(g_angles[0ull])
		),
		Point(
			center.x() + radius * std::cos(g_angles[1ull]),
			center.y() + radius * std::sin(g_angles[1ull])
		),
		Point(
			center.x() + radius * std::cos(g_angles[2ull]),
			center.y() + radius * std::sin(g_angles[2ull])
		),
		Point(
			center.x() + radius * std::cos(g_angles[3ull]),
			center.y() + radius * std::sin(g_angles[3ull])
		),
		Point(
			center.x() + radius * std::cos(g_angles[4ull]),
			center.y() + radius * std::sin(g_angles[4ull])
		)
}}
{
}

Star::~Star() {
}

void Star::print_info() const {
	std::cout << "Star(";
	print_vertices();
	std::cout << ")\n";
}
