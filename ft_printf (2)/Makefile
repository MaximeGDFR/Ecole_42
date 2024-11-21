SRCS =	printf_utils/ft_bzero.c \
		printf_utils/ft_calloc.c \
		printf_utils/ft_find_length.c \
		printf_utils/ft_handle_flags.c \
		printf_utils/ft_handle_padding.c \
		printf_utils/ft_print_char.c \
		printf_utils/ft_print_hex.c \
		printf_utils/ft_print_itoa.c \
		printf_utils/ft_print_number.c \
		printf_utils/ft_print_pointer.c \
		printf_utils/ft_print_string.c \
		printf_utils/ft_print_unsigned_number.c \
		printf_utils/ft_print_utoa.c \
		printf_utils/ft_print_xtoa.c \
		printf_utils/ft_search_flags.c \
		printf_utils/ft_strdup.c \
		printf_utils/ft_strlcpy.c \
		printf_utils/ft_strlen.c \
		ft_printf.c

OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
INCLUDE = -I.
TEST_SRC = test.c
TEST_NAME = test_printf

printf_utils/%.o: printf_utils/%.c ft_printf.h
			${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

all:		${NAME}

$(NAME):	${OBJS} ft_printf.h
			${AR} ${NAME} ${OBJS}

bonus:		${OBJS} ft_printf.h
			${AR} ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

test:		${NAME} ${TEST_SRC}
			${CC} ${CFLAGS} ${INCLUDE} -o ${TEST_NAME} ${TEST_SRC} -L. -lftprintf
			./${TEST_NAME}

.PHONY:		all clean fclean re bonus test