
NAME        = push_swap


OBJ_DIR     = obj
PRINTF_DIR  = ft_printf
INC_DIR     = includes


PRINTF_LIB  = $(PRINTF_DIR)/libftprintf.a


CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3

INCLUDES    = -I. -I$(PRINTF_DIR)/includes -Iutils

SRCS        = main.c \
              parsing.c \
              create_stack.c \
              function_sort.c \
              utils/ft_split.c \
              utils/basics.c \
              utils/list.c \



OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

DEPS        = $(OBJS:.o=.d)



all: $(NAME)


$(NAME): $(OBJS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS) -L$(PRINTF_DIR) -lftprintf -o $(NAME)


$(PRINTF_LIB):
	@make -C $(PRINTF_DIR)


$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@


-include $(DEPS)



clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(PRINTF_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re