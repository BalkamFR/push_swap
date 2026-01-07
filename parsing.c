/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:32:18 by papilaz           #+#    #+#             */
/*   Updated: 2026/01/07 00:06:07 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*list_parsed(char **argv, int argc)
{
	char	**new;
	t_list	*newlist;

	if (argc == 2)
	{
		new = ft_split(argv[1], ' ');
		newlist = create_stack(new);
		free(new);
	}
	else
		newlist = create_stack(argv + 1);
	return (newlist);
}
