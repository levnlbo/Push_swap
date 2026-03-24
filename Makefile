NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
INC		= -I includes

SRCS	= src/main.c \
		  src/stack_utils.c \
		  src/ops_swap.c \
		  src/ops_push.c \
		  src/ops_rotate.c \
		  src/ops_rrotate.c \
		  src/parse.c \
		  src/sort_utils.c \
		  src/sort_small.c \
		  src/sort_simple.c \
		  src/sort_medium.c \
		  src/sort_complex.c \
		  src/sort_complex2.c \
		  src/sort_adaptive.c \
		  src/bench.c \
		  src/error.c \
		  src/ft_split.c \
		  src/stack_utils2.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
