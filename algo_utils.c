/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:52:07 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/26 13:37:20 by mparisse         ###   ########.fr       */
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

void push_to_b_from_mediane(t_pushswap *pushswap)
{
	int mediane;
	int *sorted_tab;

	sorted_tab = sort_tab(pushswap->heada);
	mediane = find_mediane(pushswap->heada, sorted_tab);
	while (pushswap->heada->size > 3)
	{
		sorted_tab = sort_tab(pushswap->heada);
		// ft_printf("la mediane est %d \n", mediane);
		if (pushswap->heada->first->nb > mediane && pushswap->heada->first->nb != sorted_tab[2])
		{
			push_b(pushswap);
			mediane = find_mediane(pushswap->heada, sorted_tab);
		}
		else
			rotate(pushswap->heada, 'a');
	}
	free(sorted_tab);
}

void daron_algo(t_pushswap *pushswap)
{
	int *sorted_tab;
	int i;
	t_pile *tmp;

	i = 0;
	tmp = pushswap->headb->first;
	sorted_tab = sort_tab(pushswap->headb);
	while (tmp)
	{
		if (tmp->nb == sorted_tab[0])
			break;
		i++;
		tmp = tmp->next;
	}
	if (i == 0)
	{
		push_a(pushswap);
		rotate(pushswap->heada, 'a');
		return;
	}
	tmp = pushswap->headb->first;
	if (i < pushswap->headb->size / 2)
	{
		while (tmp->nb != sorted_tab[0])
			rotate(pushswap->headb, 'b');
		push_a(pushswap);
	}
	else
	{
		while (tmp->nb != sorted_tab[0])
			r_rotate(pushswap->headb, 'b');
		push_a(pushswap);
	}
	rotate(pushswap->heada, 'a');
}

int *make_sorted_tab(int *sorted_tab, int to_find, int size)
{
	int *new_sorted_tab;
	int i;
	int j;
	int keep;

	i = 0;
	new_sorted_tab = malloc(sizeof(int) * size + 1);
	if (!new_sorted_tab)
		return (0);
	while (i < size)
	{
		new_sorted_tab[i] = sorted_tab[i];
		i++;
	}
	// printf("new_sorted_tab\n");
	// print_tab(new_sorted_tab, size + 1);
	new_sorted_tab[i] = to_find;
	i = 0;
	while (i < size + 1)
	{
		j = i + 1;
		while (j < size + 1)
		{
			if (new_sorted_tab[j] < new_sorted_tab[i])
			{
				keep = new_sorted_tab[i];
				new_sorted_tab[i] = new_sorted_tab[j];
				new_sorted_tab[j] = keep;
			}
			j++;
		}
		i++;
	}
	return (new_sorted_tab);
}

// int find_father(t_pushswap *pushswap, t_pile *node)
// {
// 	t_pile *stack_a;
// 	int findsup;
// 	int i;
// 	int j;
// 	int	min;
// 	int	index;
	
// 	(void) index;
// 	i = 0;
// 	j = -1;
// 	index = j;
// 	stack_a = pushswap->heada->first;
// 	while (stack_a)
// 	{
// 		if (stack_a->nb > node->nb)
// 		{
// 			j = i;
// 			index = stack_a->index;
// 			findsup = stack_a->nb;
// 			break ;
// 		}
// 		i++;
// 		stack_a = stack_a->next;
// 	}
// 	stack_a = pushswap->heada->first;
// 	while (stack_a)
// 	{
// 		if (stack_a->nb > node->nb && stack_a->nb < findsup)
// 		{
// 			j = i;
// 			index = stack_a->index;
// 			findsup = stack_a->nb;
// 		}
// 		i++;
// 		stack_a = stack_a->next;
// 	}
// 	if (j != -1)
// 	{
// 		return (j);
// 	}
// 	i = 0;
// 	j = 0;
// 	stack_a = pushswap->heada->first;
// 	min = pushswap->heada->first->nb;
// 	while (stack_a)
// 	{
// 		if (min > stack_a->nb)
// 		{
// 			j = i;
// 			min = stack_a->nb;
// 		}
// 		i++;
// 		stack_a = stack_a->next;
// 	}
// 	// printf("min %d \n", min);
// 	return (j);
// }

