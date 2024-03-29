project: main.o drawS.o drawV.o Cube.o 3DCurve.o drawT.o drawW.o drawX.o drawU.o Ucube.o test.o Ear.o wing.o drawNose.o drawEyes.o drawOval.o drawHead.o drawBody.o drawFoot.o
	g++ main.o drawS.o drawV.o Cube.o 3DCurve.o drawT.o drawW.o drawX.o drawU.o Ucube.o test.o Ear.o wing.o drawNose.o drawEyes.o drawOval.o drawHead.o drawBody.o drawFoot.o -o project -lGLU -lglut -lGL -lm

clean: tidy
	rm -f project

rebuild: clean project

all: clean run

run: project
	./project

tidy:
	rm -f *.o

help:
	echo "Possible targets are: project clean rebuild all run tidy help"
