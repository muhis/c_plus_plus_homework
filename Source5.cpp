#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Shape {
public:
	virtual void draw() {};
};

class Rectangle :public Shape {
public:
	void draw() {
		cout << "I am rectangle";
	}
};
class Square :public Shape {
public:
	void draw() {
		cout << "I am a square!";
	}
};
class Circle :public Shape {
public:
	void draw() {
		cout << "I am a circle";
	}
};
class ShapeFactory {
public:
	Shape getShape(string shapeType) {
		if (shapeType == "") {
			throw invalid_argument("received no shape type");
		}
		if (shapeType.compare("Rectangle") == 0) {
			return Rectangle();
		}
		else if (shapeType.compare("Square") == 0) {
			return Square();
		}
		else if (shapeType.compare("Circle") == 0) {
			return Circle();
		}
	}
};
int main()
{
	ShapeFactory shapeFactory = ShapeFactory();

	Shape shape1 = shapeFactory.getShape("Rectangle");
	shape1.draw();
	getchar();
}
