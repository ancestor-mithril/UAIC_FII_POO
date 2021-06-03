#pragma once
namespace third_lab
{
	class Math
	{
	public:
		static int Add(int, int);
		static int Add(int, int, int);
		static int Add(double, double);
		static int Add(double, double, double);
		static int Mul(int, int);
		static int Mul(int, int, int);
		static int Mul(double, double);
		static int Mul(double, double, double);
		static int Add(int count, ...); // sums up a list of integers
		static char* Add(const char*, const char*);
	};

	class Canvas
	{
		// add private data members
		char** _matrix;
		int _width;
		int _height;
	public:
		Canvas(int width, int height);
		void DrawCircle(int x, int y, int ray, char ch);
		void FillCircle(int x, int y, int ray, char ch);
		void DrawRect(int left, int top, int right, int bottom, char ch);
		void FillRect(int left, int top, int right, int bottom, char ch);
		void SetPoint(int x, int y, char ch);
		void DrawLine(int x1, int y1, int x2, int y2, char ch);
		void Print(); // shows what was printed
		void Clear(); // clears the canvas
	};
}

