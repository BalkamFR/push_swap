/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:35:37 by papilaz           #+#    #+#             */
/*   Updated: 2026/02/03 21:30:54 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_stack(char **list_brut)
{
	size_t	i;
	int		temp;
	t_list	*stack_created;
	int		flag_select;

	flag_select = flag_select_algo(list_brut);
	i = 0;
	stack_created = NULL;
	while (list_brut[i])
	{
		if (check_flag_tab(list_brut[i]) == 0)
		{
			temp = ft_atoi(list_brut[i]);
			ft_lstadd_back(&stack_created, ft_lstnew(temp, 0));
			stack_created->flag = flag_select;
		}
		i++;
	}
	return (stack_created);
}

void	ft_index(t_list **stack)
{
	int		count;
	t_list	*stack_current;
	t_list	*stack_compare;

	stack_compare = *stack;
	stack_current = *stack;
	while (stack_current != NULL)
	{
		count = 0;
		while (stack_compare != NULL)
		{
			if (stack_compare->content < stack_current->content)
				count++;
			stack_compare = stack_compare->next;
		}
		stack_current->index = count;
		stack_current = stack_current->next;
		stack_compare = *stack;
	}
}
