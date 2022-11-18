CC = g++
rutaPython = /Users/xavierporre/opt/anaconda3/bin/python
rutaSwig = /Users/xavierporre/swig/
EXE = oop
COMP = g++
FLAGS = 
BLOQUES = tarea4.o
LIBRERIA = tarea4.so
WRAP = tarea4_wrap.cxx

$(EXE): tarea4.o
	$(COMP) tarea4.o -o $(EXE) 
	
# Regla comodín para compilar librerías

# Se agrega el -fPIC
%.o: %.cpp %.h
	$(COMP) $(FLAGS) -fPIC -o  $@ $< -c

# Regla para crear librería compartida (.so)

lib: $(BLOQUES)
	$(COMP) -shared $^ -o $(LIBRERIA)
	sudo mv $(LIBRERIA) /usr/lib

tarea4.o: tarea4.h tarea4.c++
	$(CC) -Wall -fPIC -c tarea4.c++ -o tarea4.o

# Regla para wraper
wrap: tarea4.i tarea4.h
	swig -c++ -python  tarea4.i

# Regla para crear librería desde el wraper
tarea4.so: $(WRAP) $(BLOQUES)
	$(COMP) $(FLAGS) -fPIC -c $(WRAP) -o tarea4.o -I$(rutaPython)
	$(COMP) -shared tarea4.o  -o tarea4.so
	
clean:
	rm -f *.o
	rm -f *.so
	rm -f $(EXE)
	
run: $(EXE)
	./$(EXE)	
	
all: clean $(EXE)