SRCS =	ft_printf.c \
		ft_printf_utils.c \
		ft_print_char.c \
		ft_print_str.c \
		ft_print_ptr.c \
		ft_print_num.c \
		ft_print_u_num.c \
		ft_print_hex.c
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
CC = gcc -Wall -Wextra -Werror
AR = ar rcs

%.o: %.c ft_printf.h
		${CC} -I. -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJS} ft_printf.h
			ar rcs ${NAME} ${OBJS}

bonus:		${OBJS} ft_printf.h
			ar rcs ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean

.PHONY:		all clean fclean re bonus