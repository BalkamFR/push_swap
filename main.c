/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:02:47 by papilaz           #+#    #+#             */
/*   Updated: 2026/01/10 19:51:49 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
	{
		write(2, "Error\n", 6);
		return(0);
	}
	stack_a = list_parsed(argv, argc);
	ft_printf("-------------------------\n");
	ft_push_b(&stack_a, &stack_b);
	ft_push_b(&stack_a, &stack_b);
	ft_push_b(&stack_a, &stack_b);
	ft_push_b(&stack_a, &stack_b);

	// ft_reverse_rotate_b(&stack_b);
	// ft_rotate_b(&stack_b);
	ft_print_stack_list_2(stack_a, stack_b);
	ft_lstclear(&stack_a);
	return(1);
}
