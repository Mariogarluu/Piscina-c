NAME = bsq

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_main.c ft_aux.c ft_atoi.c ft_files.c ft_free_map.c ft_initialize.c ft_process.c ft_process2.c ft_read_stdin.c ft_validate.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c bsq.h
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re

