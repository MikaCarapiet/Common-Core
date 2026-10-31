NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
CPPFLAGS = -I$(INC_DIR)
DEPFLAGS = -MMD -MP

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

SRCS = main.c \
	parse.c \
	init.c \
	threads.c \
	routine.c \
	monitor.c \
	time.c \
	state.c \
	cleanup.c
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

-include $(DEPS)

.PHONY: all clean fclean re
