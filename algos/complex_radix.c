/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_radix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 23:28:14 by armenag           #+#    #+#             */
/*   Updated: 2026/02/03 21:22:03 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_index_max(t_list *stack_a)
{
	int	index_max;

	index_max = stack_a->index;
	while (stack_a)
	{
		if (stack_a->index > index_max)
			index_max = stack_a->index;
		stack_a = stack_a->next;
	}
	return (index_max);
}

int	binary_size(int index)
{
	int	count;

	count = 1;
	while (index / 2 != 0)
	{
		index /= 2;
		count++;
	}
	return (count);
}

void	sort_binary(t_list **stack_a, t_list **stack_b, int move_on,
		t_bench **bench)
{
	int	i;
	int	j;
	int	size;

	size = ft_lstsize(*stack_a);
	i = 0;
	j = 0;
	while (i < size)
	{
		if (((*stack_a)->index >> move_on & 1) == 1)
			ft_rotate_a(stack_a, bench);
		else
		{
			ft_push_b(stack_a, stack_b, bench);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < j)
	{
		ft_push_a(stack_a, stack_b, bench);
		i++;
	}
}

void	radix_sort(t_list **stack_a, t_list **stack_b, t_bench **bench)
{
	int	i;
	int	max_bin;

	max_bin = binary_size(check_index_max(*stack_a));
	i = 0;
	while (i < max_bin)
	{
		sort_binary(stack_a, stack_b, i, bench);
		i++;
	}
}
