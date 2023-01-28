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

void algo_for_five(t_pushswap *pushswap)
{
	int tmp;
	int *sorted_tab;

	sorted_tab = sort_tab(pushswap->heada);
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

int *sort_tab(t_head *head)
{
	t_pile *tmp;
	int *tab;
	int i;
	int j;
	int keep;

	i = 0;
	tab = malloc(sizeof(int) * head->size);
	if (!tab)
		return (0);
	if (!tab)
		return (0);
	tmp = head->first;
	while (i < head->size)
	{
		tab[i] = tmp->nb;
		tmp = tmp->next;
		i++;
	}
	i = 0;
	while (i < head->size)
	{
		j = i + 1;
		while (j < head->size)
		{
			if (tab[j] < tab[i])
			{
				keep = tab[i];
				tab[i] = tab[j];
				tab[j] = keep;
			}
			j++;
		}
		i++;
	}
	// print_tab(tab, i);
	return (tab);
}

int	ft_already_sort(t_pile *lst);

void	free_tout(t_pushswap *pushswap)
{
	t_pile	*tmp;
	t_pile	*keep;
	
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
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void start_ps(int ac, char **av)
{
	int			i;
	// int			*sorted_tab;
	// int 		size_final;
	t_head		*heada;
	t_head		*headb;
	t_pushswap	*pushswap;
	char 		**temp;
	int 		j;

	heada = 0;
	headb = 0;

	init_ldc(&heada);
	init_ldc(&headb);
	pushswap = malloc(sizeof(t_pushswap));
	if (!pushswap)
		return;
	pushswap->heada = heada;
	pushswap->headb = headb;
	i = 1;
	while (i < ac)
	{
		temp = ft_split(av[i], ' ');
		if (!temp)
		{
			free_tout(pushswap);
		}
		j = 0;
		while (temp[j])
		{
			add_back(heada, ft_atoi(temp[j]));
			j++;
		}
		i++;
		free_temp(temp);
	}
	if (check_list_sorted(heada) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	if (check_list_duplicates(heada) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	pushswap->size_final_heada = pushswap->heada->size;
	if (heada->size == 5)
	{
		algo_for_five(pushswap);
		free_tout(pushswap);
		return;
	}
	if (heada->size == 2)
	{
		r_rotate(heada, 'a');
		return ;
	}
	push_to_b_from_mediane(pushswap);
	algo_for_three(pushswap->heada);
	daron_algo_4(pushswap);
	ft_already_sort(pushswap->heada->first);
	free_tout(pushswap);
}

int	ft_already_sort(t_pile *lst)
{
	t_pile	*begin;
	t_pile	*size;
	int		i;
	int		lstsize;

	lstsize = 0;
	size = lst;
	while (size)
	{
			lstsize++;
			size = size->next;
	}
	i = 0;
	while (i < lstsize)
	{
		begin = lst;
		while (begin->next != NULL)
		{
			if (begin->nb > begin->next->nb)
				return (1);
			begin = begin->next;
		}
		i++;
	}
	return (0);
}

int parsing(int ac, char **av)
{
	char **str;
	int i;

	i = 1;
	while (av[i])
	{
		str = ft_split(av[i], ' ');
		if (!str || !*str)
			return (0);
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

int main(int ac, char **av)
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
// re organise files
// up mediane to pile b (check)
// reorganise for sorted tab
// algo de 5
