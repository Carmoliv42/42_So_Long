NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
SCRS = ft_printf.c printf_hex.c printf_int.c printf_pointer.c printf_putchar.c printf_putstr.c printf_unsigned_int.c \

OBJS = $(SCRS:.c=.o)
AR = ar rcs

#MAIN_SRC = ft_printf.c
#EXEC = a.out

$(EXEC): $(MAIN_SRC) $(NAME)
	$(CC) $(CFLAGS) $(MAIN_SRC) $(NAME) -o $(EXEC)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME) $(EXEC)

run: $(EXEC)
	./$(EXEC)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) $(EXEC)

re: fclean all