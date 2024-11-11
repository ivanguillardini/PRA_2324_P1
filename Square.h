#ifndef SQUARE_H
#define SQUARE_H

#include <stdexcept>
#include <iostream>
#include "Rectangle.h"

class Square : public Rectangle {
public:
    	// Constructor por defecto
    	Square();

    	// Constructor con parámetros
    	Square(std::string color, Point2D* vertices);

    	// Método para sobrescribir los vértices
    	virtual void set_vertices(Point2D* vertices);

    	// Sobrecarga del operador <<
    	friend std::ostream& operator<<(std::ostream& out, const Square& square);

private:
    	// Método estático para verificar si los vértices conforman un cuadrado válido
    	static bool check(Point2D* vertices);
};

#endif

