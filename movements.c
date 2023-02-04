/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:55:15 by mparisse          #+#    #+#             */
/*   Updated: 2023/02/03 18:43:20 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	swap(t_head *head, char c)
// {
// 	int	tmp;

// 	if (!head->first || !head->last)
// 		return ;
// 	tmp = head->first->nb;
// 	head->first->nb = head->first->next->nb;
// 	head->first->next->nb = tmp;
// 	if (c == 'a')
// 		ft_printf("sa\n");
// 	else
// 		ft_printf("sb\n");
// 	fill_index_b(head);
// 	fill_index_b(head);
// }

int	r_rotate(t_head *head, char c, t_pushswap *pushswap)
{
	int		tmp;
	t_pile	*keep;
	t_pile	*res;

	tmp = head->last->nb;
	keep = head->last;
	head->last = head->last->previous;
	head->last->next = NULL;
	res = ft_calloc(sizeof(t_pile), 1);
	if (!res)
		return (free_tout(pushswap), 0);
	res->nb = tmp;
	res->previous = NULL;
	res->next = head->first;
	if (head->first)
		head->first->previous = res;
	else
		head->last = res;
	head->first = res;
	if (c == 'a')
		return (ft_printf("rra\n"), free(keep), fill_index_b(head), 1);
	else if (c == 'b')
		return (ft_printf("rrb\n"), free(keep), fill_index_b(head), 1);
	free(keep);
	return (1);
}

int	rotate(t_head *head, char c, t_pushswap *pushswap)
{
	int		tmp;
	t_pile	*keep;
	t_pile	*res;

	tmp = head->first->nb;
	keep = head->first;
	head->first = head->first->next;
	head->first->previous = NULL;
	res = ft_calloc(sizeof(t_pile), 1);
	if (!res)
		return (free_tout(pushswap), 0);
	res->nb = tmp;
	res->next = NULL;
	res->previous = head->last;
	if (head->last)
		head->last->next = res;
	else
		head->last = res;
	head->last = res;
	if (c == 'a')
		return (ft_printf("ra\n"), free(keep), fill_index_b(head), 1);
	else if (c == 'b')
		return (ft_printf("rb\n"), free(keep), fill_index_b(head), 1);
	free(keep);
	return (1);
}

// void	rrr(t_pushswap *pushswap)
// {
// 	r_rotate(pushswap->heada, 'r');
// 	r_rotate(pushswap->headb, 'r');
// 	ft_printf("rrr\n");
// 	fill_index_b(pushswap->headb);
// 	fill_index_b(pushswap->heada);
// }

// void	rr(t_pushswap *pushswap)
// {
// 	rotate(pushswap->heada, 'r');
// 	rotate(pushswap->headb, 'r');
// 	ft_printf("rr\n");
// 	fill_index_b(pushswap->headb);
// 	fill_index_b(pushswap->heada);
// }

void	push_b(t_pushswap *pushswap)
{
	int		tmp;
	t_pile	*keep;
	t_head	*heada;
	t_head	*headb;

	heada = pushswap->heada;
	headb = pushswap->headb;
	tmp = heada->first->nb;
	keep = heada->first;
	if (heada->first->next)
	{
		heada->first = heada->first->next;
		heada->first->previous = NULL;
	}
	else
	{
		headb->first = NULL;
		headb->last = NULL;
	}
	free(keep);
	add_front(headb, tmp);
	ft_printf("pb\n");
	heada->size--;
	fill_index_b(pushswap->headb);
	fill_index_b(pushswap->heada);
}

void	push_a(t_pushswap *pushswap)
{
	int		tmp;
	t_pile	*keep;
	t_head	*heada;
	t_head	*headb;

	heada = pushswap->heada;
	headb = pushswap->headb;
	tmp = headb->first->nb;
	keep = headb->first;
	if (headb->first->next)
	{
		headb->first = headb->first->next;
		headb->first->previous = NULL;
	}
	else
	{
		headb->first = NULL;
		headb->last = NULL;
	}
	free(keep);
	add_front(heada, tmp);
	headb->size--;
	ft_printf("pa\n");
	fill_index_b(pushswap->headb);
	fill_index_b(pushswap->heada);
}
