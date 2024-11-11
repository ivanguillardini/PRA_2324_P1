#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <iostream>
#include <stdexcept>
#include "Node.h" 

template <typename T>
class ListLinked {
private:
    	Node<T>* first; //puntero al primer nodo de la lista
    	int n;          //número de elementos en la lista

public:
   	//constructor: inicializa lista vacía
    	ListLinked() : first(nullptr), n(0) {}

    	//destructor: libera todos los nodos de la lista
    	~ListLinked() {
        	Node<T>* current = first;
        	while (current != nullptr) {
            		Node<T>* aux = current->next; //apunta al siguiente nodo
            		delete current;               //libera el nodo actual
            		current = aux;                //avanza al siguiente nodo
        	}
    	}

    	T operator[](int pos) {
        	if (pos < 0 || pos >= n) {
            		throw std::out_of_range("Posición fuera del rango de la lista.");
        	}
        	Node<T>* current = first;
        	for (int i = 0; i < pos; ++i) {
            		current = current->next;
        	}
        return current->data;
    	}	

    	friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
        	Node<T>* current = list.first;
        	while (current != nullptr) {
            		out << current->data << " ";
        	   	current = current->next;
        	}
        	return out;
    	}	

    	void addFirst(T data) {
        	Node<T>* newNode = new Node<T>(data, first);
        	first = newNode;
        	n++;
    	}

    	int size() const {
        	return n;
    	}
};

#endif // LISTLINKED_H

