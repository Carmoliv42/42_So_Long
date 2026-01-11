# Nome do executável
NAME = so_long

# Compilador e flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Fontes
SRC = main.c map_read.c map_validation.c so_long_utils.c controls.c\
      GNL/get_next_line.c GNL/get_next_line_utils.c game_render.c

# Objetos
OBJ = $(SRC:.c=.o)

# Includes
INC = -I . -I GNL -I mlx_linux -I ft_printf

# diretorios do printft

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

# Bibliotecas para Linux
LIBS = mlx_linux/libmlx.a -lm -lX11 -lXext $(FT_PRINTF)

# Regra padrão
all: $(FT_PRINTF) $(NAME)

# Compilação do executável
$(NAME): $(OBJ) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS)

# Compilação dos objetos
%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Compilação do printft

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

# Remove arquivos objeto
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(FT_PRINTF_DIR) clean

# Remove arquivos objeto + executável
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

# Recompila tudo
re: fclean all

# Alvos "não arquivos"
.PHONY: all clean fclean re
