# Compilador
CXX = g++

# Opciones de compilacion
CXXFLAGS = -std=c++11

# OPciones de linking
LDFLAGS = -lstdc++fs
# Directorio source
SRC_DIR = src

# Lista de archivos fuente
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(SRC_DIR)/%.exe)
EXCECUTABLE = tarea5.x

# Compilar y correr el programa
all: build run

# Crear archivos objetos
$(SRC_DIR)/%.exe: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilar el ejecutable dle programa
build: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $(EXCECUTABLE) $(LDFLAGS)

# Correr el programa
run: $(EXCECUTABLE)
	./$(EXCECUTABLE)



# Regla para limpiar los archivos generados
clean:
	rm $(EXCECUTABLE) $(OBJECTS)

