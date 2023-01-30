/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:24:16 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/30 20:24:27 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_tab(t_head *head)
{
	t_pile	*tmp;
	int		*tab;
	int		i[2];

	tab = malloc(sizeof(int) * head->size);
	if (!tab)
		return (0);
	tmp = head->first;
	i[0] = -1;
	while (++i[0] < head->size)
	{
		tab[i[0]] = tmp->nb;
		tmp = tmp->next;
	}
	i[0] = -1;
	while (++i[0] < head->size)
	{
		i[1] = i[0];
		while (++i[1] < head->size)
		{
			if (tab[i[1]] < tab[i[0]])
				ft_swap(&tab[i[0]], &tab[i[1]]);
		}
	}
	return (tab);
}

int	fill_list(int ac, char **av, t_pushswap *pushswap)
{
	int		i;
	char	**temp;
	int		j;

	i = 0;
	while (++i < ac)
	{
		temp = ft_split(av[i], ' ');
		if (!temp)
			return (free_tout(pushswap), 0);
		j = -1;
		while (temp[++j])
		{
			if (!add_back(pushswap->heada, ft_atoi(temp[j])))
			{
				free_temp(temp);
				free_tout(pushswap);
				exit(0);
			}
		}
		free_temp(temp);
	}
	return (1);
}
