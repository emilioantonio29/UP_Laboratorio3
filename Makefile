# Nombre del ejecutable
TARGET = main

# Directorios de origen y destino
SRC_DIR = .
OBJ_DIR = .
HEADERS_DIR = headers

# Lista de archivos fuente y objetos
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

# Compilador y opciones de compilación
CC = gcc
CFLAGS = -Wall -pedantic-errors -O3 -std=gnu89

# Regla principal
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Regla para la creación de objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ_DIR)/*.o

.PHONY: all clean
