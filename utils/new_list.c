/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:37:27 by papilaz           #+#    #+#             */
/*   Updated: 2026/01/07 00:44:50 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new.h"

t_list	*ft_lstnew(int	nbr)
{
	t_list	*new_node;
	int	temp;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = nbr;
	new_node->next = NULL;
	new_node->previous = NULL;
	return (new_node);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;
	t_list	*tmp_2;
	
	if (!lst || !*lst)
	{
		ft_lstadd_front(lst, new);
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp_2 = tmp;
	tmp->next = new;
	tmp = tmp->next;
	tmp->previous = tmp_2;

}
int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}


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

// void	ft_lstdelone(t_list *lst)
// {
// 	free(lst->content);
// 	free(lst);
// }