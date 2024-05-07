# Nombre del programa de salida
TARGET = gestion_estudiantes.exe

# Compilador
CXX = g++

# Opciones de compilacion
CXXFLAGS = -Wall -std=c++11

# Lista de archivos fuente
SOURCES = main.cpp estudiante.cpp

# Lista de archivos objeto generados a partir de los archivos fuente
OBJECTS = $(SOURCES:.cpp=.exe)

# Regla para compilar los archivos fuente en archivos objeto
%.exe: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para compilar el programa a partir de los archivos objeto
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	./$(TARGET)

# Regla para limpiar los archivos generados
clean:
	rm $(TARGET) $(OBJECTS)