/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:09:09 by ajeloyan          #+#    #+#             */
/*   Updated: 2026/02/03 21:33:00 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_push(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!*stack_a)
	{
		ft_putstr("Error\n");
		return ;
	}
	temp = *stack_a;
	ft_lstadd_front(stack_b, ft_lstnew(temp->content, temp->index));
	*stack_a = temp->next;
	free(temp);
}

void	ft_push_b(t_list **stack_a, t_list **stack_b, t_bench **bench)
{
	ft_push(stack_a, stack_b);
	(*bench)->nbr_pb = (*bench)->nbr_pb + 1;
	ft_putstr("pb\n");
}

void	ft_push_a(t_list **stack_a, t_list **stack_b, t_bench **bench)
{
	ft_push(stack_b, stack_a);
	(*bench)->nbr_pa = (*bench)->nbr_pa + 1;
	ft_putstr("pa\n");
}
