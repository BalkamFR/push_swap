/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeloyan <ajeloyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 00:28:55 by papilaz           #+#    #+#             */
/*   Updated: 2026/02/04 20:09:59 by ajeloyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	print_erreur(ft_itoa(bench->nbr_sa));
	print_erreur("  sb:  ");
	print_erreur(ft_itoa(bench->nbr_sb));
	print_erreur("  ss:  ");
	print_erreur(ft_itoa(bench->nbr_ss));
	print_erreur("  pa:  ");
	print_erreur(ft_itoa(bench->nbr_pa));
	print_erreur("  pb:  ");
	print_erreur(ft_itoa(bench->nbr_pb));
	print_erreur("\n[bench] ra:  ");
	print_erreur(ft_itoa(bench->nbr_ra));
	print_erreur("  rb:  ");
	print_erreur(ft_itoa(bench->nbr_rb));
	print_erreur("  rr:  ");
	print_erreur(ft_itoa(bench->nbr_rr));
	print_erreur("  rra:  ");
	print_erreur(ft_itoa(bench->nbr_rra));
	print_erreur("  rrb:  ");
	print_erreur(ft_itoa(bench->nbr_rrb));
	print_erreur("  rrr:  ");
	print_erreur(ft_itoa(bench->nbr_rrr));
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
	ft_putnbr(integer);
	print_erreur(".");
	if (nbr_float < 10)
		print_erreur("0");
	ft_putnbr(nbr_float);
	print_erreur("%\n");
}

int	print_bench(int flag, float disorder, char **argv, t_bench **bench)
{
	if (check_bench(argv) == 0)
		return (0);
	print_disorder_float(disorder);
	if (flag == 1)
		print_erreur("[bench] strategy: Simple O(n2)\n");
	if (flag == 2)
		print_erreur("[bench] strategy: Medium O(n√n)\n");
	if (flag == 3)
		print_erreur("[bench] strategy: Complex O(n log n)\n");
	if (flag == 0 || flag == 4)
	{
		if (disorder < 0.2)
			print_erreur("[bench] strategy: Adaptive / O(n2)\n");
		else if (disorder < 0.5 && disorder >= 0.2)
			print_erreur("[bench] strategy: Adaptive / O(n√n)\n");
		else
			print_erreur("[bench] strategy: Adaptive / O(n log n)\n");
	}
	print_erreur("[bench] total_ops:  ");
	print_erreur(ft_itoa((*bench)->nbr_sa + (*bench)->nbr_sb + (*bench)->nbr_ss
			+ (*bench)->nbr_pa + (*bench)->nbr_pb + (*bench)->nbr_ra
			+ (*bench)->nbr_rb + (*bench)->nbr_rr + (*bench)->nbr_rra
			+ (*bench)->nbr_rrb + (*bench)->nbr_rrr));
	print_bench_operation(*bench);
	return (1);
}