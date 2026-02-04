
NAME        = push_swap

OBJ_DIR     = obj
INC_DIR     = includes

CFLAGS      = -Wall -Wextra -Werror -g3
CFLAGS      = -g3

INCLUDES    = -I./includes -Iutils

SRCS        = main.c \
	parsing.c \
	parsing_2.c \
	create_stack.c \
	operations/swap.c \
	operations/push.c \
	operations/rotate.c \
	operations/reverse.c \
	utils/ft_split.c \
	utils/basics.c \
	utils/list.c \
	utils/list_2.c \
	utils/ft_itoa.c \
	algos/simple_select.c \
	algos/medium_chunk.c \
	algos/complex_radix.c \
	disorder.c \
	bench.c \
	algos/mini_algos.c


OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

DEPS        = $(OBJS:.o=.d)



all: $(NAME)


$(NAME): $(OBJS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS) -L$(PRINTF_DIR) -lftprintf -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re