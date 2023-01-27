/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:11:59 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/26 13:55:20 by mparisse         ###   ########.fr       */
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

void daron_algo_4(t_pushswap *pushswap)
{
	// int 	ret_ff;
	// int price;
	int count_coup;
	int tmp;
	// t_pile	*tmp;
	// int	*tab;
	int go[4];
	// ft_printf("______PILE A_____\n");
	// print_head(pushswap->heada);
	// ft_printf("______PILE B_____\n");
	// print_head(pushswap->headb);
	// push_a(pushswap);
	// r_rotate(pushswap->heada, 'a');
	// tmp = pushswap->headb->first;
	while (pushswap->headb->size)
	{
		go[0] = get_min_price_index(pushswap);							// prix minimum de l'index dans la pile b
		go[1] = find_number_according_to_index(pushswap->headb, go[0]); // num
		go[2] = find_father_2(pushswap, go[1]);							// index prix minimum pile a
		go[3] = calcul_prix(pushswap, go[2], go[0]);				// le prix total
		if (go[0] == go[2])
		{
			printf("ok0\n");
			if (go[0] < 0)
			{
				while (go[3] != 0)
				{
					rrr(pushswap);
					go[3]--;
				}
				push_a(pushswap);
			}
			else if (go[0] > 0)
			{
				while (go[3] != 0)
				{
					rr(pushswap);
					go[3]--;
				}
				push_a(pushswap);
			}
			else
				push_a(pushswap);
		}
		else if (go[0] < 0 && go[2] < 0)
		{
			printf("ok1\n");
			if (go[0] < go[2])
			{
				count_coup = abs(go[2]);
				while (go[3] != count_coup)
				{
					// ft_printf("ici");
					r_rotate(pushswap->heada, 'a');
					go[3]--;
				}
				while (go[3] != 0)
				{
					rrr(pushswap);
					go[3]--;
				}
				push_a(pushswap);
			}
			else if (go[0] > go[2])
			{
				count_coup = abs(go[0]);
				while (go[3] != count_coup)
				{
					rr(pushswap);
					go[3]--;
				}
				while (go[3] != 0)
				{
					r_rotate(pushswap->headb, 'b');
					go[3]--;
				}
				push_a(pushswap);
			}
		}
		// else if (go[0] > 0 && go[2] > 0)
		// {
		// 	printf("ok2\n");
		// 	if (go[0] < go[2])
		// 	{
		// 		count_coup = abs(go[0]);
		// 		while (go[3] != count_coup)
		// 		{
		// 			rotate(pushswap->heada, 'a');
		// 			go[3]--;
		// 		}
		// 		while (go[3] != 0)
		// 		{
		// 			rr(pushswap);
		// 			go[3]--;
		// 		}
		// 		push_a(pushswap);
		// 	}
		// 	else if (go[0] > go[2])
		// 	{
		// 		count_coup = abs(go[2]);
		// 		while (go[3] != count_coup)
		// 		{
		// 			r_rotate(pushswap->headb, 'b');
		// 			go[3]--;
		// 		}
		// 		while (go[3] != 0)
		// 		{
		// 			rr(pushswap);
		// 			go[3]--;
		// 		}
		// 		push_a(pushswap);
		// 	}
		// }
		else
		{
			printf("ok3\n");
			if (go[0] == 0)
			{
				// count_coup = abs(go[2]);
				// while (count_coup != 0)
				// {
				// 	rotate(pushswap->headb, 'b');
				// 	count_coup--;
				// }
				count_coup = abs(go[2]);
				if (go[2] < 0)
				{
					while (count_coup != 0)
					{
						r_rotate(pushswap->heada, 'a');
						count_coup--;
					}
					// push_a(pushswap);
				}
				else if (go[2] > 0)
				{
					while (count_coup != 0)
					{
						rotate(pushswap->heada, 'a');
						count_coup--;
					}
				}
				push_a(pushswap);
			}
			else if (go[2] == 0)
			{
				count_coup = abs(go[0]);
				if (go[0] > 0)
				{
					while (count_coup != 0)
					{
						rotate(pushswap->headb, 'b');
						count_coup--;
					}
				}
				else if (go[0] < 0)
				{
					while (count_coup != 0)
					{
						r_rotate(pushswap->headb, 'b');
						count_coup--;
					}
				}
				push_a(pushswap);
			}
			else
			{
				go[0] = find_father_2(pushswap, pushswap->headb->first->nb);
				go[1] = find_number_according_to_index(pushswap->heada, go[0]);
				while (pushswap->heada->first->nb != go[1])
				{
					rotate(pushswap->heada, 'a');
				}
				push_a(pushswap);
			}
		}
	}
		// printf("le min price est %d c'est %d daron %d\n", go[0], go[1], go[2]);
		// printf("coup total %d\n",)
	tmp = find_min(pushswap->heada);
	tmp = find_number_according_to_index(pushswap->heada, tmp);
	while (pushswap->heada->first->nb != tmp)
	{
		rotate(pushswap->heada, 'a');
	}
	printf("tmp >> %d\n", tmp);
	ft_printf("______PILE A_____\n");
	print_head(pushswap->heada);
	ft_printf("______PILE B_____\n");
	print_head(pushswap->headb);
	// go[3] =
	// go[3] = find_min_price_nb(pushswap);
	// ret_ff = find_father_2(pushswap, tmp);
	// price = calcul_prix(pushswap ,ret_ff, tmp->index);
	// printf("le prix de %d est %d \n",tmp->nb, price);
	// if (!tmp)
	// break ;
	// tmp = tmp->next;
	// (void)price;
	// ft_printf("ret ff >> %d\n", ret_ff);
}
