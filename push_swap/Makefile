NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = src
OBJDIR = obj
LIBDIR = libft

SRCS = main.c validate.c
OBJS = $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

LIBNAME = libft.a
LIB = $(LIBDIR)/$(LIBNAME)

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBDIR) -lft -o $(NAME)

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

.PHONY: all clean fclean re
