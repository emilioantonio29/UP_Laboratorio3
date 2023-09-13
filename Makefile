# Nombre del compilador
CC = gcc

# Opciones de compilación
CFLAGS = -Wall

# Directorio de archivos fuente y objetos
SRC_DIR = src
OBJ_DIR = obj

# Nombres de los archivos ejecutables y fuentes
TARGET = main
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Directorio de archivos de encabezado
INC_DIR = include

# Regla predeterminada
all: $(TARGET)

# Compilar el programa
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compilar cada archivo fuente
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)