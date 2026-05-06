NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = src
OBJDIR = obj
MLX_DIR = ./mlx_linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_SRC = $(wildcard $(MLX_DIR)/*.c) $(wildcard $(MLX_DIR)/*.h)
LIBDIR = libft

LIBNAME = libft.a
LIB = $(LIBDIR)/$(LIBNAME)

SRCS = args.c color_fill.c init.c main.c fractals.c render.c utils.c
OBJS = $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

MLXFLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm
INCLUDES = -I$(MLX_DIR)

all: $(NAME)

debug: CFLAGS += -g -fsanitize=address
debug: all

$(NAME): $(LIB) $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBDIR) -lft $(MLXFLAGS) -o $(NAME)

$(LIB):
	make -C $(LIBDIR)

$(MLX_LIB): $(MLX_SRC)
	make -C $(MLX_DIR)

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
