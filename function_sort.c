/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:03:23 by papilaz           #+#    #+#             */
/*   Updated: 2026/01/09 17:36:59 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_list *stack_a)
{
	int	temp;

	if (!stack_a->next->content)
		return ;
	temp = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = temp;
	ft_putstr("sa\n");
}

void	ft_swap_b(t_list *stack_b)
{
	int	temp;

	if (!stack_b->next->content)
		return ;
	temp = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next->content = temp;
	ft_putstr("sb\n");
}

void	ft_ss(t_list *stack_a, t_list *stack_b)
{
	int	temp;

	if (!stack_a->next->content || !stack_b->next->content)
		return ;
	temp = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = temp;
	temp = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next->content = temp;
	ft_putstr("ss\n");
}

void	ft_push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	temp = *stack_a;
	
	ft_lstadd_front(stack_b, ft_lstnew(temp->content));
	*stack_a = temp->next;
	ft_putstr("pb\n");
}

void	ft_push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	temp = *stack_b;
	
	ft_lstadd_front(stack_a, ft_lstnew(temp->content));
	*stack_b = temp->next;
	ft_putstr("pa\n");
}

void	ft_rotate_a(t_list **stack_a)
{
	t_list *temp;
	
	ft_lstlast
}