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
	field.draw_line(p3, p2, '2');
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



	Drawer field3(24, 88, '*', '.', 0.0, 24.0, 0.0, 88.0);
	const Point center3(44.0, 12.0);
	const Point p301( 0.0, 0.0);
	const Point p302(11.0, 0.0);
	const Point p303(22.0, 0.0);
	const Point p304(33.0, 0.0);
	const Point p305(44.0, 0.0);
	const Point p306(55.0, 0.0);
	const Point p307(66.0, 0.0);
	const Point p308(77.0, 0.0);
	const Point p309(88.0, 0.0);

	const Point p310(88.0,  4.0);
	const Point p311(88.0,  8.0);
	const Point p312(88.0, 12.0);
	const Point p313(88.0, 16.0);
	const Point p314(88.0, 20.0);
	const Point p315(88.0, 24.0);

	const Point p316(88.0, 24.0);
	const Point p317(77.0, 24.0);
	const Point p318(66.0, 24.0);
	const Point p319(55.0, 24.0);
	const Point p320(44.0, 24.0);
	const Point p321(33.0, 24.0);
	const Point p322(22.0, 24.0);
	const Point p323(11.0, 24.0);
	const Point p324( 0.0, 24.0);

	const Point p325(0.0, 24.0);
	const Point p326(0.0, 20.0);
	const Point p327(0.0, 16.0);
	const Point p328(0.0, 12.0);
	const Point p329(0.0,  8.0);
	const Point p330(0.0,  4.0);


	field3.draw_line(center3, p301, 'a');
	field3.draw_line(center3, p302, 'b');
	field3.draw_line(center3, p303, 'c');
	field3.draw_line(center3, p304, 'd');
	field3.draw_line(center3, p305, 'e');
	field3.draw_line(center3, p306, 'f');
	field3.draw_line(center3, p307, 'g');
	field3.draw_line(center3, p308, 'h');
	field3.draw_line(center3, p309, 'i');
	field3.draw_line(center3, p310, 'j');
	field3.draw_line(center3, p311, 'k');
	field3.draw_line(center3, p312, 'l');
	field3.draw_line(center3, p313, 'm');
	field3.draw_line(center3, p314, 'n');
	field3.draw_line(center3, p315, 'o');

	field3.draw_line(center3, p316, 'p');
	field3.draw_line(center3, p317, 'q');
	field3.draw_line(center3, p318, 'r');
	field3.draw_line(center3, p319, 's');
	field3.draw_line(center3, p320, 't');
	field3.draw_line(center3, p321, 'u');
	field3.draw_line(center3, p322, 'v');
	field3.draw_line(center3, p323, 'x');
	field3.draw_line(center3, p324, 'y');

	field3.draw_line(center3, p325, 'z');
	field3.draw_line(center3, p326, '1');
	field3.draw_line(center3, p327, '2');
	field3.draw_line(center3, p328, '3');
	field3.draw_line(center3, p329, '4');
	field3.draw_line(center3, p330, '5');

	field3.print_field();
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
