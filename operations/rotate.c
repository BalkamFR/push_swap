/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:10:56 by ajeloyan          #+#    #+#             */
/*   Updated: 2026/02/03 21:33:09 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_rotate(t_list **stack)
{
	t_list	*temp;

	if (!*stack)
	{
		ft_putstr("Error\n");
		return ;
	}
	temp = *stack;
	ft_lstadd_back(stack, ft_lstnew(temp->content, temp->index));
	*stack = temp->next;
	free(temp);
}

void	ft_rotate_a(t_list **stack_a, t_bench **bench)
{
	ft_rotate(stack_a);
	(*bench)->nbr_ra = (*bench)->nbr_ra + 1;
	ft_putstr("ra\n");
}

void	ft_rotate_b(t_list **stack_b, t_bench **bench)
{
	ft_rotate(stack_b);
	(*bench)->nbr_rb = (*bench)->nbr_rb + 1;
	ft_putstr("rb\n");
}

void	ft_rr(t_list **stack_a, t_list **stack_b, t_bench **bench)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	(*bench)->nbr_rr = (*bench)->nbr_rr + 1;
	ft_putstr("rr\n");
}
