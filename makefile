example: Example_8_3.o
	gcc -lGLU -lglut -lGL -lm -o Example_8_3 Example_8_3.o

example.o: Example_8_3.cpp
	gcc -c Example_8_3.cpp
	
clean:
	rm Example_8_3 Example_8_3.o
