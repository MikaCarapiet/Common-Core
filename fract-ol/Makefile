NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = src
OBJDIR = obj
MLX_DIR = ./mlx_linux

SRCS = args.c cleanup.c color.c events.c init.c julia.c main.c mandelbrot.c math_utils.c render.c
OBJS = $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

MLXFLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm
INCLUDES = -I$(MLX_DIR)

all: $(NAME)

debug: CFLAGS += -g -fsanitize=address
debug: all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)


$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)
clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
