#include <iostream>
#include "Node.h"

int main() {
    	Node<char> n1('A');
    	Node<char> n2('B', &n1);
    	Node<char> n3('C', &n2);

    	Node<char>* current = &n3;
    	while (current != nullptr) {
        	std::cout << *current << " ";
        	current = current->next;
    	}
    	std::cout << std::endl;

    	return 0;
}

