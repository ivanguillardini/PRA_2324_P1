#include "Square.h"
#include "Point2D.h"  // Asegúrate de incluir la clase Point2D

// Constructor por defecto
Square::Square() : Rectangle("red", new Point2D[4]{
    	Point2D(-1, 1), Point2D(1, 1), Point2D(1, -1), Point2D(-1, -1)
}) {}

// Constructor con parámetros
Square::Square(std::string color, Point2D* vertices)
    : Rectangle(color, vertices) {
    	if (!check(vertices)) {
        	throw std::invalid_argument("Los vértices no conforman un cuadrado válido");
    	}
}

// Sobrescribe el método set_vertices para verificar que los vértices conformen un cuadrado
void Square::set_vertices(Point2D* vertices) {
    	if (!check(vertices)) {
        	throw std::invalid_argument("Los vértices no conforman un cuadrado válido");
    	}
    	Rectangle::set_vertices(vertices);  // Llama a la implementación de Rectangle
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& out, const Square& square) {
    	square.print();  // Aprovechamos la implementación heredada de print()
    	return out;
}

// Método estático para verificar si los vértices conforman un cuadrado
bool Square::check(Point2D* vertices) {
    	double dist01 = Point2D::distance(vertices[0], vertices[1]);
    	double dist12 = Point2D::distance(vertices[1], vertices[2]);
    	double dist23 = Point2D::distance(vertices[2], vertices[3]);
    	double dist30 = Point2D::distance(vertices[3], vertices[0]);

    	// Verifica si todas las distancias son iguales
    	return dist01 == dist12 && dist12 == dist23 && dist23 == dist30;
}

