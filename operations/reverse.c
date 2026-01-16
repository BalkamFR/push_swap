/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeloyan <ajeloyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:11:28 by ajeloyan          #+#    #+#             */
/*   Updated: 2026/01/16 15:29:58 by ajeloyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*temp2;
	int		res;

	if (!*stack)
	{
		ft_putstr("Error\n");
		return ;
	}
	res = ft_lstsize(*stack);
	last = *stack;
	ft_lstadd_front(stack, ft_lstclone(ft_lstlast(*stack)));
	while (res > 2)
	{
		last = last->next;
		res--;
	}
	temp2 = last->next;
	last->next = NULL;
	free(temp2);
}

void	ft_reverse_rotate_a(t_list **stack_a)
{
	ft_reverse_rotate(stack_a);
	ft_putstr("rra\n");
}

void	ft_reverse_rotate_b(t_list **stack_b)
{
	ft_reverse_rotate(stack_b);
	ft_putstr("rrb\n");
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	ft_putstr("rrb\n");
}
