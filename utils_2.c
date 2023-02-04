/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:24:16 by mparisse          #+#    #+#             */
/*   Updated: 2023/02/04 13:59:56 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

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

int	atoi_return(int res, int negatif)
{
	if (negatif == -1 && res == (MAXOU_INT_MIN * -1) - 1)
		return (INT_MIN);
	return (res * negatif);
}

int	ft_atoi_special(const char *str, char **temp, t_pushswap *pushswap)
{
	long	res;
	int		negatif;

	res = 0;
	negatif = 1;
	while (ft_is_space(*str) == 1)
		str++;
	if (*str == '+' || *str == '-')
	{
		negatif = ((*str == '-') * -1) + ((*str == '+') * 1);
		str++;
	}
	if (*str == '+' || *str == '-')
		return (ft_putstr_fd("Error\n", 1), exit(0), 0);
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - 48);
		str++;
		if (res > MAXOU_INT_MIN * -1)
			return (ft_printf("Error\n", 1), exit(0), 0);
	}
	if (*str)
		return (ft_putstr_fd("Error\n", 1), free_temp(temp),
			free_tout(pushswap), exit(0), 0);
	return (atoi_return(res, negatif));
}
// res negatif temp 

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
			if (!add_back(pushswap->heada, ft_atoi_special(temp[j],
						temp, pushswap)))
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
