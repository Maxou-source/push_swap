/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:48:50 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/26 06:51:16 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_tab(int *tab, int size)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < size)
// 		ft_printf("[%i]%d \n",i , tab[i]);
// 	ft_printf("\n");
// }

void	print_head(t_head *head)
{
	t_pile	*tmp;

	if (!head->first)
		return ;
	tmp = head->first;
	while (tmp)
	{
		ft_printf("nb : %d       ", tmp->nb);
		ft_printf("index : %d\n", tmp->index);
		tmp = tmp->next;
	}
	ft_printf("nb d'elem: %d \n", head->size);
}
		// ft_printf("Actual: %p\n", tmp);
		// ft_printf("Prev: %p\n", tmp->previous);
		// ft_printf("Next: %p\n\n", tmp->next);