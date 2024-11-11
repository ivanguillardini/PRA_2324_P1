#include "Rectangle.h"
#include <cmath>
#include <stdexcept>

// Constructor por defecto
Rectangle::Rectangle() : Shape(), vs(new Point2D[N_VERTICES]{
    	Point2D(-1, 0.5), Point2D(1, 0.5), Point2D(1, -0.5), Point2D(-1, -0.5)}) {}

// Constructor con color y vértices
Rectangle::Rectangle(const std::string &color, Point2D* vertices) : Shape(color), vs(new Point2D[N_VERTICES]) {
    	if (!check(vertices)) throw std::invalid_argument("Los vértices no forman un rectángulo.");
    	for (int i = 0; i < N_VERTICES; i++) {
        	vs[i] = vertices[i];
    	}
}

// Constructor de copia
Rectangle::Rectangle(const Rectangle &r) : Shape(r.color), vs(new Point2D[N_VERTICES]) {
    	for (int i = 0; i < N_VERTICES; i++) {
        	vs[i] = r.vs[i];
    	}
}

// Destructor
Rectangle::~Rectangle() {
    	delete[] vs;
}

// Validar si los vértices forman un rectángulo
bool Rectangle::check(Point2D* vertices) {
    	double d01 = Point2D::distance(vertices[0], vertices[1]);
    	double d12 = Point2D::distance(vertices[1], vertices[2]);
    	double d23 = Point2D::distance(vertices[2], vertices[3]);
    	double d30 = Point2D::distance(vertices[3], vertices[0]);
    	return (d01 == d23) && (d12 == d30);
}

// Obtener un vértice específico
Point2D Rectangle::get_vertex(int ind) const {
    	if (ind < 0 || ind >= N_VERTICES) throw std::out_of_range("Índice fuera de rango.");
    	return vs[ind];
}

// Modificar los vértices
void Rectangle::set_vertices(Point2D* vertices) {
    	if (!check(vertices)) throw std::invalid_argument("Los vértices no forman un rectángulo.");
    	for (int i = 0; i < N_VERTICES; i++) {
        	vs[i] = vertices[i];
    	}
}

// Sobrecarga de operador []
Point2D Rectangle::operator[](int ind) const {
    	return get_vertex(ind);
}

// Sobrecarga de operador de asignación
Rectangle& Rectangle::operator=(const Rectangle &r) {
    	if (this != &r) {
        	color = r.color;
        	for (int i = 0; i < N_VERTICES; i++) {
            		vs[i] = r.vs[i];
        	}
    	}
    	return *this;
}

// Sobrecarga de operador <<
std::ostream& operator<<(std::ostream &out, const Rectangle &r) {
    	out << "[Rectangle: color = " << r.color;
    	for (int i = 0; i < Rectangle::N_VERTICES; i++) {
        	out << "; vertex " << i << " = (" << r.vs[i].get_x() << ", " << r.vs[i].get_y() << ")";
    	}
    	out << "]";
    	return out;
}

// Métodos virtuales de Shape
double Rectangle::area() const {
    	double length = Point2D::distance(vs[0], vs[1]);
    	double width = Point2D::distance(vs[1], vs[2]);
    	return length * width;
}

double Rectangle::perimeter() const {
    	double length = Point2D::distance(vs[0], vs[1]);
    	double width = Point2D::distance(vs[1], vs[2]);
    	return 2 * (length + width);
}

void Rectangle::translate(double incX, double incY) {
    	for (int i = 0; i < N_VERTICES; i++) {
        	vs[i].translate(incX, incY);
    	}
}

void Rectangle::print() const {
    	std::cout << *this << std::endl;
}

