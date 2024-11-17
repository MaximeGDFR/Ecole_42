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
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
TEST_SRC = test.c
TEST_NAME = test_printf

%.o: %.c ft_printf.h
			${CC} ${CFLAGS} -I. -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJS} ft_printf.h
			${AR} ${NAME} ${OBJS}

bonus:		${OBJS} ft_printf.h
			${AR} ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean

test:		${NAME} ${TEST_SRC}
			${CC} ${CFLAGS} -o ${TEST_NAME} ${TEST_SRC} -L. -lftprintf
			./${TEST_NAME}

.PHONY:		all clean fclean re bonus test