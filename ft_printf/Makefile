CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rcs

SRC =	ft_printf.c \
	ft_printf_utils.c \
	ft_putchar.c \
	ft_putfloat.c \
	ft_puthex.c \
	ft_putnbr.c \
	ft_putstr.c \
	ft_putaddr.c

OBJ = $(SRC:.c=.o)
NAME = libftprintf.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
