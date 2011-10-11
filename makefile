project: main.o drawS.o drawV.o drawI.o Cube.o 3DCurve.o drawT.o
	gcc main.o drawS.o drawV.o drawI.o Cube.o 3DCurve.o drawT.o -o project -lGLU -lglut -lGL -lm

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

Cube.o: Cube.cpp
	gcc -c Cube.cpp

3DCurve.o: 3DCurve.cpp
	gcc -c 3DCurve.cpp

clean:
	rm main.o drawS.o drawV.o drawI.o Cube.o 3DCurve.o project
