/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:40:45 by mparisse          #+#    #+#             */
/*   Updated: 2023/02/04 13:42:05 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "get_next_line/get_next_line.h"

int	parsing_checker(char *str, t_pushswap *pushswap)
{
	if (!ft_strcmp(str, "ra\n"))
		return (rotate(pushswap->heada, 'r', pushswap), 1);
	if (!ft_strcmp(str, "rra\n"))
		return (r_rotate(pushswap->heada, 'r', pushswap), 1);
	if (!ft_strcmp(str, "rb\n"))
		return (rotate(pushswap->headb, 'r', pushswap), 1);
	if (!ft_strcmp(str, "rrb\n"))
		return (r_rotate(pushswap->headb, 'r', pushswap), 1);
	if (!ft_strcmp(str, "rrr\n"))
		return (rrr(pushswap, 'f'), 1);
	if (!ft_strcmp(str, "rr\n"))
		return (rr(pushswap, 'f'), 1);
	if (!ft_strcmp(str, "sb\n"))
		return (swap(pushswap->headb, 'r'), 1);
	if (!ft_strcmp(str, "sa\n"))
		return (swap(pushswap->heada, 'r'), 1);
	if (!ft_strcmp(str, "ss\n"))
		return (swap_swap(pushswap, 'f'), 1);
	if (!ft_strcmp(str, "pa\n"))
		return (push_a_checker(pushswap), 1);
	if (!ft_strcmp(str, "pb\n"))
		return (push_b_checker(pushswap), 1);
	return (0);
}
	// if (!ft_strcmp(str, "print b\n"))
	// 	return (print_head(pushswap->headb), 1);
	// if (!ft_strcmp(str, "print a\n"))
	// 	return (print_head(pushswap->heada), 1);

int	last_parsing_checker(t_pushswap *pushswap)
{
	if (check_list_sorted(pushswap->heada) == 0)
	{
		ft_putstr_fd("checker : invalid arguments list sorted\n", 2);
		free_tout(pushswap);
		exit(0);
	}
	if (check_list_duplicates(pushswap->heada) == 0)
	{
		ft_printf("ici\n");
		ft_putstr_fd("checker : invalid arguments\n", 2);
		free_tout(pushswap);
		exit(0);
	}
	return (1);
}

int	parsing_bonus(int ac, char **av, t_pushswap *pushswap)
{
	if (!fill_list(ac, av, pushswap))
		return (0);
	if (last_parsing_checker(pushswap) == 0)
		return (0);
	if (parsing(ac, av) == 0)
		return (ft_putstr_fd("checker : invalid arguments", 2), 0);
	return (1);
}

int	main(int ac, char **av)
{
	char		*str;
	t_pushswap	*pushswap;

	if (check_numbers(ac, av) == 1)
		return (ft_putstr_fd("checker : invalid arguments", 2), 0);
	pushswap = 0;
	pushswap = init_pushswap_ldc(pushswap);
	if (parsing_bonus(ac, av, pushswap) == 0)
		return (ft_putstr_fd("checker : invalid arguments", 2), 0);
	pushswap->size_final_heada = pushswap->heada->size;
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			return (free_tout(pushswap), ft_printf("KO"), 0);
		if (parsing_checker(str, pushswap) == 0)
			return (ft_putstr_fd("checker : invalid arguments", 2),
				free(str), free_tout(pushswap), 0);
		if (check_list_sorted(pushswap->heada) == 0
			&& pushswap->size_final_heada == pushswap->heada->size)
			return (free(str), free_tout(pushswap), ft_printf("OK\n"), 0);
		free(str);
	}
}
