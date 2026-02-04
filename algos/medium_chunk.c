/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:23:25 by papilaz           #+#    #+#             */
/*   Updated: 2026/02/03 21:32:34 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_range_index(t_list *stack_a, int max)
{
	int	res;

	while (ft_lstsize(stack_a) > 1)
	{
		if (stack_a->index < max)
		{
			res = stack_a->index;
			return (res);
		}
		stack_a = stack_a->next;
	}
	return (0);
}

int	chunk_number(t_list *stack_a)
{
	int	tot_number;
	int	res;

	tot_number = ft_lstsize(stack_a);
	res = 0;
	while ((res * res) <= tot_number)
		res++;
	return (res);
}

int	check_max(t_list *stack_b)
{
	int	res;

	res = stack_b->content;
	while (stack_b)
	{
		if (stack_b->content > res)
			res = stack_b->content;
		stack_b = stack_b->next;
	}
	return (res);
}

static void	chunk_sort_push_a(t_list **stack_a, t_list **stack_b,
		t_bench **bench)
{
	int	min;

	while (ft_lstsize(*stack_b) > 0)
	{
		min = check_max((*stack_b));
		while ((*stack_b)->content != min)
		{
			if (check_min_pos(*stack_b, min) > (ft_lstsize(*stack_b) / 2))
				ft_reverse_rotate_b(stack_b, bench);
			else
				ft_rotate_b(stack_b, bench);
		}
		ft_push_a(stack_a, stack_b, bench);
	}
}

void	chunk_sort(t_list **stack_a, t_list **stack_b, t_bench **bench)
{
	int	index_range;
	int	i;
	int	taugmentation;

	taugmentation = chunk_number(*stack_a);
	i = 0;
	index_range = chunk_number(*stack_a);
	while (*stack_a)
	{
		while (i < index_range && *stack_a)
		{
			while ((*stack_a)->index >= index_range)
			{
				ft_rotate_a(stack_a, bench);
			}
			ft_push_b(stack_a, stack_b, bench);
			i++;
		}
		index_range = index_range + taugmentation;
	}
	chunk_sort_push_a(stack_a, stack_b, bench);
}
