/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:51:29 by ajeloyan          #+#    #+#             */
/*   Updated: 2026/02/09 14:00:12 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_list *stack_a)
{
	float	mistakes;
	float	total_pairs;
	t_list	*temp;

	mistakes = 0;
	total_pairs = 0;
	temp = stack_a;
	if (ft_lstsize(stack_a) == 1)
		return(0);	
	while (ft_lstsize(stack_a))
	{
		while (ft_lstsize(temp->next))
		{
			total_pairs++;
			if (stack_a->index > temp->next->index)
				mistakes++;
			temp = temp->next;
		}
		stack_a = stack_a->next;
		temp = stack_a;
	}
	return (mistakes / total_pairs);
}
