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

Point2D.o: Point2D.h Point2D.cpp
	g++ -c Point2D.cpp

Shape.o: Shape.h Shape.cpp
	g++ -c Shape.cpp

# Actualizar la regla de compilación para bin/testPoint2D para incluir Shape.o
bin/testPoint2D: testPoint2D.cpp Point2D.o Shape.o | bin
	g++ -o bin/testPoint2D testPoint2D.cpp Point2D.o Shape.o
# Regla de compilación para Circle.o
Circle.o: Circle.h Circle.cpp Shape.h Point2D.h	
	g++ -c Circle.cpp
Rectangle.o: Rectangle.cpp Rectangle.h Shape.h
	g++ -c Rectangle.cpp -o Rectangle.o
# Regla de compilación para el ejecutable bin/testCircle
bin/testCircle: testCircle.cpp Circle.o Shape.o Point2D.o | bin
	g++ -c testCircle.cpp
	g++ -o bin/testCircle testCircle.o Circle.o Shape.o Point2D.o
bin/testRectangle: testRectangle.cpp Rectangle.o Shape.o Point2D.o | bin
	g++ -c testRectangle.cpp
	g++ -o bin/testRectangle testRectangle.o Rectangle.o Shape.o Point2D.o
# Agrega la regla para compilar Square.cpp
Square.o: Square.cpp Square.h Rectangle.o
	g++ -c Square.cpp -o Square.o

# Regla para generar el ejecutable testSquare
bin/testSquare: testSquare.cpp Square.o Rectangle.o Shape.o | bin
	g++ -o bin/testSquare testSquare.cpp Square.o Rectangle.o Shape.o

bin/testDrawing: testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o | bin
	g++ -o bin/testDrawing testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o

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

