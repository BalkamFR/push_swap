/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:16:10 by papilaz           #+#    #+#             */
/*   Updated: 2026/02/09 21:34:41 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_concat_args(int ac, char **av)
{
	int		i;
	int		j;
	int		k;
	long	len;
	char	*s;

	len = ft_len_args(ac, av);
	i = 0;
	s = malloc(sizeof(char) * (len + ac));
	if (!s)
		return (NULL);
	k = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
			s[k++] = av[i][j++];
		if (i < ac - 1)
			s[k++] = ' ';
	}
	s[k] = '\0';
	return (s);
}

int	parcing_check_flag(char **argv)
{
	int	flag;
	int	i;

	i = -1;
	flag = 0;
	if (!argv)
		return (1);
	while (argv[++i])
	{
		if (check_flag_tab(argv[i]) >= 1 && check_flag_tab(argv[i]) <= 4)
			flag++;
	}
	if (flag > 1 || check_valid(argv) == 1)
		return (1);
	return (0);
}

int	parcing_check_erreur(int argc, char **argv)
{
	if (!argv)
		return (1);
	(void)argc;
	if (parcing_check_flag(argv) == 1 || check_valid(argv) == 1
		|| check_doubles(argv) == 1 || check_max_min(argv) == 1)
		return (1);
	return (0);
}

char	**create_args_clean(int argc, char **argv)
{
	char	*str;
	char	**new;

	str = ft_concat_args(argc, argv);
	if (!str)
		return (NULL);
	new = ft_split(str, ' ');
	if (!new)
		return (NULL);
	free(str);
	return (new);
}

t_list	*list_parsed(char **argv, int argc)
{
	t_list	*list;
	char	**new;

	list = NULL;
	new = NULL;
	new = create_args_clean(argc, argv);
	if (!new || parcing_check_erreur(0, new) == 1)
	{
		if (new)
			ft_free_all(new);
		print_erreur("Error\n");
		return (NULL);
	}
	list = create_stack(new);
	if (!list)
	{
		ft_free_all(new);
		return (NULL);
	}
	ft_free_all(new);
	ft_index(&list);
	return (list);
}
