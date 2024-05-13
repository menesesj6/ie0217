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
EXCECUTABLE = emailValidator.exe

$(SRC_DIR)/%.exe: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

build: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $(EXCECUTABLE) $(LDFLAGS)

run: $(EXCECUTABLE)
	./$(EXCECUTABLE)

all: 
	make build
	make run

# Regla para limpiar los archivos generados
clean:
	rm $(EXCECUTABLE) $(OBJECTS)

