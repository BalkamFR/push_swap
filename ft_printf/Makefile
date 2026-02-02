NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRCDIR = .
DEPDIR = $(SRCDIR)/.deps
INCDIR = includes

SRCS = ft_print_char.c ft_print_str.c ft_print_nbr.c ft_printf.c ft_check_format.c ft_pointer.c
OBJS = $(SRCS:.c=.o)
HEADER = $(INCDIR)/ft_printf.h

INCLUDES = -I$(INCDIR)

DEPFLAGS = -MMD -MP -MF $(DEPDIR)/$*.d

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	@mkdir -p $(DEPDIR)
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@

-include $(SRCS:%.c=$(DEPDIR)/%.d)

clean: 
	rm -rf $(DEPDIR)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re