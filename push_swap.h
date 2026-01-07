/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:28:21 by papilaz           #+#    #+#             */
/*   Updated: 2026/01/07 15:12:27 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int			content;
	struct s_list	*previous;
	struct s_list	*next;
}		t_list;
# include "utils/new.h"
t_list	*create_stack(char **list_brut);
void	ft_print_stack(t_list *list);
t_list	*list_parsed(char **argv, int argc);
void	ft_lstclear(t_list **lst);
#endif