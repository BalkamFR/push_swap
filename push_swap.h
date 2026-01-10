/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:37:52 by papilaz           #+#    #+#             */
/*   Updated: 2026/01/09 20:07:17 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/includes/ft_printf.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*previous;
	struct s_list	*next;
}					t_list;

int					ft_putstr(char *tab);
int					ft_putchar(char c);
int					ft_putnbr(int nb);
int					ft_atoi(const char *nptr);
char				**ft_split(char *s, char c);

t_list				*ft_lstnew(int content);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_print_stack_list(t_list *list, t_list *list2);
void				ft_print_stack_list_2(t_list *list, t_list *list2);
int					ft_lstsize(t_list *lst);
void				ft_lstclear(t_list **lst);
t_list				*ft_lstlast(t_list *lst);

t_list				*list_parsed(char **argv, int argc);
void				ft_print_stack(t_list *list);
t_list				*create_stack(char **list_brut);
t_list				*ft_lstclone(t_list *node);

void				ft_ss(t_list *stack_a, t_list *stack_b);
void				ft_swap_a(t_list *stack_a);
void				ft_push_b(t_list **stack_a, t_list **stack_b);
void				ft_push_a(t_list **stack_a, t_list **stack_b);
void				ft_rotate_a(t_list **stack_a);
void				ft_rotate_b(t_list **stack_b);
void				ft_rr(t_list **stack_a, t_list **stack_b);
void				ft_reverse_rotate_a(t_list **stack_a);
void				ft_reverse_rotate_b(t_list **stack_b);
void				ft_rrr(t_list **stack_a, t_list **stack_b);

#endif