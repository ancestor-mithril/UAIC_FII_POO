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
		void circleVerification(int x, int y, int ray) const;
		void rectangleVerification(int left, int right, int top, int bottom) const;
	public:
		Canvas(int width, int height);
		void DrawCircle(int x, int y, int ray, char ch) const;
		void FillCircle(int x, int y, int ray, char ch) const;
		void DrawRect(int left, int top, int right, int bottom, char ch);
		void FillRect(int left, int top, int right, int bottom, char ch) const;
		void SetPoint(int x, int y, char ch) const;
		void DrawLine(int x1, int y1, int x2, int y2, char ch) const;
		void Print() const; // shows what was printed
		void Clear() const; // clears the canvas
	};
}

