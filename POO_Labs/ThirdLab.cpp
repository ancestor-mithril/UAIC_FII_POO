#include "ThirdLab.h"

#include <cstdarg>
#include <cstring>
#include <iostream>

#include "CustomException.h"

int third_lab::Math::Add(int a, int b)
{
	return a + b;
}

int third_lab::Math::Add(int a, int b, int c)
{
	return a + b + c;
}

int third_lab::Math::Add(double a, double b)
{
	return static_cast<int>(a + b);
}

int third_lab::Math::Add(double a, double b, double c)
{
	return static_cast<int>(a + b + c);
}

int third_lab::Math::Mul(int a, int b)
{
	return a * b;
}

int third_lab::Math::Mul(int a, int b, int c)
{
	return a * b * c;
}

int third_lab::Math::Mul(double a, double b)
{
	return static_cast<int>(a * b);
}

int third_lab::Math::Mul(double a, double b, double c)
{
	return static_cast<int>(a * b * c);
}

int third_lab::Math::Add(int count, ...)
{
	double sum = 0.0;
	va_list elements;
	va_start(elements, count);
	for (int i = 0; i < count; ++i)
	{
		sum += va_arg(elements, double);
	}
	va_end(elements);
	return static_cast<int>(sum);
}

char* third_lab::Math::Add(const char* a, const char* b)
{
	if (a == nullptr || b == nullptr)
	{
		return nullptr;
	}
	const int lenA = strlen(a);
	const int lenB = strlen(b);
	const auto lenResult = lenA + lenB + 2;
	const auto result = new char[lenResult];
	strcpy_s(result, lenResult * sizeof(char), a);
	strcat_s(result, lenResult * sizeof(char), b);
	return result;
}

third_lab::Canvas::Canvas(int width, int height): _width(width), _height(height)
{
	_matrix = new char* [height];
	for (int line = 0; line < height; ++line)
	{
		_matrix[line] = new char[width];
		for (int col = 0; col < width; ++col)
		{
			SetPoint(line, col, ' ');
		}
	}
}

void third_lab::Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	if (x - ray < 0 || x + ray >= _height || y - ray < 0 || y + ray >= _width)
	{
		throw utils::CustomException("Circle exits canvas");
	}
	//TODO: find algorithm to draw the circle
	std::cout << "Draw Circle does nothing" << std::endl;
}

void third_lab::Canvas::FillCircle(int x, int y, int ray, char ch)
{

	if (x - ray < 0 || x + ray >= _height || y - ray < 0 || y + ray >= _width)
	{
		throw utils::CustomException("Circle exits canvas");
	}
	//TODO: find algorithm to fill the circle
	std::cout << "Fill Circle does nothing" << std::endl;
}

void third_lab::Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	if (left < 0 || left >= right || right >= _width || top < 0 || top >= bottom || bottom >= _height)
	{
		throw utils::CustomException("Wrong rectangle coordinates");
	}
	for (int line = top; line < bottom; ++line) 
	{
		_matrix[line][right] = _matrix[line][left] = ch;
		SetPoint(line, right, ch);
		SetPoint(line, left, ch);
	}
	for (int col = left; col < right; ++col)
	{
		SetPoint(top, col, ch);
		SetPoint(bottom, col, ch);
	}
}

void third_lab::Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	if (left < 0 || left >= right || right >= _width || top < 0 || top >= bottom || bottom >= _height)
	{
		throw utils::CustomException("Wrong rectangle coordinates");
	}
	for (int line = top; line < bottom; ++line)
	{
		for (int col = left; col < right; ++col)
		{
			SetPoint(line, col, ch);
		}
	}
}

void third_lab::Canvas::SetPoint(int x, int y, char ch)
{
	if (x < 0 || x > _height || y < 0 || y > _width)
	{
		throw utils::CustomException("Point not in canvas");
	}
	_matrix[x][y] = ch;
}

void third_lab::Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	if (x1 < 0 || x1 > _height || y1 < 0 || y1 > _width || x2 < 0 || x2 > _height || y2 < 0 || y2 > _width)
	{
		throw utils::CustomException("Line exits canvas");
	}
	const auto dx = abs(x1 - x2);
	const auto sx = x1 < x2 ? 1 : -1;
	const auto dy = -abs(y2 - y1);
	const auto sy = y1 < y2 ? 1 : -1;
	auto err = dx + dy;
	while (true)
	{
		SetPoint(x1, y1, ch);
		if (x1 == x2 && y1 == y2)
		{
			break;
		}
		const int e2 = 2 * err;
		if (e2 > dy)
		{
			err += dy;
			x1 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}

void third_lab::Canvas::Print()
{
	for (int line = 0; line < _height; ++line)
	{
		for (int col = 0; col < _width; ++col)
		{
			std::cout << _matrix[line][col];
		}
		std::cout << std::endl;
	}
}

void third_lab::Canvas::Clear()
{
	for (int line = 0; line < _height; ++line)
	{
		for (int col = 0; col < _width; ++col)
		{
			SetPoint(line, col, ' ');
		}
	}
}


