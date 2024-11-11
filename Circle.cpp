#include "Circle.h"

// Constructor por defecto
Circle::Circle() : Shape("red"), center(Point2D(0, 0)), radius(1) {}

// Constructor con parámetros
Circle::Circle(std::string color, Point2D center, double radius) : Shape(color), center(center), radius(radius) {}

// Métodos getter y setter
Point2D Circle::get_center() const {
    	return center;
}

void Circle::set_center(Point2D p) {
    	center = p;
}

double Circle::get_radius() const {
    	return radius;
}

void Circle::set_radius(double r) {
    	radius = r;
}

// Implementación de métodos virtuales
double Circle::area() const {
    	return M_PI * std::pow(radius, 2);
}

double Circle::perimeter() const {
    	return 2 * M_PI * radius;
}

void Circle::translate(double incX, double incY) {
    	center = Point2D(center.x + incX, center.y + incY);
}

void Circle::print() const {
    	std::cout << "[Circle: color = " << get_color() 
              << "; center = (" << center.x << "," << center.y << ")"
              << "; radius = " << radius << "]";
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream &out, const Circle &c) {
    	c.print();  // Llamar a print() para evitar duplicación de código
    	return out;
}

