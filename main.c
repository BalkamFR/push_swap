/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:02:47 by papilaz           #+#    #+#             */
/*   Updated: 2026/02/01 15:44:21 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_algo(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->flag == 1)
		selection_sort(stack_a, stack_b);
	if ((*stack_a)->flag == 2)
		chunk_sort(stack_a, stack_b);
	if ((*stack_a)->flag == 3)
		radix_sort(stack_a, stack_b);
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
	select_algo(&stack_a, &stack_b);
	ft_print_stack_list_2(stack_a, stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (1);
}
