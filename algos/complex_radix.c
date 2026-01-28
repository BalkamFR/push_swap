/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_radix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armenag <armenag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 23:28:14 by armenag           #+#    #+#             */
/*   Updated: 2026/01/28 02:11:33 by armenag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int binary_size(int index)
{
    int count;

    count = 1;
    while (index / 2 != 0)
    {
        index /= 2;
        count++;
    }
    return (count);
}

void radix_sort(t_list **stack_a, t_list **stack_b)
{
    int i;
    int max_bin;
    int max_index;

    max_index = check_index_max(*stack_a);
    max_bin = binary_size(max_index);
    i = 0;
    while(i < ft_lstsize(*stack_a))
    {
        if((*stack_a)->index & 1!= 1)
            ft_push_b(stack_a, stack_b);
        else
            ft_rotate_a(stack_a);
        i++;
    }
}
