/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:35:37 by papilaz           #+#    #+#             */
/*   Updated: 2026/01/09 17:33:47 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_stack(char **list_brut)
{
	size_t	i;
	int		temp;
	t_list	*stack_created;

	i = 0;
	stack_created = NULL;
	while (list_brut[i])
	{
		temp = ft_atoi(list_brut[i]);
		ft_lstadd_back(&stack_created, ft_lstnew(temp));
		i++;
	}
	return (stack_created);
}

void	ft_print_stack(t_list *list)
{
	t_list	*temp;

	if (!list || list == NULL)
	{
		ft_putstr("list vide");
		return ;
	}
	temp = list;
	while (temp)
	{
		ft_putnbr(temp->content);
		ft_putstr(" ");
		temp = temp->next;
	}
}

void	ft_print_stack_list(t_list *list, t_list *list2)
{
	int	i;

	i = 0;
	ft_printf("--------------\n");
	while (list || list2)
	{
		ft_printf("line (%d)\n", i);
		if (list)
		{
			ft_printf("   a : %d \n", list->content);
			list = list->next;
		}
		else
			ft_printf("   a : (vide)\n");
		if (list2)
		{
			ft_printf("   b : %d", list2->content);
			list2 = list2->next;
		}
		else
			ft_printf("   b : (vide)");
		ft_printf("\n--------------\n");
		i++;
	}
}

void	ft_print_stack_list_2(t_list *list, t_list *list2)
{

	ft_printf("-------------------------\n");
	ft_printf("\nlist a : ");
	ft_print_stack(list);
	ft_printf("\nlist b : ");
	ft_print_stack(list2);
	ft_printf("\n\n-------------------------\n");
}