/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 20:29:58 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/13 19:52:29 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define START1() k = 0, i = 0, skiko = 0, tmp = *lst_a, wow = size
#define NEXT1() tmp = tmp->next, ra(lst_a, num, 1), i++
#define NEXT2() tmp = tmp->next, pb(lst_a, lst_b, num, 1), (*num)->start++
#define BOO() (lenlstnew(lst_a) == i + wow)

void		what(int wow, t_lst **lst_a, int i, t_num **num)
{
	if (wow > 0 && wow < lenlstnew(lst_a) / 2 && wow < i && BOO())
	{
		while (wow != 0)
		{
			ra(lst_a, num, 1);
			wow--;
		}
	}
	else if (lenlstnew(lst_a) != i)
		while (i--)
			rra(lst_a, num, 1);
}

int			begin_sort(t_lst **lst_a, t_lst **lst_b, t_num **num, int size)
{
	t_lst	*tmp;
	int		wow;
	int		skiko;
	int		i;
	int		k;

	START1();
	lenlstnew(lst_b) != 0 ? k = 1 : 0;
	while (tmp != NULL && wow > 0)
	{
		if (!checkkol(lst_a, num))
			break ;
		if (tmp->x <= (*num)->mid)
		{
			NEXT2();
			skiko++;
		}
		else
			NEXT1();
		wow--;
	}
	k == 1 ? what(wow, lst_a, i, num) : 0;
	(*num)->end = (*num)->len - (*num)->start;
	return (skiko);
}

void		start_sort(t_lst *lst_a, t_lst *lst_b, t_num *num)
{
	if (num->len > 3)
		sort_a(&lst_a, &lst_b, &num, num->len);
	else if (num->len < 4)
		sort_lessfor_a(&lst_a, num->len, &num);
	if (num->len > 4)
	{
		cleanlist(&(num->com));
		enotherclean(&(num->com));
		cleanlistnext(&(num->com));
	}
	lenlst(&(num->com));
	ft_del_list(&lst_b);
	ft_del_list(&lst_a);
}
