/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:09:43 by ajeloyan          #+#    #+#             */
/*   Updated: 2026/02/03 21:33:18 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_swap(t_list *stack)
{
	int	temp;

	if (!stack)
	{
		ft_putstr("Error\n");
		return ;
	}
	if (!stack->next->content)
		return ;
	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
}

void	ft_swap_a(t_list *stack_a, t_bench **bench)
{
	ft_swap(stack_a);
	(*bench)->nbr_sa = (*bench)->nbr_sa + 1;
	ft_putstr("sa\n");
}

void	ft_swap_b(t_list *stack_b, t_bench **bench)
{
	ft_swap(stack_b);
	(*bench)->nbr_sb = (*bench)->nbr_sb + 1;
	ft_putstr("sb\n");
}

void	ft_ss(t_list *stack_a, t_list *stack_b, t_bench **bench)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	(*bench)->nbr_ss = (*bench)->nbr_ss + 1;
	ft_putstr("ss\n");
}
