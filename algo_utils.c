/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:52:07 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/28 01:14:11 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_mediane(t_head *head, int *sorted_tab)
{
	int mediane;

	if (head->size % 2 == 0)
		mediane = sorted_tab[(head->size / 2) - 1];
	else
		mediane = sorted_tab[head->size / 2];
	// printf("la mediane est %d\n", mediane);
	return (mediane);
}

int	find_mean(t_head *head)
{
	t_pile	*tmp;
	int	sum;
	
	tmp = head->first;
	sum = 0;
	while (tmp)
	{
		sum = sum + tmp->nb;
		tmp = tmp->next;
	}
	return (sum / head->size);
}

void push_to_b_from_mediane(t_pushswap *pushswap)
{
	int mediane;
	int *sorted_tab;

	sorted_tab = sort_tab(pushswap->heada);
	mediane = find_mediane(pushswap->heada, sorted_tab);
	free(sorted_tab);
	while (pushswap->heada->size > 3)
	{
		sorted_tab = sort_tab(pushswap->heada);
		if (pushswap->heada->first->nb > mediane && pushswap->heada->first->nb != sorted_tab[2])
		{
			push_b(pushswap);
			mediane = find_mediane(pushswap->heada, sorted_tab);
		}
		else
			rotate(pushswap->heada, 'a');
		free(sorted_tab);
	}
}


void algo_for_three(t_head *head)
{
	t_pile *tmp;
	// int		*sorted_tab;

	tmp = head->last;
	// sorted_tab = sort_tab(head);
	while (tmp)
	{
		tmp = head->last;
		if ((tmp->nb < tmp->previous->nb) && (tmp->nb < head->first->nb))
			break;
		rotate(head, 'a');
	}
	if (head->first->nb > head->first->next->nb)
	{
		swap(head, 'a');
		r_rotate(head, 'a');
	}
	else
		r_rotate(head, 'a');
}
