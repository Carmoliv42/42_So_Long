NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c map_read.c map_validation.c so_long_utils.c controls.c\
      GNL/get_next_line.c GNL/get_next_line_utils.c game_render.c

OBJ = $(SRC:.c=.o)

INC = -I . -I GNL -I minilibx-linux -I ft_printf

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

LIBS = $(MLX) -lm -lX11 -lXext $(FT_PRINTF)

all: $(FT_PRINTF) $(MLX) $(NAME)

$(NAME): $(OBJ) $(FT_PRINTF) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re

