/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <papilaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:46:45 by papilaz           #+#    #+#             */
/*   Updated: 2026/02/09 21:26:24 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				flag;
	struct s_list	*next;
}					t_list;

typedef struct s_bench
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

long				ft_atoi(const char *nptr);
char				*ft_itoa(long int n);
char				**ft_split(char *s, char c);
int					ft_strcmp_ps(char *str, char *str2);
int					ft_putchar(char c);
int					ft_putstr(char *tab);
int					ft_putnbr(int nb);
void				ft_free_all(char **tab);

t_list				*ft_lstnew(int nbr, int index_nbr);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstclone(t_list *node);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst);
int					ft_lstsize(t_list *lst);

int					parcing_check_erreur(int argc, char **argv);
int					check_valid(char **argv);
int					check_max_min(char **argv);
int					check_doubles(char **argv);
void				print_erreur(char *tab);

t_list				*list_parsed(char **argv, int argc);
t_list				*create_stack(char **list_brut);

void				ft_swap_a(t_list *stack_a, t_bench **bench);
void				ft_swap_b(t_list *stack_b, t_bench **bench);
void				ft_ss(t_list *stack_a, t_list *stack_b, t_bench **bench);

void				ft_push_a(t_list **stack_a, t_list **stack_b,
						t_bench **bench);
void				ft_push_b(t_list **stack_a, t_list **stack_b,
						t_bench **bench);

void				ft_rotate_a(t_list **stack_a, t_bench **bench);
void				ft_rotate_b(t_list **stack_b, t_bench **bench);
void				ft_rr(t_list **stack_a, t_list **stack_b, t_bench **bench);

void				ft_reverse_rotate_a(t_list **stack_a, t_bench **bench);
void				ft_reverse_rotate_b(t_list **stack_b, t_bench **bench);
void				ft_rrr(t_list **stack_a, t_list **stack_b, t_bench **bench);

void				ft_index(t_list **stack);
int					check_min_pos(t_list *stack_a, int res);

void				selection_sort(t_list **stack_a, t_list **stack_b,
						t_bench **bench);
void				chunk_sort(t_list **stack_a, t_list **stack_b,
						t_bench **bench);
void				radix_sort(t_list **stack_a, t_list **stack_b,
						t_bench **bench);

int					check_flag_tab(char *tab);
int					flag_select_algo(char **argv);
float				compute_disorder(t_list *stack_a);
int					print_bench(int flag, float disorder, char **argv,
						t_bench **bench);

void				print_disorder_float(float nbr);
void				print_erreur(char *tab);
int					print_bench(int flag, float disorder, char **argv,
						t_bench **bench);
void				print_itoa_safe(int n);
void				print_bench_operation(t_bench *bench);
int					total_ops(t_bench *b);
int					check_bench(char **argv);
void				print_strategy(int flag, float disorder);
int					ft_len_args(int ac, char **av);
char				**create_args_clean(int argc, char **argv);
#endif