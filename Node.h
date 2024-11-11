#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>
class Node {
public:
    	T data;                //elementto almacenado en el nodo
    	Node<T>* next;         //puntero al siguiente nodo en la secuencia

    	Node(T data, Node<T>* next = nullptr) : data(data), next(next) {}

    	friend std::ostream& operator<<(std::ostream &out, const Node<T> &node) {
        	out << node.data;
        	return out;
    	}
};

#endif // NODE_H

