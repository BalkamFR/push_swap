/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeloyan <ajeloyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:02:47 by papilaz           #+#    #+#             */
/*   Updated: 2026/02/02 22:37:58 by ajeloyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_algo(t_list **stack_a, t_list **stack_b)
{
	float	disorder;

	disorder = compute_disorder(*stack_a);
	if ((*stack_a)->flag == 1)
	{
		selection_sort(stack_a, stack_b);
		return;
	}
	if ((*stack_a)->flag == 2)
	{
		chunk_sort(stack_a, stack_b);
		return;	
	}
	if ((*stack_a)->flag == 3)
	{
		radix_sort(stack_a, stack_b);
		return;
	}
	if ((*stack_a)->flag == 0 || (*stack_a)->flag == 4)
	{
		if (disorder < 0.2)
		{
			selection_sort(stack_a, stack_b);
			// printf("select\n");
		}
		else if (disorder < 0.5 && disorder >= 0.2)
		{
			chunk_sort(stack_a, stack_b);
			// printf("chunk\n");
		}
		else
		{
			radix_sort(stack_a, stack_b);
			// printf("radix\n");	
		}
	}
}
int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	stack_a = list_parsed(argv, argc);
	if (stack_a == NULL)
		return (0);
	// ft_printf("-------------------------\n");
	float	disorder;
	disorder = compute_disorder(stack_a);
	select_algo(&stack_a, &stack_b);
	// ft_print_stack_list_2(stack_a, stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (1);
}
