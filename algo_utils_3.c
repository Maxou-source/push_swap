/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:11:59 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/28 09:48:28 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_count_moves(int *go, t_countmoves *countmoves)
{
	countmoves->ra = 0;
	countmoves->rb = 0;
	countmoves->rra = 0;
	countmoves->rrb = 0;
	countmoves->rrr = 0;
	countmoves->rr = 0;
	if (go[0] >= 0)
		countmoves->rb = go[0];
	else if (go[0] < 0)
		countmoves->rrb = ft_abs(go[0]);
	if (go[2] >= 0)
		countmoves->ra = go[2];
	else if (go[2] < 0)
		countmoves->rra = ft_abs(go[2]);
}

void	fill_count_moves_rrr(t_countmoves *countmoves)
{
	if (countmoves->rra && countmoves->rrb)
	{
		if (countmoves->rra == countmoves->rrb)
		{
			countmoves->rrr = countmoves->rrb;
			countmoves->rra = 0;
			countmoves->rrb = 0;
			return ;
		}
		if (countmoves->rra > countmoves->rrb)
		{
			countmoves->rrr = countmoves->rrb;
			countmoves->rra = countmoves->rra - countmoves->rrr;
			countmoves->rrb = 0;
		}
		if (countmoves->rrb > countmoves->rra)
		{
			countmoves->rrr = countmoves->rra;
			countmoves->rrb = countmoves->rrb - countmoves->rrr;
			countmoves->rra = 0;
		}
		return ;
	}
}

void	fill_count_moves_rr(t_countmoves *countmoves)
{
	if (countmoves->ra && countmoves->rb)
	{
		if (countmoves->ra == countmoves->rb)
		{
			countmoves->rr = countmoves->rb;
			countmoves->ra = 0;
			countmoves->rb = 0;
			return ;
		}
		if (countmoves->ra > countmoves->rb)
		{
			countmoves->rr = countmoves->rb;
			countmoves->ra = countmoves->ra - countmoves->rr;
			countmoves->rb = 0;
		}
		if (countmoves->rb > countmoves->ra)
		{
			countmoves->rr = countmoves->ra;
			countmoves->rb = countmoves->rb - countmoves->rr;
			countmoves->ra = 0;
		}
		return ;
	}
}

void	first_at_the_top(t_pushswap *pushswap)
{
	int	tmp;

	tmp = find_min(pushswap->heada);
	if (tmp < 0)
	{
		tmp = find_number_according_to_index(pushswap->heada, tmp);
		while (pushswap->heada->first->nb != tmp)
		{
			r_rotate(pushswap->heada, 'a');
		}
	}
	else if (tmp > 0)
	{
		tmp = find_number_according_to_index(pushswap->heada, tmp);
		while (pushswap->heada->first->nb != tmp)
		{
			rotate(pushswap->heada, 'a');
		}
	}
}

void	daron_algo_4(t_pushswap *pushswap)
{
	static t_countmoves	countmoves = {0};
	int					go[3];

	while (pushswap->headb->size)
	{
		go[0] = get_min_price_index(pushswap);
		go[1] = find_number_according_to_index(pushswap->headb, go[0]);
		go[2] = find_father_2(pushswap, go[1]);
		fill_count_moves(go, &countmoves);
		fill_count_moves_rr(&countmoves);
		fill_count_moves_rrr(&countmoves);
		while (countmoves.ra--)
			rotate(pushswap->heada, 'a');
		while (countmoves.rb--)
			rotate(pushswap->headb, 'b');
		while (countmoves.rr--)
			rr(pushswap, 'r');
		while (countmoves.rra--)
			r_rotate(pushswap->heada, 'a');
		while (countmoves.rrb--)
			r_rotate(pushswap->headb, 'b');
		while (countmoves.rrr--)
			rrr(pushswap, 'r');
		push_a(pushswap);
	}
}
