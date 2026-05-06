NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = src
OBJDIR = obj
MLX_DIR = ./mlx_linux
LIBDIR = libft

LIBNAME = libft.a
LIB = $(LIBDIR)/$(LIBNAME)

SRCS = args.c cleanup.c color.c events.c init.c julia.c main.c mandelbrot.c render.c math_utils.c
OBJS = $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

MLXFLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm
INCLUDES = -I$(MLX_DIR)

all: $(NAME)

debug: CFLAGS += -g -fsanitize=address
debug: all

$(NAME): $(LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBDIR) -lft $(MLXFLAGS) -o $(NAME)

$(LIB):
	make -C $(LIBDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)
clean:
	rm -rf $(OBJDIR)
	make -C $(LIBDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBDIR) fclean

re: fclean all

.PHONY: all clean fclean re debug
