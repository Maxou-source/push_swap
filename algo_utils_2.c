/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:30:18 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/29 15:30:20 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_price_index(t_pushswap *pushswap)
{
	int		min_price;
	int		index;
	t_pile	*tmp;

	tmp = pushswap->headb->first;
	min_price = calcul_prix(pushswap,
			find_father_2(pushswap, tmp->nb), tmp->index);
	index = tmp->index;
	while (tmp)
	{
		if (calcul_prix(pushswap,
				find_father_2(pushswap, tmp->nb), tmp->index) < min_price)
		{
			min_price = calcul_prix(pushswap,
					find_father_2(pushswap, tmp->nb), tmp->index);
			index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (index);
}

int	find_min(t_head *heada)
{
	t_pile	*tmp;
	int		min;
	int		index_min;

	tmp = heada->first;
	min = tmp->nb;
	index_min = tmp->index;
	while (tmp)
	{
		if (tmp->nb < min)
		{
			index_min = tmp->index;
			min = tmp->nb;
		}
		tmp = tmp->next;
	}
	return (index_min);
}

int	find_father_2(t_pushswap *pushswap, int node)
{
	t_pile	*stack_a;
	int		index_fathers[2];

	index_fathers[0] = find_min(pushswap->heada);
	stack_a = pushswap->heada->first;
	while (stack_a)
	{
		if (stack_a->nb > node)
		{
			index_fathers[0] = stack_a->index;
			index_fathers[1] = stack_a->nb;
			break ;
		}
		stack_a = stack_a->next;
	}
	while (stack_a)
	{
		if (stack_a->nb > node && stack_a->nb < index_fathers[1])
		{
			index_fathers[0] = stack_a->index;
			index_fathers[1] = stack_a->nb;
		}
		stack_a = stack_a->next;
	}
	return (index_fathers[0]);
}

int	find_number_according_to_index(t_head *head, int index)
{
	t_pile	*tmp;

	tmp = head->first;
	while (tmp)
	{
		if (tmp->index == index)
			return (tmp->nb);
		tmp = tmp->next;
	}
	return (0);
}

int	calcul_prix(t_pushswap *pushswap, int father, int son)
{
	if (father == son)
		return (abs(father));
	if (father < 0 && son < 0)
	{
		if (father < son)
			return (ft_abs(son) + (ft_abs(father) - ft_abs(son)));
		if (son < father)
			return (ft_abs(father) + (ft_abs(son) - ft_abs(father)));
	}
	if (father > 0 && son > 0)
	{
		if (father < son)
			return (father + (son - father));
		if (son < father)
			return (son + (father - son));
	}
	return (abs(father) + abs(son));
}