int biggest(t_head *heada, int to_find)
{
	t_pile *tmp;

	tmp = heada->first;
	while (tmp)
	{
		if (tmp->nb > to_find)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

// void	fill_index_b(t_head *head)
// {
// 	int		i;
// 	t_pile	*tmp;

// 	i = 0;
// 	tmp = head->first;
// 	printf("a partir du debut\n");
// 	while (i < head->size / 2 + 1)
// 	{
// 		tmp->index = i;
// 		tmp = tmp->next;
// 		printf("tmp->index deb>> %d \n", i);
// 		i++;
// 	}
// 	i = 1;
// 	printf("a partir de la fin\n");
// 	tmp = head->last;
// 	while (i < head->size / 2)
// 	{
// 		tmp->index = i;
// 		tmp = tmp->previous;
// 		printf("tmp->index fin>> %d \n", i);
// 		i++;
// 	}
// }

int	*fill_count_tab(t_pushswap *pushswap)
{
	int		*res;
	t_pile	*pile;
	int		i;
	int		j;

	res = malloc(sizeof(int) * pushswap->headb->size);
	// =================================================================================== portege malloc
	pile = pushswap->headb->first;
	i = 0; 
	while (i < pushswap->headb->size)
	{
		res[i] = find_father(pushswap, pile) + i;
		// printf("Il  fin faut faire %d  de coup pour mettre %d dans pile a\n", res[i], pile->nb);
		// printf("le daron de res i %d est %d\n", pile->nb, res[i]); //find_father(pushswap, pile));
		i++;
		pile = pile->next;
	}
	i = pushswap->headb->size / 2;
	j = i + 1;
	pile = pushswap->headb->last;
	while (i < pushswap->headb->size)
	{
		res[i] = find_father(pushswap, pile) + j;
		// printf("le fin daron de res i %d est %d\n", pile->nb, res[i]); //find_father(pushswap, pile));
		printf("Il  fin faut faire %d  de coup pour mettre %d dans pile a\n", res[i], pile->nb);
		i++;
		j--;
		pile = pile->previous;
	}
	// i = 0;
	// pile = pushswap->headb->first;
	// while (i < pushswap->headb->size)
	// {
	// 	printf("Il faut faire %d  de coup pour mettre %d dans pile a\n", res[i], pile->nb);
	// 	i++;
	// 	pile = pile->next;
	// }
	// daron_algo_3(pushswap);
	// ft_printf("______PILE A_____\n");
	// print_head(pushswap->heada);
	// ft_printf("______PILE B_____\n");
	// print_head(pushswap->headb);
	return (res);
}

int	find_smallest_move(int *tab, int size)
{
	int	i;
	int	j;
	int min;

	i = 0;
	j = 0;
	min = tab[0];
	while (i < size)
	{
		if (tab[i] < min)
		{
			j = i;
			min = tab[i];
		}
		i++;
	}
	print_tab(tab, size);
	// printf("le plus petit coup est %d \n", min);
	return (j);
}

t_pile	*find_right_node(t_pushswap *pushswap ,int index_right_node)
{
	t_pile 	*tmp;
	int		i;

	i = 0;
	tmp = pushswap->headb->first;
	while (tmp && i != index_right_node)
	{
		i++;
		tmp = tmp->next;
	}
	return (tmp);
}

// void	printcalc(t_pushswap *pushswap)
// {
// 	printf("\tCALC\n");
// 	printf("PILE B [%i] %i -> %i\n", pushswap->headb->first->index, pushswap->headb->first->nb, findfather(pushswap, pushswap->headb->first));
// }

void daron_algo_3(t_pushswap *pushswap)
{
	int i;
	int tmp;
	int	*tab;
	// int	*sorted_tab;
	int	index_smallest_count;
	// int	*count_move;

	i = 0;
	(void) i;
	while (pushswap->headb->size)
	{
		fill_index_b(pushswap->heada);
		fill_index_b(pushswap->headb);
		printf("*******************************\n");
		tab = fill_count_tab(pushswap);
		index_smallest_count = find_smallest_move(tab, pushswap->headb->size);
		tmp = find_father(pushswap, find_right_node(pushswap, index_smallest_count));
		ft_printf("______PILE A_____\n");
		print_head(pushswap->heada);
		ft_printf("______PILE B_____\n");
		print_head(pushswap->headb);
		printf("le cout le moins couteux est a faire sur le %d de la pile b \n", index_smallest_count);
		// printf("index small count %d \n", index_smallest_count);
		printf("tmp a %d \n", tmp);
		printf("*******************************\n");
		if (index_smallest_count  < pushswap->headb->size / 2 && tmp < pushswap->heada->size / 2)
		{
			while (index_smallest_count != 0 && tmp != 0)
			{
				// printf("j'entre \n");
				rr(pushswap);
				// rotate(pushswap->headb, 'b');
				// rotate(pushswap->heada, 'a');
				index_smallest_count--;
				tmp--;
			}
			while (index_smallest_count != 0)
			{
				index_smallest_count--;
				rotate(pushswap->headb, 'b');
			}
			while (tmp != 0)
			{
				tmp--;
				rotate(pushswap->heada, 'a');
			}
		}
		if (index_smallest_count > pushswap->headb->size / 2 && tmp > pushswap->heada->size / 2)
		{
			index_smallest_count = pushswap->headb->size - index_smallest_count;
			tmp = pushswap->heada->size - tmp;
			while (index_smallest_count != 0 && tmp != 0)
			{
				rrr(pushswap);
				index_smallest_count--;
				tmp--;
			}
			while (index_smallest_count != 0)
			{
				index_smallest_count--;
				r_rotate(pushswap->headb, 'b');
			}
			while (tmp != 0)
			{
				tmp--;
				r_rotate(pushswap->heada, 'a');
			}
			
		}
		if (index_smallest_count < pushswap->headb->size / 2 && tmp > pushswap->heada->size / 2)
		{
			while (index_smallest_count != 0)//i < index_smallest_count && index_smallest_count != 0)
			{
				rotate(pushswap->headb, 'b');
				index_smallest_count--;
			}
		}
		else
		{
			if (index_smallest_count != 0)
				index_smallest_count = pushswap->headb->size - index_smallest_count;
			i = 0;
			while (index_smallest_count != 0)
			{
				r_rotate(pushswap->headb, 'b');
				index_smallest_count--;
			}
		}
		if (tmp < pushswap->heada->size / 2)
		{
			i = 0;
			while (tmp != 0)
			{
				rotate(pushswap->heada, 'a');
				tmp--;
			}
			push_a(pushswap);
		}
		else
		{
			if (tmp != 0)
				tmp = pushswap->heada->size - tmp;
			i = 0;
			while (tmp != 0)
			{
				r_rotate(pushswap->heada, 'a');
				tmp--;
			}
			push_a(pushswap);
		}
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

// void	daron_algo_2(t_pushswap *pushswap, int *sorted_tab)
// {
// 	t_pile	*tmp;
// 	int		*new_sorted_tab;
// 	int		index_pile_a;
// 	// int		index_pile_b;
// 	int		*count;
// 	int		j;

// 	index_pile_a = 0 ;
// 	tmp = pushswap->headb->first;
// 	(void) tmp;
// 	(void) index_pile_a;
// 	(void) tmp;
// 	(void) new_sorted_tab;
// 	int i = 0;
// 	count = malloc(sizeof(int) * pushswap->headb->size);
// 	if (!count)
// 		return ;
// 	// print_tab(sorted_tab, pushswap->heada->size);
// 	while (i < pushswap->headb->size)
// 	{
// 		new_sorted_tab = make_sorted_tab(sorted_tab, tmp->nb, pushswap->heada->size);
// 		index_pile_a = find_father(tmp->nb, pushswap, new_sorted_tab);
// 		if (index_pile_a == 0 && tmp->nb > pushswap->heada->first->nb)
// 			index_pile_a++;
// 		count[i] = index_pile_a + i;
// 		// printf("i : %i \n", i);
// 		// printf("l'index pile a %d \n", index_pile_a);
// 		// printf("le cout de %d est: %d \n", tmp->nb, count[i]);
// 		tmp = tmp->next;
// 		i++;
// 	}
// 	j = 0;
// 	while (j < pushswap->headb->size)
// 	{
// 		if (count[j - 1] < count[j])
// 			i = count[j - 1];
// 		j++;
// 	}
// 	// printf("count i %d \n", count[i]);
// 	// j = 0;
// 	// index_pile_b = i;
// 	// printf("indexpileb %d\n", index_pile_b);
// 	// printf("index i %i", index_pile_b);
// 	// i = 0;
// 	// while (index_pile_b != i)
// 	// {
// 	// 	r_rotate(pushswap->headb, 'b');
// 	// }
// 	if (biggest(pushswap->heada, pushswap->headb->first->nb) == 1)
// 	{
// 		push_a(pushswap);
// 		rotate(pushswap->heada, 'a');
// 		return ;
// 	}
// 	else
// 	{
// 		(void) j;
// 		j  = 0;
// 		while (j < i)
// 		{
// 			rotate(pushswap->headb, 'b');
// 			j++;
// 		}
// 		j = 0;
// 		while (j < index_pile_a)
// 		{
// 			rotate(pushswap->heada, 'a');
// 			j++;
// 		}
// 		push_a(pushswap);
// 		// if (pushswap->headb->size / 2 < index_pile_a)
// 		ft_printf("______PILE A_____\n");
// 		print_head(pushswap->heada);
// 		ft_printf("______PILE B_____\n");
// 		print_head(pushswap->headb);
// 		// printf("on s'arete\n");
// 		// exit(0) ;
// 	}
// }