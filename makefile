example: Example_8_3.o cube.o 3DCurve.o
	gcc -lGLU -lglut -lGL -lm -o Example_8_3 Example_8_3.o cube.o 3DCurve.o

example.o: Example_8_3.cpp
	gcc -c Example_8_3.cpp
	
cube.o: cube.cpp
	gcc -c cube.cpp

3DCurve.o: 3DCurve.cpp
	gcc -c 3DCurve.cpp

clean:
	rm Example_8_3 Example_8_3.o cube.o 3DCurve.o
