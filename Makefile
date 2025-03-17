CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -lXext -lX11 -lm

SRCS = main.c main_utils.c mandelbrot.c mandelbrot_utils.c julia.c julia_utils.c event_utils_mandelbrot.c event_utils_julia.c utils_function.c function_helper.c
OBJS = $(SRCS:.c=.o)

NAME = fractol

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY: $(OBJS)