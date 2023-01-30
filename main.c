/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psh_swp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 00:55:35 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/28 00:56:11 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_for_five(t_pushswap *pushswap)
{
	int	tmp;
	int	*sorted_tab;

	sorted_tab = sort_tab(pushswap->heada);
	if (!sorted_tab)
	{
		free_tout(pushswap);
		exit(0);
	}
	while (pushswap->heada->size != 3)
	{
		tmp = pushswap->heada->first->nb;
		if (tmp == sorted_tab[0] || tmp == sorted_tab[1])
			push_b(pushswap);
		else
			rotate(pushswap->heada, 'a');
	}
	algo_for_three(pushswap->heada);
	if (pushswap->heada->first->nb > pushswap->heada->first->next->nb)
		swap(pushswap->headb, 'b');
	push_a(pushswap);
	push_a(pushswap);
	free(sorted_tab);
}

// int	*sort_tab(t_head *head)
// {
// 	t_pile	*tmp;
// 	int		*tab;
// 	int		i[2];

// 	tab = malloc(sizeof(int) * head->size);
// 	if (!tab)
// 		return (0);
// 	tmp = head->first;
// 	i[0] = -1;
// 	while (++i[0] < head->size)
// 	{
// 		tab[i[0]] = tmp->nb;
// 		tmp = tmp->next;
// 	}
// 	i[0] = -1;
// 	while (++i[0] < head->size)
// 	{
// 		i[1] = i[0];
// 		while (++i[1] < head->size)
// 		{
// 			if (tab[i[1]] < tab[i[0]])
// 				ft_swap(&tab[i[0]], &tab[i[1]]);
// 		}
// 	}
// 	return (tab);
// }

// int	fill_list(int ac, char **av, t_pushswap *pushswap)
// {
// 	int		i;
// 	char	**temp;
// 	int		j;

// 	i = 0;
// 	while (++i < ac)
// 	{
// 		temp = ft_split(av[i], ' ');
// 		if (!temp)
// 			return (free_tout(pushswap), 0);
// 		j = -1;
// 		while (temp[++j])
// 		{
// 			if (!add_back(pushswap->heada, ft_atoi(temp[j])))
// 			{
// 				free_temp(temp);
// 				free_tout(pushswap);
// 				exit(0);
// 			}
// 		}
// 		free_temp(temp);
// 	}
// 	return (1);
// }

void	start_ps(int ac, char **av)
{
	t_pushswap	*pushswap;

	pushswap = 0;
	pushswap = init_pushswap_ldc(pushswap);
	if (!fill_list(ac, av, pushswap))
		return ;
	if (last_parsing(pushswap) == 0)
		return ;
	if (pushswap->heada->size == 5)
	{
		algo_for_five(pushswap);
		free_tout(pushswap);
		return ;
	}
	if (pushswap->heada->size == 2)
	{
		r_rotate(pushswap->heada, 'a');
		return ;
	}
	if (!push_to_b_from_mediane(pushswap))
		free_tout(pushswap);
	algo_for_three(pushswap->heada);
	daron_algo_4(pushswap);
	first_at_the_top(pushswap);
	free_tout(pushswap);
}

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		if (parsing(ac, av) == 0)
		{
			return (ft_putstr_fd("Error\n", 2), 0);
		}
		else
		{
			start_ps(ac, av);
		}
	}
	else
		return (0);
}

// parsing avant transformation en liste (check)
// nombre 0 ou 1 (check)
// relink Makefile (check)
// only one argument simple Error (check)
// re organise files (check)
// up mediane to pile b (check)
// reorganise for sorted tab (check)
// algo de 5 (check)

// init pushswap dans utils (check)
// raccorucir startps (check)
// reorganise files (check)
// revierfier malloc 
