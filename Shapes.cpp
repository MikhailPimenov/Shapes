// Shapes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Необходимо привести пример программы или библиотеки на C++, 
которая выводит на экран различные геометрические фигуры: 
круг, квадрат, треугольник, прямоугольник и т.п. 
Глубина проработки примера (количество фигур, параметры, методы) 
на Ваше усмотрение. Программа не обязательно должна запускаться 
и работать (хотя это будет плюсом).
*/


#include <iostream>
#include <memory>
#include <vector>

#include "Circle.h"
#include "Drawer.h"
#include "Triangle.h"

using Shapes_t = std::vector<std::unique_ptr<IShape>>;

void print_shapes(const Shapes_t& shapes) {
	Drawer field(24u, 88u);
	for (const auto& shape : shapes) {
		shape->print_info();
		field.draw(*shape);

	}
	field.print_field();
}


int main() {
	//Drawer field4(24, 100, '*', '.', 0.0, 24.0, 0.0, 55.0);
	//Drawer field4(24, 100);

	//field4.draw_circle(Point(24.0, 12.0), 10.0);
	//field4.print_field();//


	//Triangle t;
	//t.initialize_field(20ull, 30ull);
	//t.initialize_field(25ull, 35ull);
	//t.initialize_field(25ull, 35ull);
	//Triangle t;
	//t.print_info();
	//t.draw(24u, 88u);


	//Circle c(Point(10.0, 10.0), 5.0);
	//c.print_info();
	//c.draw(24u, 88u);

	Shapes_t shapes;
	shapes.push_back(
		std::make_unique<Triangle>(
			Point(28.0, 8.0), 
			Point(22.0, 16.0), 
			Point(30.0, 16.0)
			)
	);
	shapes.push_back(std::make_unique<Circle>(Point(10.0, 10.0), 5.0));
	shapes.push_back(std::make_unique<Triangle>());
	shapes.push_back(std::make_unique<Circle>(Point(5.0, 15.0), 4.0));


	print_shapes(shapes);

	Drawer field5(24ull, 88ull);
	const Point center(25.0, 12.0);

	
	//field5.draw_line(center, Point(12.0, 0.0));
	//field5.draw_line(center, Point(8.0, 0.0));
	//field5.draw_line(center, Point(0.0, 0.0));

	//field5.draw_line(center, Point(48.0, 12.0));
	// 
	// 
	//field5.draw_line(Point(120.0, 120.0), Point(100.0, 10000.0));
	//field5.draw_line(Point(120.0, 120.0), Point(10000.0, 100.0));
	
	//field5.draw_line(Point(-120.0, 120.0), Point(-100.0, 10000.0));
	//field5.draw_line(Point(-120.0, 120.0), Point(-10000.0, 100.0));

	//field5.draw_line(Point(-120.0, -120.0), Point(-100.0, -10000.0));
	//field5.draw_line(Point(-120.0, -120.0), Point(-10000.0, -100.0));

	//field5.draw_line(Point(120.0, -120.0), Point(100.0, -10000.0));
	//field5.draw_line(Point(120.0, -120.0), Point(10000.0, -100.0));

	//field5.draw_line(center, Point(9999.0, 9999.0));
	//field5.draw_line(center, Point(9999.0, 99999.0));
	//field5.draw_line(center, Point(9999.0, 999999.0));

	//field5.draw_line(Point(999.0, 2999.0), center);
	//field5.draw_line(Point(999.0, 29999.0), center);
	//field5.draw_line(Point(999.0, 299999.0), center);


	//field5.draw_line(center, Point(-9999.0, 9999.0));
	//field5.draw_line(center, Point(-9999.0, 99999.0));
	//field5.draw_line(center, Point(-9999.0, 999999.0));

	//field5.draw_line(Point(-999.0, 2999.0), center);
	//field5.draw_line(Point(-999.0, 29999.0), center);
	//field5.draw_line(Point(-999.0, 299999.0), center);



	//field5.draw_line(center, Point(9999.0, -9999.0));
	field5.draw_line(center, Point(9999.0, -99999.0));
	field5.draw_line(center, Point(2999.0, -999.0));

	//field5.draw_line(Point(999.0, -2999.0), center);
	field5.draw_line(Point(999.0, -29999.0), center);
	field5.draw_line(Point(9999.0, -299.0), center);


	field5.print_field();
}
