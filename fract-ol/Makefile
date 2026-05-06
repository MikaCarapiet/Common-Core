NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = src
OBJDIR = obj
MLX_DIR = minilibx-linux
MLX_REPO = https://github.com/42paris/minilibx-linux.git
MLX_LIB = $(MLX_DIR)/libmlx.a
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

$(MLX_DIR):
	git clone $(MLX_REPO) $(MLX_DIR)

$(MLX_LIB): | $(MLX_DIR)
	make -C $(MLX_DIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR) $(MLX_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

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
