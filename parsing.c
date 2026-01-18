/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeloyan <ajeloyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:32:18 by papilaz           #+#    #+#             */
/*   Updated: 2026/01/18 18:30:30 by ajeloyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			{
				write(2, "Error\n", 6);
				return (1);
			}
			a++;
		}
		i++;
	}
	return (0);
}
int check_valid(char **argv)
{
	int i;
	int	count;
	int j;

	i = 0;
	count = 0;
	while(argv[i])
	{
		j = 0;
		count = 0;
		while(argv[i][j])
		{
			if(argv[i][j] == '-')
				count++;
			if ((argv[i][j] < '0' || argv[i][j] > '9') && (count > 1))
				return(1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_free_all(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	
}


t_list	*list_parsed(char **argv, int argc)
{
	char **new;
	t_list *newlist;

	if (argc == 2)
	{
		new = ft_split(argv[1], ' ');
		if (check_doubles(argv) == 1 || check_valid(new) == 1)
			return (NULL);
		newlist = create_stack(new);
		ft_free_all(new);
	}
	else
	{
		if (check_doubles(argv + 1) == 1 || check_valid(argv + 1) == 1)
			return (NULL);
		newlist = create_stack(argv + 1);
	}
	ft_index(&newlist);
	return (newlist);
}

