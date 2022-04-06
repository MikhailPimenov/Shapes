#pragma once

#include "IShape.h"
#include "Point.h"

class Circle : public IShape {
private:
    Point  m_center;
    double m_radius;
public:
    Circle();
    Circle(double x, double y, double radius);
    Circle(const Point& center, double radius);
    virtual ~Circle() override;

    virtual void print_info() const override;

    const Point& center() const;
    double radius() const;
};

