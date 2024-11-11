#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <stdexcept>
#include "Point2D.h"

class Shape {
protected:
    	std::string color;

    	void validate_color(const std::string &c);

public:
    	// Constructores
    	Shape();
    	Shape(const std::string &c);

    	// Métodos getter y setter
    	std::string get_color() const;
    	void set_color(const std::string &c);

    	// Métodos virtuales puros (abstractos)
    	virtual double area() const = 0;
    	virtual double perimeter() const = 0;
    	virtual void translate(double incX, double incY) = 0;
    	virtual void print() const = 0;

    	virtual ~Shape() = default;
};

#endif

