/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:31:06 by mparisse          #+#    #+#             */
/*   Updated: 2023/02/03 21:30:21 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_pushswap *pushswap, char c)
{
	r_rotate(pushswap->heada, 'r', pushswap);
	r_rotate(pushswap->headb, 'r', pushswap);
	if (c == 'r')
		ft_printf("rrr\n");
	fill_index_b(pushswap->headb);
	fill_index_b(pushswap->heada);
}

void	rr(t_pushswap *pushswap, char c)
{
	rotate(pushswap->heada, 'r', pushswap);
	rotate(pushswap->headb, 'r', pushswap);
	if (c == 'r')
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
	else if (c == 'b')
		ft_printf("sb\n");
	fill_index_b(head);
	fill_index_b(head);
}

void	swap_swap(t_pushswap *pushswap, char c)
{
	swap(pushswap->headb, 'r');
	swap(pushswap->heada, 'r');
	if (c == 's')
		ft_printf("ss\n");
	fill_index_b(pushswap->heada);
	fill_index_b(pushswap->headb);
}
