CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rcs

SRC = 

SRC_BONUS = 

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
NAME = libftprintf.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

bonus:	$(OBJ) $(OBJ_BONUS)
	 $(AR) $(ARFLAGS) $(NAME) $(OBJ) $(OBJ_BONUS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
