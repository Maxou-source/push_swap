/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_median.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:52:07 by mparisse          #+#    #+#             */
/*   Updated: 2023/02/03 21:26:40 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_mediane(t_head *head, int *sorted_tab)
{
	int	mediane;

	mediane = sorted_tab[(head->size / 2) - 1];
	return (mediane);
}

int	numbers_above_median(t_pushswap *pushswap, int mediane)
{
	t_pile	*tmp;

	tmp = pushswap->heada->first;
	while (tmp)
	{
		if (tmp->nb > mediane)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	push_to_b_from_mediane(t_pushswap *pushswap)
{
	int	mediane;
	int	*sorted_tab;

	sorted_tab = sort_tab(pushswap->heada);
	mediane = sorted_tab[((pushswap->heada->size / 7) * 2)];
	free(sorted_tab);
	while (pushswap->heada->size != 3)
	{
		sorted_tab = sort_tab(pushswap->heada);
		if (!sorted_tab)
			return (0);
		if (pushswap->heada->first->nb > mediane)
		{
			push_b(pushswap);
			mediane = sorted_tab[((pushswap->heada->size / 7) * 5)];
		}
		else
			rotate(pushswap->heada, 'a', pushswap);
		free(sorted_tab);
	}
	return (1);
}

void	algo_for_three(t_head *head, t_pushswap *pushswap)
{
	t_pile	*tmp;

	tmp = head->last;
	while (tmp)
	{
		tmp = head->last;
		if ((tmp->nb < tmp->previous->nb) && (tmp->nb < head->first->nb))
			break ;
		rotate(head, 'a', pushswap);
	}
	if (head->first->nb > head->first->next->nb)
	{
		swap(head, 'a');
		r_rotate(head, 'a', pushswap);
	}
	else
		r_rotate(head, 'a', pushswap);
}

void	fill_index_b(t_head *head)
{
	int		i;
	t_pile	*tmp;

	if (head->size == 0)
		return ;
	i = 0;
	tmp = head->first;
	while (i < head->size / 2 + 1)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
	i = 1;
	tmp = head->last;
	while (i < head->size / 2 + 1)
	{
		tmp->index = i * -1;
		tmp = tmp->previous;
		i++;
	}
}
