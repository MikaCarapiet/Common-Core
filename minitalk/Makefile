NAME_CLIENT = client
NAME_SERVER = server

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = src
OBJDIR = obj

CLIENT_SRCS = client.c utils.c
SERVER_SRCS = server.c utils.c

CLIENT_OBJS = $(addprefix $(OBJDIR)/,$(CLIENT_SRCS:.c=.o))
SERVER_OBJS = $(addprefix $(OBJDIR)/,$(SERVER_SRCS:.c=.o))

debug: CFLAGS += -g -fsanitize=address
debug: all

all: $(NAME_CLIENT) $(NAME_SERVER)


$(NAME_CLIENT): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(NAME_CLIENT)

$(NAME_SERVER): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o $(NAME_SERVER)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)
clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re
