/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 00:58:49 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/27 13:39:59 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include <stdio.h>

typedef struct s_pile
{
	struct s_pile	*previous;
	int				nb;
	struct s_pile	*next;
	int				index;
}	t_pile;

typedef struct s_head
{
	t_pile	*first;
	t_pile	*last;
	int		size;
}	t_head;

typedef struct t_pushswap
{
	t_head	*heada;
	t_head	*headb;
	int		size_final_heada;
	int		min_cout_value;
}	t_pushswap;

typedef struct s_countmoves
{
	int	count_ra;
	int	count_rra;
	int	count_rb;
	int	count_rrb;
	int	count_rr;
	int	count_rrr;
}	t_countmoves;

int	*sort_tab(t_head* head);

//parsing 
int		check_numbers(int ac, char **av);
int		check_list_sorted(t_head *heada);
int		check_list_duplicates(t_head *heada);

void	add_front(t_head *head, int value);
void	add_back(t_head *head, int value);

// movements 
void	swap(t_head *head, char c);
void	r_rotate(t_head	*head, char c);
void	rotate(t_head *head, char c);
void	swap_swap(t_pushswap *pushwap);
void	push_b(t_pushswap *pushswap);
void	push_a(t_pushswap *pushswap);
void rr(t_pushswap *pushswap);
void rrr(t_pushswap *pushswap);

// utils
void	add_back(t_head *head, int value);
void	add_front(t_head *head, int value);
t_pile	*create_elem(int nb_content);
void	init_ldc(t_head **head);

// algo utils
// int		*sort_tab(int	*tab, int size);
int		find_mediane(t_head *head, int	*sorted_tab);
void	push_to_b_from_mediane(t_pushswap *pushswap);
void	algo_for_three(t_head *head);
void	daron_algo(t_pushswap *pushswap);
void	daron_algo_2(t_pushswap *t_pushswap, int *sorted_tab);
void daron_algo_3(t_pushswap *pushswap);

// algo utils 2
void	daron_algo_4(t_pushswap *pushswap);
int find_father(t_pushswap *pushswap, t_pile *node);

//tmp utils
void	print_tab(int *tab, int size);
void	print_head(t_head *head);
void	fill_index_b(t_head *head);

#endif