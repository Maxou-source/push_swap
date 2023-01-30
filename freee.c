/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freee.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:58:41 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/30 12:58:58 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tout(t_pushswap *pushswap)
{
	t_pile	*tmp;
	t_pile	*keep;

	tmp = pushswap->headb->first;
	if (pushswap->headb->first)
	{
		while (tmp)
		{
			keep = tmp->next;
			free(tmp);
			tmp = keep;
		}		
	}
	tmp = pushswap->heada->first;
	while (tmp)
	{
		keep = tmp->next;
		free(tmp);
		tmp = keep;
	}
	free(pushswap->headb);
	free(pushswap->heada);
	free(pushswap);
}

void	free_temp(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
