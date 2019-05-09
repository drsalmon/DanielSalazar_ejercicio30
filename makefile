all: ejemplo.dat solucion.gif 

solucion.gif: ejemplo.dat grafica.py
	python grafica.py

%.dat : a.out
	./a.out 

a.out: DanielSalazar_ejercicio30.cpp
	g++ DanielSalazar_ejercicio30.cpp

clean:
	rm -rf a.out ejemplo.dat plot.png *~