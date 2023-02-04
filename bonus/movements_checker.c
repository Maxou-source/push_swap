/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:29:08 by mparisse          #+#    #+#             */
/*   Updated: 2023/02/04 13:40:27 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	push_a_checker(t_pushswap *pushswap)
{
	int		tmp;
	t_pile	*keep;
	t_head	*heada;
	t_head	*headb;

	heada = pushswap->heada;
	headb = pushswap->headb;
	if (!headb->first)
		return (0);
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
	return (fill_index_b(pushswap->heada), fill_index_b(pushswap->headb), 0);
}

int	push_b_checker(t_pushswap *pushswap)
{
	int		tmp;
	t_pile	*keep;
	t_head	*heada;
	t_head	*headb;

	if (!pushswap->headb->first)
		return (0);
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
	return (fill_index_b(pushswap->heada), fill_index_b(pushswap->headb), 0);
}
