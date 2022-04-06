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
#include "Rectangle.h"

using Shapes_t = std::vector<std::unique_ptr<IShape>>;

void print_shapes(const Shapes_t& shapes) {
	Drawer field(24ull, 88ull);
	for (const auto& shape : shapes) {
		shape->print_info();
		field.draw(*shape);
	}
	field.print_field();
}


int main() {

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
	shapes.push_back(std::make_unique<Circle>(Point(20.0, 5.0), 3.0));
	shapes.push_back(std::make_unique<Rectangle>());

	shapes.push_back(
		std::make_unique<Triangle>(
			Point(15.0, 10.0),
			Point(30.0, 10.0),
			Point(20.0, 22.0)
			)
	);

	print_shapes(shapes);
}
