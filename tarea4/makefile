CC = g++
rutaPython = /usr/share/file/magic/python
rutaSwig = 
libreria = tarea4.pyd

$(lib):tarea4_wrap.cxx tarea4.o
	$(cc) -fPIC -c tarea4_wrap.cxx -o tarea4_wrap.o -I$(rutaPython)/include 
	$(cc) -shared tarea4_wrap.o tarea4.o -o $(lib) -L$(rutaPython) -lpython39

lib_wrap.cxx: tarea4.h tarea4.i
	$(rutaSwig)/swig -python -c++ tarea4.i

persona.o:tarea4.h tarea4.cpp
	$(CC) -fPIC -c tarea4.cpp -o tarea4.o