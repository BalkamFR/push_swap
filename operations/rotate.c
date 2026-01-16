/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeloyan <ajeloyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:10:56 by ajeloyan          #+#    #+#             */
/*   Updated: 2026/01/16 15:35:18 by ajeloyan         ###   ########.fr       */
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
	ft_lstadd_back(stack, ft_lstnew(temp->content));
	*stack = temp->next;
	free(temp);
}

void	ft_rotate_a(t_list **stack_a)
{
	ft_rotate(stack_a);
	ft_putstr("ra\n");
}

void	ft_rotate_b(t_list **stack_b)
{
	ft_rotate(stack_b);
	ft_putstr("rb\n");
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putstr("rr\n");
}