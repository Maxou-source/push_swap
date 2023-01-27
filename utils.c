/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:48:16 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/20 00:13:38 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_back(t_head *head, int value)
{
	t_pile	*res;

	res = ft_calloc(sizeof(t_pile), 1);
	if (!res)
		return ;
	res->nb = value;
	res->next = NULL;
	res->previous = head->last;
	if (head->last)
		head->last->next = res;
	else
	{
		head->last = res;
		head->first = res;
	}
	head->last = res;
	head->size++;
}

void	add_front(t_head *head, int value)
{
	t_pile	*nouv;

	nouv = ft_calloc(sizeof(t_pile), 1);
	if (!nouv)
		return ;
	nouv->nb = value;
	nouv->previous = NULL;
	nouv->next = head->first;
	if (head->first)
		head->first->previous = nouv;
	else
	{
		head->first = nouv;
		head->last = nouv;
	}
	head->first = nouv;
	head->size++;
}

t_pile	*create_elem(int nb_content)
{
	t_pile	*res;

	res = malloc(sizeof(t_pile));
	if (!res)
		return (NULL);
	res->nb = nb_content;
	res->next = NULL;
	res->previous = NULL;
	return (res);
}

void	init_ldc(t_head **head)
{
	*head = malloc(sizeof(t_head));
	if (!*head)
		return ;
	(*head)->first = NULL;
	(*head)->last = NULL;
	(*head)->size = 0;
}
