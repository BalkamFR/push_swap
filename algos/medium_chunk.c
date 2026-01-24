/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeloyan <ajeloyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:19:12 by ajeloyan          #+#    #+#             */
/*   Updated: 2026/01/23 18:06:02 by ajeloyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_number(t_list *stack_a)
{
	int	tot_number;
	int	res;

	tot_number = ft_lstsize(stack_a);
	res = 0;
	while ((res * res) < tot_number)
		res++;
	return (res);
}


void    push_index(t_list **stack_a, t_list **stack_b, int value)
{
    t_list *temp;

    temp = *stack_a;
    while (temp)
    {
        if (temp->index == value)
        {
            ft_push_b(stack_a, stack_b);
            return;
        }
        temp = temp->next;
    }
}

int	check_min_index(t_list *stack_a, int chunk_size)
{
	int res;

	res = stack_a->index;
	while (stack_a)
	{
		if (stack_a->index < chunk_size)
			res = stack_a->index;
		stack_a = stack_a->next;
	}
	return (res);
}



void	chunk_sort(t_list **stack_a, t_list **stack_b)
{
	int	chunk_numbers;
	int	size;
	int	i;

	(void)stack_b;
	size = ft_lstsize(*stack_a);
	chunk_numbers = chunk_number(*stack_a);
	i = 0;
	while (ft_lstsize(*stack_a) > 1)
	{
        i = 0;
        while (i < chunk_numbers)
        {
            
            i++;
        }
        chunk_numbers = chunk_numbers + chunk_numbers;
	}
}

