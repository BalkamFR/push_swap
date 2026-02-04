/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_algos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeloyan <ajeloyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:28:53 by ajeloyan          #+#    #+#             */
/*   Updated: 2026/02/04 20:06:22 by ajeloyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	vshort_sort(t_list **stack_a, t_bench **bench)
{
	if ((*stack_a)->index == 2)
	{
		ft_swap_a(*stack_a, bench);
		ft_reverse_rotate_a(stack_a, bench);
	}
	else if ((*stack_a)->index == 1 && (*stack_a)->next->index != 0)
		ft_reverse_rotate_a(stack_a, bench);
	else if ((*stack_a)->index == 1 && (*stack_a)->next->index == 0)
		ft_swap_a(*stack_a, bench);
	else if ((*stack_a)->index == 0)
		ft_rotate_a(stack_a, bench);
}
