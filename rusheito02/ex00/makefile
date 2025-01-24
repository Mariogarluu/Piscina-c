# Definición de variables
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_main.c ft_dictionary.c ft_string.c ft_convert.c ft_decompose_number.c
OBJ = $(SRC:.c=.o)
TARGET = rush-02

# Regla para compilar el programa
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Regla para compilar los archivos de objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Limpiar los archivos de objeto y el ejecutable
fclean: clean
	rm -f $(TARGET)

# Limpiar los archivos de objeto
clean:
	rm -f $(OBJ)

# Regla para eliminar todos los archivos temporales
re: fclean all

.PHONY: all clean fclean re
