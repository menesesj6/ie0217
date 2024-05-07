# Nombre del programa de salida
TARGET = matrix.exe

# Objetivo predeterminado
all: $(TARGET)

# Compilador
CXX = g++

# Opciones de compilacion
CXXFLAGS = -std=c++11

# Lista de archivos fuente
SOURCES = src/main.cpp src/Matrix.cpp src/BasicOperations.cpp src/InputValidator.cpp

# Lista de archivos objeto generados a partir de los archivos fuente
OBJECTS = $(SOURCES:.cpp=.exe)

# Regla para compilar los archivos fuente en archivos objeto
%.exe: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para compilar el programa a partir de los archivos objeto
matrix: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	./$(TARGET)

# Documentacion Doxygen
doxygen: html
	,/html/index.html

# Regla para limpiar los archivos generados
.PHONY: clean
clean:
	rm $(TARGET) $(OBJECTS)