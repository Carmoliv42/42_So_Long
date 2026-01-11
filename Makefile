NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c map_read.c map_validation.c so_long_utils.c controls.c\
      GNL/get_next_line.c GNL/get_next_line_utils.c game_render.c

OBJ = $(SRC:.c=.o)

INC = -I . -I GNL -I mlx_linux -I ft_printf

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

LIBS = mlx_linux/libmlx.a -lm -lX11 -lXext $(FT_PRINTF)

all: $(FT_PRINTF) $(NAME)

$(NAME): $(OBJ) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
