/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeloyan <ajeloyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:37:52 by papilaz           #+#    #+#             */
/*   Updated: 2026/02/04 17:03:24 by ajeloyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct list
{
	int				flag;
	int				disorder;
	int				nbr_sa;
	int				nbr_sb;
	int				nbr_ss;
	int				nbr_pa;
	int				nbr_pb;
	int				nbr_ra;
	int				nbr_rb;
	int				nbr_rr;
	int				nbr_rra;
	int				nbr_rrb;
	int				nbr_rrr;
}					t_bench;

typedef struct s_list
{
	int				content;
	int				index;
	int				flag;
	struct s_list	*next;
}					t_list;

int					ft_putstr(char *tab);
int					ft_putchar(char c);
int					ft_putnbr(int nb);
long				ft_atoi(const char *nptr);
char				**ft_split(char *s, char c);
int					ft_strcmp_ps(char *str, char *str2);
void				ft_free_all(char **tab);
t_list				*ft_lstnew(int nbr, int index_nbr);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
void				ft_lstclear(t_list **lst);
t_list				*ft_lstlast(t_list *lst);

t_list				*list_parsed(char **argv, int argc);
t_list				*create_stack(char **list_brut);
t_list				*ft_lstclone(t_list *node);

void				ft_ss(t_list *stack_a, t_list *stack_b, t_bench **bench);
void				ft_swap_a(t_list *stack_a, t_bench **bench);
void				ft_swap_b(t_list *stack_b, t_bench **bench);
void				ft_push_b(t_list **stack_a, t_list **stack_b,
						t_bench **bench);
void				ft_push_a(t_list **stack_a, t_list **stack_b,
						t_bench **bench);
void				ft_rotate_a(t_list **stack_a, t_bench **bench);
void				ft_rotate_b(t_list **stack_b, t_bench **bench);
void				ft_rr(t_list **stack_a, t_list **stack_b, t_bench **bench);
void				ft_reverse_rotate_a(t_list **stack_a, t_bench **bench);
void				ft_reverse_rotate_b(t_list **stack_b, t_bench **bench);
void				ft_rrr(t_list **stack_a, t_list **stack_b, t_bench **bench);

void				selection_sort(t_list **stack_a, t_list **stack_b,
						t_bench **bench);
void				chunk_sort(t_list **stack_a, t_list **stack_b,
						t_bench **bench);
void				radix_sort(t_list **stack_a, t_list **stack_b,
						t_bench **bench);

int					check_min_pos(t_list *stack_a, int res);
int					check_min(t_list *stack_a);
void				ft_index(t_list **stack);
void				sort_binary(t_list **stack_a, t_list **stack_b, int move_on,
						t_bench **bench);

int					check_flag_tab(char *tab);
int					flag_select_algo(char **argv);

float				compute_disorder(t_list *stack_a);
int					print_bench(int flag, float disorder, char **argv,
						t_bench **bench);
int					check_bench(char **argv);

char				*ft_itoa(long int n);
void				print_erreur(char *tab);
int					parcing_check_erreur(int argc, char **argv);
#endif