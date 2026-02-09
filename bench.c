/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 00:28:55 by papilaz           #+#    #+#             */
/*   Updated: 2026/02/09 16:28:34 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_itoa_safe(int n)
{
	char	*str;

	str = ft_itoa(n);
	if (!str)
		return ;
	print_erreur(str);
	free(str);
}

static int	check_bench(char **argv)
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

void	print_erreur(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		write(2, &tab[i], 1);
		i++;
	}
}

static void	print_bench_operation(t_bench *bench)
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

void	print_disorder_float(float nbr)
{
	float	percent;
	int		integer;
	int		nbr_float;

	percent = nbr * 100;
	integer = (int)percent;
	nbr_float = (int)((percent - integer) * 100 + 0.0001);
	print_erreur("[bench] disorder: ");
	print_itoa_safe(integer);
	print_erreur(".");
	if (nbr_float < 10)
		print_erreur("0");
	print_itoa_safe(nbr_float);
	print_erreur("%\n");
}

static void	print_strategy(int flag, float disorder)
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

static int	total_ops(t_bench *b)
{
	return (b->nbr_sa + b->nbr_sb + b->nbr_ss + b->nbr_pa + b->nbr_pb
		+ b->nbr_ra + b->nbr_rb + b->nbr_rr + b->nbr_rra + b->nbr_rrb
		+ b->nbr_rrr);
}

int	print_bench(int flag, float disorder, char **argv, t_bench **bench)
{
	if (check_bench(argv) == 0)
		return (0);
	print_disorder_float(disorder);
	print_strategy(flag, disorder);
	print_erreur("[bench] total_ops:  ");
	print_itoa_safe(total_ops(*bench));
	print_bench_operation(*bench);
	return (1);
}
