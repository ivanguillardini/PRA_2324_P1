#include "Point2D.h"

// Constructor con valores por defecto
Point2D::Point2D(double x, double y) : x(x), y(y) {}

// Método estático para calcular la distancia euclidiana entre dos puntos
double Point2D::distance(const Point2D &a, const Point2D &b) {
    	return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

// Sobrecarga del operador == para comparar dos puntos
bool operator==(const Point2D &a, const Point2D &b) {
    	return (a.x == b.x) && (a.y == b.y);
}

// Sobrecarga del operador != para comparar dos puntos
bool operator!=(const Point2D &a, const Point2D &b) {
    	return !(a == b);
}

// Sobrecarga del operador << para imprimir un punto
std::ostream& operator<<(std::ostream &out, const Point2D &p) {
    	out << "(" << p.x << ", " << p.y << ")";
    	return out;
}

