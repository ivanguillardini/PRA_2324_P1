#ifndef LIST_H
#define LIST_H

#include <stdexcept>  // Para std::out_of_range

// Definición de la clase abstracta pura List<T>
template <typename T>
class List {
public:
    	// Método para insertar un elemento en una posición específica
    	virtual void insert(int pos, T e) = 0;

    	// Método para añadir un elemento al final de la lista
    	virtual void append(T e) = 0;

    	// Método para añadir un elemento al principio de la lista
    	virtual void prepend(T e) = 0;

    	// Método para eliminar y devolver el elemento en una posición específica
    	virtual T remove(int pos) = 0;

    	// Método para obtener el elemento en una posición específica
    	virtual T get(int pos) const = 0;

    	// Método para buscar la primera ocurrencia de un elemento
    	virtual int search(T e) const = 0;

    	// Método para verificar si la lista está vacía
    	virtual bool empty() const = 0;

    	// Método para obtener el tamaño de la lista
	virtual int size() const = 0;

    	// Destructor virtual para asegurar la correcta destrucción de objetos derivados		
	virtual ~List() {}
};

#endif // LIST_H

