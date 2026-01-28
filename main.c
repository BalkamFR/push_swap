/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armenag <armenag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:02:47 by papilaz           #+#    #+#             */
/*   Updated: 2026/01/28 00:23:38 by armenag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	// selection_sort(&stack_a, &stack_b);
	radix_sort(&stack_a, &stack_b);
	// chunk_sort(&stack_a, &stack_b);
	ft_print_stack_list_2(stack_a, stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (1);
}
