/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:29:08 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/30 16:29:25 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_a_checker(t_pushswap *pushswap)
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
	fill_index_b(pushswap->headb);
	fill_index_b(pushswap->heada);
}

void	push_b_checker(t_pushswap *pushswap)
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
	heada->size--;
	fill_index_b(pushswap->headb);
	fill_index_b(pushswap->heada);
}
