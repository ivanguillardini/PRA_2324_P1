#ifndef DRAWING_H
#define DRAWING_H

#include <iostream>
#include <stdexcept>
#include "Shape.h"
#include "List.h"  // Incluir la interfaz List y sus implementaciones (ListArray o ListLinked)

class Drawing {
private:
    	List<Shape*>* shapes;  // Puntero a la lista de figuras (polimorfismo)

public:
    	// Constructor por defecto
    	Drawing();

    	// Destructor
    	~Drawing();

    	// Añadir una figura al frente
    	void add_front(Shape* shape);

    	// Añadir una figura al fondo
    	void add_back(Shape* shape);

    	// Imprimir información de todas las figuras
    	void print_all() const;

    	// Obtener el área total de todos los círculos
    	double get_area_all_circles() const;

    	// Mover todos los cuadrados por un incremento en X e Y
    	void move_squares(double incX, double incY);
};

#endif // DRAWING_H

