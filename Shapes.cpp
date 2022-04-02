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

#include "Drawer.h"

int main() {
	Drawer field(24, 88, '*', '.', 0.0, 24.0, 0.0, 88.0);

	const Point p1(2.0, 2.0);
	const Point p2(15.0, 2.0);
	const Point p3(22.0, 15.0);
	const Point p4(10.0, 20.2);
	const Point p5(3.0, 55.2);
	const Point p6(1.0, 15.0);

	field.draw_line(p1, p2, '1');
	field.draw_line(p2, p3, '2');
	field.draw_line(p3, p4, '3');
	field.draw_line(p4, p5, '4');
	field.draw_line(p5, p6, '5');
	field.draw_line(p6, p1, '6');
	field.print_field();
	std::cout << '\n';



	Drawer field2(24, 88, '*', '.', 0.0, 24.0, 0.0, 88.0);
	const Point p21(5.0, 5.0);
	const Point p22(20.0, 5.0);
	const Point p23(20.0, 20.0);
	const Point p24(5.0, 20.0);

	field2.draw_line(p21, p22, '1');
	field2.draw_line(p22, p23, '2');
	field2.draw_line(p23, p24, '3');
	field2.draw_line(p24, p21, '4');
	field2.print_field();
	std::cout << '\n';



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
