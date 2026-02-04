/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:32:18 by papilaz           #+#    #+#             */
/*   Updated: 2026/02/03 22:32:02 by papilaz          ###   ########.fr       */
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

int	check_valid(char **argv)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		count = 0;
		while (argv[i][j] && check_flag_tab(argv[i]) == 0)
		{
			if (argv[i][j] == '-' && (argv[i][j + 1] > '0' && argv[i][j
					+ 1] < '9'))
				count++;
			if ((argv[i][j] < '0' || argv[i][j] > '9') && count > 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_list	*list_parsed(char **argv, int argc)
{
	char	**new;
	t_list	*newlist;

	if (argc == 2)
	{
		new = ft_split(argv[1], ' ');
		if (check_doubles(argv) == 1 || check_valid(new) == 1)
		{
			print_erreur("Error\n");
			return (NULL);
		}
		newlist = create_stack(new);
		ft_free_all(new);
	}
	else
	{
		if (check_doubles(argv + 1) == 1 || check_valid(argv + 1) == 1)
		{
			print_erreur("Error\n");
			return (NULL);
		}
		newlist = create_stack(argv + 1);
	}
	ft_index(&newlist);
	return (newlist);
}
