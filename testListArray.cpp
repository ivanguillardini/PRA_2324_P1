#include <iostream>
#include "ListArray.h"  // Incluir la cabecera de ListArray

int main() {
   	 ListArray<int> list;  //crear una lista de enteros

    
    	list.insert(0, 15);  
    	list.insert(1, 45);  
    	list.insert(2, 6); 

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

