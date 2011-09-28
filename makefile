example: Example_8_3.o cube.o
	gcc -lGLU -lglut -lGL -lm -o Example_8_3 Example_8_3.o cube.o

example.o: Example_8_3.cpp
	gcc -c Example_8_3.cpp
	
cube.o: cube.cpp
	gcc -c cube.cpp

clean:
	rm Example_8_3 Example_8_3.o cube.o	

test:
	gcc -lGLU -lglut -lGL -lm -o Example_8_3 Example_8_3.cpp cube.cpp
