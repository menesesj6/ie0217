# Compilador
CXX = g++   

# Banderas de compilacion
CXXFLAGS = $(shell wx-config --cxxflags) 

# Linking flags
LDFLAGS = $(shell wx-config --libs)       

# El nombre del archivo de código fuente y del ejecutable
SRC = main.cpp
TARGET = MyApp.exe

# La regla predeterminada que se ejecuta cuando escribes 'make'
all: $(TARGET) run

$(TARGET):
	$(CXX) $(SRC) $(CXXFLAGS) $(LDFLAGS) -o $(TARGET)

# Regla para limpiar los archivos compilados (ejecutable)
clean:
	rm -f $(TARGET)

# Regla para ejecutar el programa
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run