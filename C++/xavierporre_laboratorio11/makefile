CC = g++
flag= -fPIC
rutaPython =
rutaSwig = 
libreria = _libreria.pyd

$(lib):libreria_wrap.cxx libreria.o 
		$(cc) -fPIC -c libreria_wrap.cxx -o libreria_wrap.o -I$(rutaPython)/include
	$(cc) -shared libreria_wrap.o libreria.o -o $(lib) -L$(rutaPython) -lpython39

lib_wrap.cxx: libreria.h libreria.i
	$(rutaSwig)/swig -python -c++ libreria.i

libro.o: libreria.cpp libreria.h
	$(cc) $(flag) -c libreria.cpp -o libreria.o



clean:
	rm *.o *.out *.exe
