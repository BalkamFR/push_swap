/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:41:38 by papilaz           #+#    #+#             */
/*   Updated: 2026/02/09 14:43:18 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parcing_check_flag(char **argv)
{
	int	flag;
	int	i;

	i = 0;
	flag = 0;
	while (argv[i])
	{
		if (check_flag_tab(argv[i]) == 1 || check_flag_tab(argv[i]) == 2
			|| check_flag_tab(argv[i]) == 3 || check_flag_tab(argv[i]) == 4)
			flag++;
		i++;
	}
	if (flag > 1 || check_valid(argv) == 1)
		return (1);
	return (0);
}

int	parcing_check_erreur(int argc, char **argv)
{
	int	i;
	int	flag;

	if (argc <= 1)
		return (0);
	i = 0;
	flag = 0;
	if (parcing_check_flag(argv) == 1 || check_valid(argv) == 1
		|| check_doubles(argv) == 1 || check_max_min(argv) == 1)
		return (1);
	return (0);
}

t_list	*list_parsed(char **argv, int argc)
{
	char	**new;
	t_list	*newlist;

	if (argc == 2)
	{
		new = ft_split(argv[1], ' ');
		if (parcing_check_erreur(argc, new) == 1)
		{
			print_erreur("Error\n");
			return (NULL);
		}
		newlist = create_stack(new);
		ft_free_all(new);
	}
	else
	{
		if (parcing_check_erreur(argc, argv + 1) == 1)
		{
			print_erreur("Error\n");
			return (NULL);
		}
		newlist = create_stack(argv + 1);
	}
	ft_index(&newlist);
	return (newlist);
}
