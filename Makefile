NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a
FTPRINTF = ft_printf/libftprintf.a

SRCS = SRCS = main.c disorder.c \
	parsing/parse_args.c parsing/validate.c \
	stack_utils/stack_new.c stack_utils/stack_add_back.c \
	stack_utils/stack_free.c stack_utils/stack_check.c \
	stack_utils/stack_index.c stack_utils/stack_pos.c \
	operations/ops_primitives.c operations/ops_dispatch.c \
	operations/ops_helpers.c \
	algorithms/simple.c algorithms/medium.c \
	algorithms/complex.c algorithms/strategy.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FTPRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FTPRINTF) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

$(FTPRINTF):
	$(MAKE) -C ft_printf

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	$(MAKE) -C ft_printf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re