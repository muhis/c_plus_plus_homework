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
		cout << shapeType;
		if (shapeType == "") {
			throw invalid_argument("received no shape type");
		}
		if (shapeType == "Rectangle") {
			return Rectangle();
		}
		else if (shapeType == "Square") {
			return Square();
		}
		else if (shapeType == "Circle") {
			return Circle();
		}
	}
};
Shape shapeFactoryFunction(string shapeType) {
	/* Just to prove there is a world outside of Java, here is a
	function that works as good as the class if not better. */
	if (shapeType == "") {
		throw invalid_argument("received no shape type");
	}
	if (shapeType == "Rectangle") {
		return Rectangle();
	}
	else if (shapeType == "Square") {
		return Square();
	}
	else if (shapeType == "Circle") {
		return Circle();
	}
}
int main()
{
	ShapeFactory shapeFactory = ShapeFactory();

	Shape shape1 = shapeFactory.getShape("Rectangle");
	shape1.draw();
	Shape shape2 = shapeFactoryFunction("Circle");
	_fgetchar();
}

