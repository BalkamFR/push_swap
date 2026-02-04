/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 21:35:53 by papilaz           #+#    #+#             */
/*   Updated: 2026/02/03 21:37:10 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;
	t_list	*next;

	tmp = *lst;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*lst = NULL;
}

t_list	*ft_lstlast(t_list *lst)
{
	int		size;
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	size = ft_lstsize(lst);
	while (i < size - 1 && tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
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
