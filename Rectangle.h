#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdexcept>
#include <iostream>
#include "Shape.h"
#include "Point2D.h"

class Rectangle : public Shape {
protected:
	Point2D* vs;
public:
    	static const int N_VERTICES = 4;

    	// Constructores
    	Rectangle();
    	Rectangle(const std::string &color, Point2D* vertices);
    	Rectangle(const Rectangle &r);

    	// Destructor
    	~Rectangle();

    	// Métodos
    	Point2D get_vertex(int ind) const;
    	void set_vertices(Point2D* vertices);
    
    	// Operadores
    	Rectangle& operator=(const Rectangle &r);
    	Point2D operator[](int ind) const;
    	friend std::ostream& operator<<(std::ostream &out, const Rectangle &r);

    	// Implementación de métodos virtuales de Shape
    	double area() const override;
    	double perimeter() const override;
    	void translate(double incX, double incY) override;
    	void print() const;

private:
    	static bool check(Point2D* vertices);
};

#endif

