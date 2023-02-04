/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 00:30:45 by mparisse          #+#    #+#             */
/*   Updated: 2023/02/03 21:45:30 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_numbers(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_strlen(av[i]) == 1 && (av[i][j] == '-' || av[i][j] == '+'))
				return (0);
			if (ft_isdigit(av[i][j]) == 0 && av[i][j] != '+' && av[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
			// if ((av[i][j + 1] == '+' || 
			// av[i][j + 1] == '-') && (av[i][j - 1]) &&
			// 	(ft_isdigit(av[i][j]) == 1))
			// 	return (0);

int	check_list_sorted(t_head *heada)
{
	int		tmp;
	t_pile	*pile_tmp;

	pile_tmp = heada->first->next;
	while (pile_tmp)
	{
		tmp = pile_tmp->nb;
		if (pile_tmp->previous->nb > tmp)
			return (1);
		pile_tmp = pile_tmp->next;
	}
	return (0);
}

int	check_list_duplicates(t_head *heada)
{
	int		tmp;
	t_pile	*pile_tmp;
	t_pile	*other_pile_tmp;

	pile_tmp = heada->first;
	while (pile_tmp)
	{
		tmp = pile_tmp->nb;
		other_pile_tmp = pile_tmp->next;
		while (other_pile_tmp)
		{
			if (other_pile_tmp->nb == tmp)
				return (0);
			other_pile_tmp = other_pile_tmp->next;
		}
		pile_tmp = pile_tmp->next;
	}
	return (1);
}

int	parsing(int ac, char **av)
{
	char	**str;
	int		i;

	i = 1;
	while (av[i])
	{
		str = ft_split(av[i], ' ');
		if (!str || !*str)
			return (free(str), 0);
		if (check_numbers(ac, str) == 0)
		{
			free_temp(str);
			return (0);
		}
		i++;
		free_temp(str);
	}
	return (1);
}

int	last_parsing(t_pushswap *pushswap)
{
	if (check_list_sorted(pushswap->heada) == 0)
	{
		ft_putstr_fd("push_swap : the list is already sorted\n", 2);
		free_tout(pushswap);
		exit(0);
	}
	if (check_list_duplicates(pushswap->heada) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		free_tout(pushswap);
		exit(0);
	}
	return (1);
}
