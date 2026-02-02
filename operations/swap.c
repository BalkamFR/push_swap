/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeloyan <ajeloyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:09:43 by ajeloyan          #+#    #+#             */
/*   Updated: 2026/01/16 16:01:57 by ajeloyan         ###   ########.fr       */
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

void	ft_swap_a(t_list *stack_a)
{
	ft_swap(stack_a);
	ft_putstr("sa\n");
}

void	ft_swap_b(t_list *stack_b)
{
	ft_swap(stack_b);
	ft_putstr("sb\n");
}
void	ft_ss(t_list *stack_a, t_list *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putstr("ss\n");
}
