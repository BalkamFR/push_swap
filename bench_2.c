/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 18:10:12 by papilaz           #+#    #+#             */
/*   Updated: 2026/02/09 21:45:35 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_len_args(int ac, char **av)
{
	int	j;
	int	len;
	int	i;

	i = 1;
	len = 0;
	j = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j++])
			len++;
		i++;
	}
	return (len);
}
