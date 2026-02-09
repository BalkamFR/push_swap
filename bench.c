/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 00:28:55 by papilaz           #+#    #+#             */
/*   Updated: 2026/02/09 21:04:36 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_itoa_safe(int n)
{
	char	*str;

	str = ft_itoa(n);
	if (!str)
		return ;
	print_erreur(str);
	free(str);
}

int	check_bench(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_strcmp_ps(argv[i], "--bench") == 1)
			return (1);
		i++;
	}
	return (0);
}

void	print_bench_operation(t_bench *bench)
{
	print_erreur("\n[bench] sa:  ");
	print_itoa_safe(bench->nbr_sa);
	print_erreur("  sb:  ");
	print_itoa_safe(bench->nbr_sb);
	print_erreur("  ss:  ");
	print_itoa_safe(bench->nbr_ss);
	print_erreur("  pa:  ");
	print_itoa_safe(bench->nbr_pa);
	print_erreur("  pb:  ");
	print_itoa_safe(bench->nbr_pb);
	print_erreur("\n[bench] ra:  ");
	print_itoa_safe(bench->nbr_ra);
	print_erreur("  rb:  ");
	print_itoa_safe(bench->nbr_rb);
	print_erreur("  rr:  ");
	print_itoa_safe(bench->nbr_rr);
	print_erreur("  rra:  ");
	print_itoa_safe(bench->nbr_rra);
	print_erreur("  rrb:  ");
	print_itoa_safe(bench->nbr_rrb);
	print_erreur("  rrr:  ");
	print_itoa_safe(bench->nbr_rrr);
	print_erreur("\n");
}

void	print_strategy(int flag, float disorder)
{
	if (flag == 1)
		print_erreur("[bench] strategy: Simple O(n2)\n");
	else if (flag == 2)
		print_erreur("[bench] strategy: Medium O(n√n)\n");
	else if (flag == 3)
		print_erreur("[bench] strategy: Complex O(n log n)\n");
	else if (disorder < 0.2)
		print_erreur("[bench] strategy: Adaptive / O(n2)\n");
	else if (disorder < 0.5)
		print_erreur("[bench] strategy: Adaptive / O(n√n)\n");
	else
		print_erreur("[bench] strategy: Adaptive / O(n log n)\n");
}

int	total_ops(t_bench *b)
{
	return (b->nbr_sa + b->nbr_sb + b->nbr_ss + b->nbr_pa + b->nbr_pb
		+ b->nbr_ra + b->nbr_rb + b->nbr_rr + b->nbr_rra + b->nbr_rrb
		+ b->nbr_rrr);
}
