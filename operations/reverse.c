/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:11:28 by ajeloyan          #+#    #+#             */
/*   Updated: 2026/02/03 18:31:51 by papilaz          ###   ########.fr       */
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

void	ft_reverse_rotate_a(t_list **stack_a, t_bench **bench)
{
	ft_reverse_rotate(stack_a);
	(*bench)->nbr_rra = (*bench)->nbr_rra + 1;
	ft_putstr("rra\n");
}

void	ft_reverse_rotate_b(t_list **stack_b, t_bench **bench)
{
	ft_reverse_rotate(stack_b);
	(*bench)->nbr_rrb = (*bench)->nbr_rrb + 1;
	ft_putstr("rrb\n");
}

void	ft_rrr(t_list **stack_a, t_list **stack_b, t_bench **bench)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	(*bench)->nbr_rrr = (*bench)->nbr_rrr + 1;
	ft_putstr("rrr\n");
}
