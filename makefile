project: main.o drawS.o drawV.o drawI.o Cube.o 3DCurve.o drawT.o drawW.o drawR.o drawX.o drawU.o
	gcc main.o drawS.o drawV.o drawI.o Cube.o 3DCurve.o drawT.o drawW.o drawR.o drawX.o drawU.o -o project -lGLU -lglut -lGL -lm

clean:
	rm -f main.o drawS.o drawV.o drawI.o drawT.o drawW.o drawR.o drawX.o drawU.o Cube.o 3DCurve.o project
