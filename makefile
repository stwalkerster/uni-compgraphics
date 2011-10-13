project: main.o drawS.o drawV.o drawI.o Cube.o 3DCurve.o drawT.o drawW.o drawR.o drawX.o drawU.o
	gcc main.o drawS.o drawV.o drawI.o Cube.o 3DCurve.o drawT.o drawW.o drawR.o drawX.o drawU.o -o project -lGLU -lglut -lGL -lm

main.o: main.cpp
	gcc -c main.cpp

drawS.o: drawS.cpp
	gcc -c drawS.cpp

drawV.o: drawV.cpp
	gcc -c drawV.cpp

drawI.o: drawI.cpp
	gcc -c drawI.cpp

drawT.o: drawT.cpp
	gcc -c drawT.cpp

drawW.o: drawW.cpp
	gcc -c drawW.cpp

drawR.o: drawR.cpp
	gcc -c drawR.cpp

drawU.o: drawU.cpp
	gcc -c drawU.cpp

drawX.o: drawX.cpp
	gcc -c drawX.cpp

Cube.o: Cube.cpp
	gcc -c Cube.cpp

3DCurve.o: 3DCurve.cpp
	gcc -c 3DCurve.cpp

clean:
	rm -f main.o drawS.o drawV.o drawI.o drawT.o drawW.o drawR.o drawX.o drawU.o Cube.o 3DCurve.o project
