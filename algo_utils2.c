/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:11:59 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/27 14:13:15 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

void fill_index_b(t_head *head)
{
	int i;
	t_pile *tmp;

	if (head->size == 0)
		return;
	i = 0;
	tmp = head->first;
	// ft_printf("head_>size >> %d \n", head->size);
	while (i < head->size / 2 + 1)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
	i = 1;
	tmp = head->last;
	while (i < head->size / 2 + 1)
	{
		tmp->index = i * -1;
		tmp = tmp->previous;
		i++;
	}
}

int find_father(t_pushswap *pushswap, t_pile *node)
{
	t_pile *stack_a;
	int findsup;
	int i;
	int j;
	int min;
	int index;

	(void)index;
	i = 0;
	j = -1;
	index = j;
	stack_a = pushswap->heada->first;
	while (stack_a)
	{
		if (stack_a->nb > node->nb)
		{
			j = i;
			index = stack_a->index;
			findsup = stack_a->nb;
			break;
		}
		i++;
		stack_a = stack_a->next;
	}
	stack_a = pushswap->heada->first;
	while (stack_a)
	{
		if (stack_a->nb > node->nb && stack_a->nb < findsup)
		{
			j = i;
			index = stack_a->index;
			findsup = stack_a->nb;
		}
		i++;
		stack_a = stack_a->next;
	}
	if (j != -1)
	{
		return (j);
	}
	i = 0;
	j = 0;
	stack_a = pushswap->heada->first;
	min = pushswap->heada->first->nb;
	while (stack_a)
	{
		if (min > stack_a->nb)
		{
			j = i;
			min = stack_a->nb;
		}
		i++;
		stack_a = stack_a->next;
	}
	// printf("min %d \n", min);
	return (j);
}

int find_min(t_head *heada)
{
	t_pile *tmp;
	int min;
	int index_min;

	tmp = heada->first;
	min = tmp->nb;
	index_min = tmp->index;
	while (tmp)
	{
		if (tmp->nb < min)
		{
			index_min = tmp->index;
			min = tmp->nb;
		}
		tmp = tmp->next;
	}
	return (index_min);
}

int find_father_2(t_pushswap *pushswap, int node)
{
	t_pile *stack_a;
	int index_father;
	int findsup;

	index_father = find_min(pushswap->heada);
	stack_a = pushswap->heada->first;
	while (stack_a)
	{
		if (stack_a->nb > node)
		{
			index_father = stack_a->index;
			findsup = stack_a->nb;
			break;
		}
		stack_a = stack_a->next;
	}
	stack_a = pushswap->heada->first;
	while (stack_a)
	{
		if (stack_a->nb > node && stack_a->nb < findsup)
		{
			index_father = stack_a->index;
			findsup = stack_a->nb;
		}
		stack_a = stack_a->next;
	}
	return (index_father);
}

int find_number_according_to_index(t_head *head, int index)
{
	t_pile *tmp;

	tmp = head->first;
	while (tmp)
	{
		if (tmp->index == index)
			return (tmp->nb);
		tmp = tmp->next;
	}
	return (0);
}
int calcul_prix(t_pushswap *pushswap, int father, int son)
{
	int price;
	int nb;

	if (father == son)
	{
		return (abs(father));
	}
	if (father < 0 && son < 0)
	{
		if (father < son)
		{
			nb = find_number_according_to_index(pushswap->heada, father);
			price = abs(son) + (abs(father) - abs(son));
			return (price);
		}
		if (son < father)
		{
			nb = find_number_according_to_index(pushswap->heada, father);
			price = abs(father) + (abs(son) - abs(father));
			return (price);
		}
	}
	if (father > 0 && son > 0)
	{
		if (father < son)
		{
			nb = find_number_according_to_index(pushswap->heada, father);
			price = father + (son - father);
			return (price);
		}
		if (son < father)
		{
			price = son + (father - son);
			return (price);
		}
	}
	(void)nb;
	return (abs(father) + abs(son));
}

int get_min_price_index(t_pushswap *pushswap)
{
	int min_price;
	int index;
	t_pile *tmp;

	tmp = pushswap->headb->first;
	min_price = calcul_prix(pushswap, find_father_2(pushswap, tmp->nb), tmp->index);
	index = tmp->index;
	while (tmp)
	{
		if (calcul_prix(pushswap, find_father_2(pushswap, tmp->nb), tmp->index) < min_price)
		{
			min_price = calcul_prix(pushswap, find_father_2(pushswap, tmp->nb), tmp->index);
			index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (index);
}

void	fill_count_moves(int *go, t_countmoves *countmoves)
{
	if (go[0] == 0)
	{
		countmoves->count_rb = 0;
		countmoves->count_rrb = 0;
	}
	else
	{
		if (go[0] > 0)
		{
			countmoves->count_rb = go[0];
			countmoves->count_rrb = 0;
		}
		else if (go[0] < 0)
		{
			countmoves->count_rrb = abs(go[0]);
			countmoves->count_rb = 0;
		}
		else
		{
			printf("il y a eu un souci \n");
			exit(0);
		}
	}
	if (go[2] == 0)
	{
		countmoves->count_ra = 0;
		countmoves->count_rra = 0;
	}
	else
	{
		if (go[2] > 0)
		{
			countmoves->count_ra = go[2];
			countmoves->count_rra = 0;
		}
		else if (go[2] < 0)
		{
			countmoves->count_rra = go[2];
			countmoves->count_ra = 0; 
		}
		else
		{
			printf("il y a eu un souci \n");
			exit(0);
		}
	}
}

// rra 0 // ra 60
void	fill_count_moves_rr(t_countmoves *countmoves)
{
	if (countmoves->count_ra - countmoves->count_rb > 0 || countmoves->count_rb - countmoves->count_ra > 0 )
		countmoves->count_rr = abs(countmoves->count_rb - countmoves->count_ra);
	if (countmoves->count_rra - countmoves->count_rrb > 0 || countmoves->count_rrb - countmoves->count_rra > 0)
		countmoves->count_rrr = abs(countmoves->count_rra - countmoves->count_rrb);
}

void daron_algo_4(t_pushswap *pushswap)
{
	t_countmoves countmoves;
	int tmp;
	int go[4];

	go[0] = get_min_price_index(pushswap);							// prix minimum de l'index dans la pile b
	go[1] = find_number_according_to_index(pushswap->headb, go[0]); // num
	go[2] = find_father_2(pushswap, go[1]);							// index prix minimum pile a
	go[3] = calcul_prix(pushswap, go[2], go[0]);				    // le prix total
	fill_count_moves(go, &countmoves);
	printf("count moves ra  %d\n", countmoves.count_ra);
	printf("count moves rra %d\n", countmoves.count_rra);
	printf("count moves rb  %d\n", countmoves.count_rb);
	printf("count moves rrb %d\n", countmoves.count_rrb);
	
	// fill_count_moves_rr(&countmoves);
	// printf("go0 >> %d\n",go[0]);
	// printf("go1 >> %d\n",go[1]);
	// printf("go2 >> %d\n",go[2]);
	// printf("go3 >> %d\n",go[3]);
	tmp = find_min(pushswap->heada);
	tmp = find_number_according_to_index(pushswap->heada, tmp);
	while (pushswap->heada->first->nb != tmp)
	{
		rotate(pushswap->heada, 'a');
	}
	ft_printf("______PILE A_____\n");
	print_head(pushswap->heada);
	ft_printf("______PILE B_____\n");
	print_head(pushswap->headb);
}
