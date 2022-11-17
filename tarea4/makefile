CC = g++
rutaPython = /usr/share/file/magic/python
rutaSwig = /Users/xavierporre/swig/
EXE = oop
COMP = g++
FLAGS = 
BLOQUES = tarea4.o
LIBRERIA = tarea4.so
WRAP = tarea4_wrap.cxx

$(EXE): tarea4.o
	$(COMP) $(FLAGS) tarea4.o -o $(EXE) -Wl
	
# Regla comodín para compilar librerías

# Se agrega el -fPIC

# Regla para crear librería compartida (.so)
$(lib):persona_wrap.cxx persona.o
	sudo $(cc) -fPIC -c persona_wrap.cxx -o persona_wrap.o -I$(rutaPython)/include
	$(cc) -shared persona_wrap.o persona.o -o $(lib) -L$(rutaPython) -lpython39

tarea4.o: tarea4.h tarea4.c++
	$(CC) -fPIC -c tarea4.c++ -o tarea4.o

# Regla para wraper
wrap: tarea4.i tarea4.h
	swig -python -c++ tarea4.i

# Regla para crear librería desde el wraper
tarea4.so: $(WRAP) $(BLOQUES)
	$(COMP) $(FLAGS) -fPIC -c $(WRAP) -o lib_wrap.o -I$(rutaPython)
	$(COMP) -shared lib_wrap.o tarea4.o  -o tarea4.so
	
clean:
	rm -f *.o
	rm -f *.so
	rm -f $(EXE)
	
run: $(EXE)
	./$(EXE)	
	
all: clean $(EXE)