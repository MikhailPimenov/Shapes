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
	Drawer field(24, 88, '*', '.', 0.0, 88.0, 0.0, 24.0);

	//field.print_field();

	const Point p1(2.0, 3.0);
	const Point p2(15.0, 2.0);
	const Point p3(22.0, 15.0);
	const Point p4(10.0, 20.2);
	const Point p5(3.0, 55.2);
	const Point p11(2.0, 55.2);
	const Point p12(6.0, 55.2);
	const Point p13(10.0, 55.2);
	const Point p14(14.0, 55.2);
	const Point p15(18.0, 55.2);
	const Point p16(22.0, 55.2);

	//const Point px1(3.0, 3.0);
	//const Point px2(9.0, 9.0);

	field.draw_line(p1,  p2, '*');
	field.draw_line(p2,  p3, '*');
	field.draw_line(p3,  p4, '*');
	field.draw_line(p4,  p5, '*');
	field.draw_line(p5,  p1, '*');
	//field.draw_line(p12, p1, '6');
	//field.draw_line(p13, p1, '7');
	//field.draw_line(p14, p1, '8');
	//field.draw_line(p15, p1, '9');
	//field.draw_line(p16, p1, '0');
	//field.draw_line(px1, px2, 'x');
	field.print_field();
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
