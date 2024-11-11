#include "Shape.h"

// Constructor por defecto
Shape::Shape() : color("red") {}

// Constructor con validación de color
Shape::Shape(const std::string &c) : color(c) {
    	validate_color(c);
}

// Validar color
void Shape::validate_color(const std::string &c) {
    	if (c != "red" && c != "green" && c != "blue") {
        	throw std::invalid_argument("Color inválido: " + c);
    	}
}

// Getter del color
std::string Shape::get_color() const {
    	return color;
}

// Setter con validación
void Shape::set_color(const std::string &c) {
    	validate_color(c);
    	color = c;
}

