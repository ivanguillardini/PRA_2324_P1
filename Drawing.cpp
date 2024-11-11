#include "Drawing.h"
#include "Circle.h"   // Para verificar las figuras Circle
#include "Square.h"   // Para verificar las figuras Square
#include "Rectangle.h"// Para verificar las figuras Rectangle
#include "ListArray.h"  // Incluir la cabecera correcta de ListArray
// Constructor: asigna la implementación de lista (se elige std::vector por simplicidad)
Drawing::Drawing() {
    	shapes = new ListArray<Shape*>();  // Usar ListArray como ejemplo
}

// Destructor: libera la memoria de la lista de figuras
Drawing::~Drawing() {
    	delete shapes;  // Liberar memoria de la lista
}

// Añadir una figura al frente
void Drawing::add_front(Shape* shape) {
    	shapes->add_front(shape);
}

// Añadir una figura al fondo
void Drawing::add_back(Shape* shape) {
    	shapes->add_back(shape);
}

// Imprimir todas las figuras del dibujo
void Drawing::print_all() const {
    	for (int i = 0; i < shapes->size(); ++i) {
        	shapes->get(i)->print();  // Llamada al método print() de cada figura
    	}
}

// Obtener el área total de todos los círculos
double Drawing::get_area_all_circles() const {
    	double total_area = 0;
    	for (int i = 0; i < shapes->size(); ++i) {
        	if (dynamic_cast<Circle*>(shapes->get(i))) {  // Verifica si la figura es un círculo
            	total_area += shapes->get(i)->get_area();
        	}
    	}
    	return total_area;
}

// Mover todos los cuadrados en el dibujo
void Drawing::move_squares(double incX, double incY) {
    	for (int i = 0; i < shapes->size(); ++i) {
        	if (dynamic_cast<Square*>(shapes->get(i))) {  // Verifica si la figura es un cuadrado
            	dynamic_cast<Square*>(shapes->get(i))->translate(incX, incY);
        	}
    	}
}

