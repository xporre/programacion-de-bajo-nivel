EXE = oop
COMP = g++
FLAGS = 
BLOQUES = tarea4.o
LIBRERIA = TAREA4.so
WRAP = tarea4.cxx

$(EXE): tarea4.o $(BLOQUES)
	$(COMP) $(FLAGS) main.o -o $(EXE) -Wl,-rpath=/usr/lib -L/urs/lib -ltarea4
	
# Regla comodín para compilar librerías
# Se agrega el -fPIC
%.o: %.cpp %.h
	$(COMP) $(FLAGS) -fPIC -o  $@ $< -c

# Regla para crear librería compartida (.so)
lib: $(BLOQUES)
	$(COMP) -shared $^ -o $(LIBRERIA)
	sudo mv $(LIBRERIA) /usr/lib

main.o: main.cpp $(BLOQUES)
	$(COMP) $(FLAGS) -o $@ $< -c

# Regla para wraper
wrap: tarea4.py tarea4.h 
	swig -python3 -c++ tarea4.py

# Regla para crear librería desde el wraper
_libGato.so: $(WRAP) $(BLOQUES)
	$(COMP) $(FLAGS) -fPIC -c $(WRAP) -o lib_wrap.o -I/Users/xavierporre/opt/anaconda3/bin/python3
	$(COMP) -shared lib_wrap.o tarea4.o  -o TAREA4.so
	
clean:
	rm -f *.o
	rm -f *.so
	rm -f $(EXE)

run: $(EXE)
	./$(EXE)	
	
all: clean $(EXE)