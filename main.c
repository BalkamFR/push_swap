/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:02:47 by papilaz           #+#    #+#             */
/*   Updated: 2026/01/07 20:17:53 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	
	stack_b = NULL;
	if (argc < 1)
	{
		write(2, "Error\n", 6);
		return(0);
	}
	stack_a = list_parsed(argv, argc);
	ft_push_b(&stack_a, &stack_b);
	ft_push_a(&stack_a, &stack_b);
	ft_print_stack_list(stack_a, stack_b);
	
	ft_lstclear(&stack_a);
	return(1);
}
