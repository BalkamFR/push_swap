/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:02:47 by papilaz           #+#    #+#             */
/*   Updated: 2026/02/04 17:57:58 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	select_algo(t_list **stack_a, t_list **stack_b, char **argv,
		t_bench **bench)
{
	float	disorder;
	int		flag_select;

	flag_select = (*stack_a)->flag;
	disorder = compute_disorder(*stack_a);
	if (disorder == 0 || ft_lstsize(*stack_a) == 1)
		return (print_bench(flag_select, disorder, argv, bench));
	if (flag_select == 1)
		selection_sort(stack_a, stack_b, bench);
	if (flag_select == 2)
		chunk_sort(stack_a, stack_b, bench);
	if (flag_select == 3)
		radix_sort(stack_a, stack_b, bench);
	if (flag_select == 0 || flag_select == 4)
	{
		if (disorder < 0.2)
			selection_sort(stack_a, stack_b, bench);
		else if (disorder < 0.5 && disorder >= 0.2)
			chunk_sort(stack_a, stack_b, bench);
		else
			radix_sort(stack_a, stack_b, bench);
	}
	print_bench(flag_select, disorder, argv, bench);
	free(*bench);
	return (0);
}

t_bench	*create_list_bench(void)
{
	t_bench	*bench;

	bench = malloc(sizeof(t_bench));
	if (!bench)
		return (0);
	bench->flag = 0;
	bench->disorder = 0;
	bench->nbr_sa = 0;
	bench->nbr_sb = 0;
	bench->nbr_ss = 0;
	bench->nbr_pa = 0;
	bench->nbr_pb = 0;
	bench->nbr_ra = 0;
	bench->nbr_rb = 0;
	bench->nbr_rr = 0;
	bench->nbr_rra = 0;
	bench->nbr_rrb = 0;
	bench->nbr_rrr = 0;
	return (bench);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_bench	*bench;
	float	disorder;

	stack_b = NULL;
	bench = create_list_bench();
	if (!bench)
	{
		print_erreur("Error\n");
		return (0);
	}
	stack_a = list_parsed(argv, argc);
	if (stack_a == NULL)
	{
		free(bench);
		return (0);
	}
	disorder = compute_disorder(stack_a);
	select_algo(&stack_a, &stack_b, argv, &bench);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (1);
}
