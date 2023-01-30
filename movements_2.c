/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:31:06 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/30 13:31:07 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_pushswap *pushswap)
{
	r_rotate(pushswap->heada, 'r');
	r_rotate(pushswap->headb, 'r');
	ft_printf("rrr\n");
	fill_index_b(pushswap->headb);
	fill_index_b(pushswap->heada);
}

void	rr(t_pushswap *pushswap)
{
	rotate(pushswap->heada, 'r');
	rotate(pushswap->headb, 'r');
	ft_printf("rr\n");
	fill_index_b(pushswap->headb);
	fill_index_b(pushswap->heada);
}

void	swap(t_head *head, char c)
{
	int	tmp;

	if (!head->first || !head->last)
		return ;
	tmp = head->first->nb;
	head->first->nb = head->first->next->nb;
	head->first->next->nb = tmp;
	if (c == 'a')
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
	fill_index_b(head);
	fill_index_b(head);
}
