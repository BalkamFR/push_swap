/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_select.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeloyan <ajeloyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:02:45 by ajeloyan          #+#    #+#             */
/*   Updated: 2026/01/18 18:23:01 by ajeloyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_min_pos(t_list *stack_a, int res)
{
	int	count;

	count = 0;
	while (stack_a->content != res)
	{
		stack_a = stack_a->next;
		count++;
	}
	return (count);
}

int	check_min(t_list *stack_a)
{
	int	res;

	res = stack_a->content;
	while (stack_a)
	{
		if (stack_a->content < res)
			res = stack_a->content;
		stack_a = stack_a->next;
	}
	return (res);
}

void	selection_sort(t_list **stack_a, t_list **stack_b)
{
	int min;

	while (ft_lstsize(*stack_a) > 1)
	{
		min = check_min((*stack_a));
		while ((*stack_a)->content != min)
		{
			if (check_min_pos(*stack_a, min) > (ft_lstsize(*stack_a) / 2))
				ft_reverse_rotate_a(stack_a);
			else
				ft_rotate_a(stack_a);
		}
		ft_push_b(stack_a, stack_b);
	}
	while (ft_lstsize(*stack_b) > 0)
		ft_push_a(stack_a, stack_b);
}