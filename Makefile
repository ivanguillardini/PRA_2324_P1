all: bin/testNode bin/testListLinked bin/testListArray

# Crear el directorio bin si no existe
bin:
	mkdir -p bin
# Compilar el programa de prueba para Node<T>
bin/testNode: testNode.cpp Node.h | bin
	g++ -o bin/testNode testNode.cpp

# Compilar el programa de prueba para ListLinked<T>
bin/testListLinked: testListLinked.cpp ListLinked.h Node.h | bin
	g++ -o bin/testListLinked testListLinked.cpp

bin/testListArray: testListArray.cpp ListArray.h List.h | bin
	g++ -o bin/testListArray testListArray.cpp
# Limpiar archivos compilados
clean:
	rm -rf bin/*

# Ejecutar el test de Node<T>
run-testNode: bin/testNode
	./bin/testNode

# Ejecutar el test de ListLinked<T>
run-testListLinked: bin/testListLinked
	./bin/testListLinked

run-testListArray: bin/testListArray
	./bin/testListArray

