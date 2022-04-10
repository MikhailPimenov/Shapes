#include "MathFunctions.h"

namespace Math {

    double get_distance(const Point& a, const Point& b) {
        return std::sqrt((a.x() - b.x()) * (a.x() - b.x()) + (a.y() - b.y()) * (a.y() - b.y()));
    }

    bool is_between(double x, double lower, double greater) {
        return (lower < x) && (x < greater);
    }

    double get_delta(double range_x, std::size_t length_x, double range_y, std::size_t length_y) {
        const double dx = range_x / static_cast<double>(length_x);
        const double dy = range_y / static_cast<double>(length_y);
        return get_distance(Point(dx, dy), Point(0.0, 0.0));
    }

    bool are_equal(double left, double right, double epsilon) {
        return (left > right) ? (left - right < epsilon) : (right - left < epsilon);
    }

    double get_y_from_x_for_line(double x, const Point& first, const Point& second) {
        //  Zero-division case, when line is vertical 
        if (are_equal(first.x(), second.x())) {
            return first.y();
        }

        const double tangent_alpha = (second.y() - first.y()) / (second.x() - first.x());
        return tangent_alpha * (x - first.x()) + first.y();
    }
    double get_x_from_y_for_line(double y, const Point& first, const Point& second) {
        //  Zero-division case, when line is horizontal
        if (are_equal(first.y(), second.y())) {
            return first.x();
        }

        const double cotangent_alpha = (second.x() - first.x()) / (second.y() - first.y());
        return cotangent_alpha * (y - first.y()) + first.x();
    }

    bool is_line_vertical(const Point& first, const Point& second) {
        return std::abs(first.y() - second.y()) > std::abs(first.x() - second.x());
    }
    bool is_line_horizontal(const Point& first, const Point& second) {
        return !is_line_vertical(first, second);
    }



    double get_continuous_from_discrete_coordinate(
        std::size_t discrete_coordinate,
        std::size_t discrete_range,
        double continuous_range,
        double continuous_minimum
    ) {
        const double ratio =
            static_cast<double>(discrete_coordinate) /
            static_cast<double>(discrete_range);

        return continuous_range * ratio + continuous_minimum;
    }
    signed long long int get_discrete_from_continuous_coordinate(
        double continuous_coordinate,
        std::size_t discrete_range,
        double continuous_range,
        double continuous_minimum
    ) {
        const double shifted = continuous_coordinate - continuous_minimum;
        const double ratio = shifted / continuous_range;

        return std::llround(static_cast<double>(discrete_range) * ratio);
    }
};  //  namespace Math