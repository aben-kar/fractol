# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -I./minilibx-linux

# MiniLibX Library
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Source files
SRCS = main.c fractol.c fractol_utils.c fractol_rendre.c fractol_rend_utils.c event_utils.c
OBJS = $(SRCS:.c=.o)

# Executable name
NAME = fractol

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX_LIB):
	make -C $(MLX_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
