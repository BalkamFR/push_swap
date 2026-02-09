/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:02:47 by papilaz           #+#    #+#             */
/*   Updated: 2026/02/09 21:58:01 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_algo_adaptative(t_list **stack_a, t_list **stack_b,
		t_bench **bench, float disorder)
{
	if (disorder < 0.2)
		selection_sort(stack_a, stack_b, bench);
	else if (disorder < 0.5 && disorder >= 0.2)
		chunk_sort(stack_a, stack_b, bench);
	else
		radix_sort(stack_a, stack_b, bench);
}

int	select_algo(t_list **stack_a, t_list **stack_b, char **argv,
		t_bench **bench)
{
	int		flags;
	float	disorder;

	flags = (*stack_a)->flag;
	disorder = compute_disorder(*stack_a);
	if (disorder == 0 || ft_lstsize(*stack_a) == 1)
		return (print_bench((*stack_a)->flag, disorder, argv, bench));
	else if (flags == 1)
		selection_sort(stack_a, stack_b, bench);
	else if (flags == 2)
		chunk_sort(stack_a, stack_b, bench);
	else if (flags == 3)
		radix_sort(stack_a, stack_b, bench);
	else if (flags == 0 || flags == 4)
		select_algo_adaptative(stack_a, stack_b, bench, disorder);
	print_bench(flags, disorder, argv, bench);
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

void	ft_free_all_3(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	free(bench);
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_bench	*bench;
	char	**new_argv;

	stack_b = NULL;
	bench = create_list_bench();
	if (!bench)
	{
		print_erreur("Error\n");
		return (1);
	}
	stack_a = list_parsed(argv, argc);
	if (stack_a == NULL || !stack_a)
	{
		free(bench);
		return (1);
	}
	new_argv = create_args_clean(argc, argv);
	if (!new_argv)
		return (1);
	select_algo(&stack_a, &stack_b, new_argv, &bench);
	ft_free_all(new_argv);
	ft_free_all_3(&stack_a, &stack_b, bench);
	return (0);
}
