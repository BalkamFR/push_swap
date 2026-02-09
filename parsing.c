/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:32:18 by papilaz           #+#    #+#             */
/*   Updated: 2026/02/09 16:21:33 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_flag_tab(char *tab)
{
	if (!tab)
		return (-1);
	if (ft_strcmp_ps(tab, "--simple"))
		return (1);
	if (ft_strcmp_ps(tab, "--medium"))
		return (2);
	if (ft_strcmp_ps(tab, "--complex"))
		return (3);
	if (ft_strcmp_ps(tab, "--adaptive"))
		return (4);
	if (ft_strcmp_ps(tab, "--bench"))
		return (5);
	return (0);
}

int	flag_select_algo(char **argv)
{
	int	flag;
	int	i;

	i = 0;
	flag = 0;
	while (argv[i])
	{
		if (flag == 0 && check_flag_tab(argv[i]) != 5)
			flag = check_flag_tab(argv[i]);
		i++;
	}
	return (flag);
}

int	check_doubles(char **argv)
{
	int	i;
	int	a;

	i = 0;
	while (argv[i])
	{
		a = i + 1;
		while (argv[a])
		{
			if (ft_strcmp_ps(argv[i], argv[a]) == 1)
				return (1);
			a++;
		}
		i++;
	}
	return (0);
}

int	check_max_min(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if ((ft_atoi(argv[i]) < -2147483648) || (ft_atoi(argv[i]) > 2147483647))
			return (1);
		i++;
	}
	return (0);
}

int	check_valid(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] && check_flag_tab(argv[i]) == 0)
		{
			if (argv[i][j] == '-' && (argv[i][j + 1] < '0' || argv[i][j
					+ 1] > '9'))
				return (1);
			else if (argv[i][j] >= '0' && argv[i][j] <= '9' && (argv[i][j
					+ 1] < '0' || argv[i][j + 1] > '9') && argv[i][j
				+ 1] != '\0')
				return (1);
			else if ((argv[i][j] < '0' || argv[i][j] > '9')
				&& argv[i][j] != '-')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
