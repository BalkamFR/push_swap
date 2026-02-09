# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/03 00:28:55 by papilaz           #+#    #+#              #
#    Updated: 2026/02/09 18:12:43 by papilaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap

OBJ_DIR     = obj
INC_DIR     = includes

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3
INCLUDES    = -I. -Iutils

SRCS        = main.c \
              parsing.c \
              parsing_2.c \
              create_stack.c \
              disorder.c \
              bench_2.c \
              bench.c \
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
              algos/complex_radix.c

OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

DEPS        = $(OBJS:.o=.d)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

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