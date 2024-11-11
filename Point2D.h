#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>
#include <cmath> // para sqrt y pow

class Point2D {
public:
    	// Atributos públicos
    	double x;
    	double y;

    	// Constructor con valores predeterminados
    	Point2D(double x = 0, double y = 0);

    	// Método estático para calcular la distancia entre dos puntos
    	static double distance(const Point2D &a, const Point2D &b);

    	// Sobrecarga de operadores == y != para comparar puntos
    	friend bool operator==(const Point2D &a, const Point2D &b);
    	friend bool operator!=(const Point2D &a, const Point2D &b);

    	// Sobrecarga del operador << para imprimir el punto
    	friend std::ostream& operator<<(std::ostream &out, const Point2D &p);
};

#endif



