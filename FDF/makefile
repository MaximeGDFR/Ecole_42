NAME = fdf

# Directories
SRC_DIR = .
LIBFT_DIR = ./libft
GNL_DIR = ./get_next_line
PRINTF_DIR = ./ft_printf
FDF_UTILS_DIR = ./fdf_utils
MLX_DIR = ./minilibx-linux

# Sources
SRC = $(wildcard $(SRC_DIR)/*.c)
LIBFT_SRC = $(wildcard $(LIBFT_DIR)/*.c)
GNL_SRC = $(wildcard $(GNL_DIR)/*.c)
PRINTF_SRC = $(wildcard $(PRINTF_DIR)/*.c)
FDF_UTILS_SRC = $(wildcard $(FDF_UTILS_DIR)/*.c)

# Combine all sources
ALL_SRC = $(SRC) $(LIBFT_SRC) $(GNL_SRC) $(PRINTF_SRC) $(FDF_UTILS_SRC)

# Objects
OBJ := $(ALL_SRC:%.c=%.o)

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
MLXFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
AR = ar
ARFLAGS = -rcs

# Build rules
all : $(NAME)

$(NAME): $(OBJ)
	@echo "Compilation of MiniLibX..."
	@$(MAKE) -C $(MLX_DIR) # Compile MiniLibX
	@echo "Compilation of $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) -o $(NAME)
	@echo "Generated executable: $(NAME)"

%.o: %.c
	@$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(SRC_DIR) -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(PRINTF_DIR) -I$(FDF_UTILS_DIR) -c $< -o $@
	@echo "Created object: $@"

clean :
	@echo "Cleaning..."
	@rm -f $(OBJ)
	@echo "Removed objects."
	@$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	@echo "Cleaning..."
	@rm -f $(NAME)
	@echo "All removed."
	@$(MAKE) fclean -C $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re
