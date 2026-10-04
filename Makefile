NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a
FTPRINTF = ft_printf/libftprintf.a

SRCS = main.c parsing/parse_args.c parsing/validate.c stack_utils/stack_new.c \
	stack_utils/stack_add_back.c stack_utils/stack_free.c operations/ops_swap.c \
	operations/ops_push.c operations/ops_rotate.c operations/ops_rrotate.c \
	stack_utils/stack_check.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FTPRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FTPRINTF) -o $(NAME)

%.o: %.c
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