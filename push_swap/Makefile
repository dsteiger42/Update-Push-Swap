NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = errors/errors.c \
		operations/push.c/ operations/rev_rotate.c/ operations/rotate.c/ operations/swap.c \
		algorithm.c \
		sort_3.c \
		main.c

COMPRESS = ar rcs

RM = rm -f

OBJS = $(SRCS:.c=.o)

FT_PRINTFDIR = ./ft_printf
FT_PRINTF = $(FT_PRINTFDIR)/libftprintf.a

LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(FT_PRINTF) $(LIBFT)
	@$(CC) $(OBJS) $(FT_PRINTF) $(LIBFT) -o $(NAME)

$(FT_PRINTF):
	@make -C $(FT_PRINTFDIR) --no-print-directory

$(LIBFT):
	@make -C $(LIBFTDIR) --no-print-directory

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME) $(FT_PRINTF) $(LIBFT)
	@make -C $(FT_PRINTFDIR) fclean --no-print-directory
	@make -C $(LIBFTDIR) fclean --no-print-directory

re: fclean all