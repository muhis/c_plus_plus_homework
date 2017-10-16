//#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Shape {
public:
  virtual void draw() = 0;
};

class Rectangle : public Shape {
public:
  void draw() {
    cout << "I am rectangle" << endl;
  }
};

class Square : public Shape {
public:
  void draw() {
    cout << "I am a square!" << endl;
  }
};

class Circle : public Shape {
public:
  void draw() {
    cout << "I am a circle" << endl;
  }
};

class ShapeFactory {
public:
  Shape* getShape(string shapeType) {
    if (shapeType.compare("Rectangle") == 0) {
	return new Rectangle();
    }
    else if (shapeType.compare("Square") == 0) {
	return new Square();
    }
    else if (shapeType.compare("Circle") == 0) {
	return new Circle();
    }
    else {
        throw invalid_argument("received no shape type");
    }
  }
};

int main() {
  ShapeFactory shapeFactory;
  shapeFactory.getShape("Rectangle")->draw();
  shapeFactory.getShape("Square")->draw();
  shapeFactory.getShape("Circle")->draw();
  shapeFactory.getShape("BlahBlah")->draw();
  
  getchar();
}
