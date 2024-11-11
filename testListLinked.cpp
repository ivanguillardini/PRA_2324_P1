#include <iostream>
#include "ListLinked.h"

int main() {
    	ListLinked<int> list;
    
    	list.addFirst(12);
    	list.addFirst(23);
    	list.addFirst(36);

    	std::cout << "Contenido de la lista: " << list << std::endl;

   	 try {
        	std::cout << "Elemento en posición 0: " << list[0] << std::endl;
        	std::cout << "Elemento en posición 1: " << list[1] << std::endl;
        	std::cout << "Elemento en posición 2: " << list[2] << std::endl;
    	} catch (const std::out_of_range& e) {
        	std::cerr << e.what() << std::endl;
    	}

    	return 0;
}

