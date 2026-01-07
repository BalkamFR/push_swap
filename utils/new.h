/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:37:52 by papilaz           #+#    #+#             */
/*   Updated: 2026/01/07 20:18:29 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef NEW_H
# define NEW_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

# include "../push_swap.h"


int	ft_putstr(char *tab);
int	ft_putchar(char c);
int	ft_putnbr(int nb);
int	ft_printf(const char *list, ...);
int	ft_print_ptr(void *ptr);
int	ft_putnbr_exa_long(unsigned long int nb_long);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putnbr_exa(unsigned long int nb_long, char *base);


t_list	*ft_lstnew(int	content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_print_stack_list(t_list *list, t_list *list2);
void	ft_lstadd_front(t_list **lst, t_list *new);
int	ft_atoi(const char *nptr);
char	**ft_split(char *s, char c);
int	ft_lstsize(t_list *lst);
void	ft_ss(t_list *stack_a, t_list *stack_b);

void	ft_swap_a(t_list *stack_a);
void	ft_push_b(t_list **stack_a, t_list **stack_b);
void	ft_push_a(t_list **stack_a, t_list **stack_b);

#endif