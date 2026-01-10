/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:03:23 by papilaz           #+#    #+#             */
/*   Updated: 2026/01/10 19:52:12 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_list *stack_a)
{
	int	temp;

	if (!stack_a)
	{
		ft_putstr("Error\n");
		return ;
	}
	if (!stack_a->next->content)
		return ;
	temp = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = temp;
	ft_putstr("sa\n");
}

void	ft_swap_b(t_list *stack_b)
{
	int	temp;

	if (!stack_b)
	{
		ft_putstr("Error\n");
		return ;
	}
	if (!stack_b->next->content)
		return ;
	temp = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next->content = temp;
	ft_putstr("sb\n");
}

void	ft_ss(t_list *stack_a, t_list *stack_b)
{
	int	temp;

	if (!stack_a || !stack_b)
	{
		ft_putstr("Error\n");
		return ;
	}
	if (!stack_a->next->content || !stack_b->next->content)
		return ;
	temp = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = temp;
	temp = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next->content = temp;
	ft_putstr("ss\n");
}

void	ft_push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!*stack_a || !*stack_b)
	{
		ft_putstr("Error\n");
		return ;
	}
	temp = *stack_a;
	ft_lstadd_front(stack_b, ft_lstnew(temp->content));
	*stack_a = temp->next;
	ft_putstr("pb\n");
}

void	ft_push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!*stack_a || !*stack_b)
	{
		ft_putstr("Error\n");
		return ;
	}
	temp = *stack_b;
	ft_lstadd_front(stack_a, ft_lstnew(temp->content));
	*stack_b = temp->next;
	ft_putstr("pa\n");
}

void	ft_rotate_a(t_list **stack_a)
{
	t_list	*temp;

	if (!*stack_a)
	{
		ft_putstr("Error\n");
		return ;
	}
	temp = *stack_a;
	ft_lstadd_back(stack_a, ft_lstnew(temp->content));
	*stack_a = temp->next;
	ft_putstr("ra\n");
}

void	ft_rotate_b(t_list **stack_b)
{
	t_list	*temp;

	if (!*stack_b)
	{
		ft_putstr("Error\n");
		return ;
	}
	temp = *stack_b;
	ft_lstadd_back(stack_b, ft_lstnew(temp->content));
	*stack_b = temp->next;
	ft_putstr("rb\n");
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!*stack_a || !*stack_b)
	{
		ft_putstr("Error\n");
		return ;
	}
	temp = *stack_a;
	ft_lstadd_back(stack_a, ft_lstnew(temp->content));
	*stack_a = temp->next;
	temp = *stack_b;
	ft_lstadd_back(stack_b, ft_lstnew(temp->content));
	*stack_b = temp->next;
	ft_putstr("rr\n");
}

void	ft_reverse_rotate_a(t_list **stack_a)
{
	t_list	*temp;

	if (!*stack_a)
	{
		ft_putstr("Error\n");
		return ;
	}
	temp = ft_lstlast(*stack_a);
	ft_lstadd_front(stack_a, ft_lstnew(temp->content));
	temp = temp->previous;
	temp->next = NULL;
	ft_putstr("rra\n");
}

void	ft_reverse_rotate_b(t_list **stack_b)
{
	t_list	*temp;
	int		res;

	if (!*stack_b)
	{
		ft_putstr("Error\n");
		return ;
	}
	res = ft_lstsize(*stack_b);
	temp = *stack_b;
	ft_lstadd_front(stack_b, ft_lstclone(ft_lstlast(*stack_b)));
	while (res > 2)
	{
		temp = temp->next;
		res--;
	}
	temp->next = NULL;
	ft_putstr("rrb\n");
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	t_list *temp;
	t_list *temp2;

	if (!*stack_a || !*stack_b)
	{
		ft_putstr("Error\n");
		return ;
	}
	temp = ft_lstlast(*stack_a);
	ft_lstadd_front(stack_a, ft_lstnew(temp->content));
	temp = temp->previous;
	temp->next = NULL;
	temp2 = ft_lstlast(*stack_b);
	ft_lstadd_front(stack_b, ft_lstnew(temp->content));
	temp2 = temp2->previous;
	temp2->next = NULL;
	ft_putstr("rrr\n");
}
