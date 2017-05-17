/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sort_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:44:26 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/13 18:46:20 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define START() i = 0, ski = 0, tmp = *lst_b
#define NEXT() tmp = tmp->next, pa(lst_a, lst_b, num, 1), (*num)->start++, ski++

void		to_up(int i, t_lst **lst_b, t_num **num)
{
	if (lenlstnew(lst_b) > i)
	{
		while (i > 0)
		{
			rrb(lst_b, num, 1);
			i--;
		}
	}
}

int			begin_sort_b(t_lst **lst_a, t_lst **lst_b, t_num **num, int size)
{
	t_lst	*tmp;
	int		ski;
	int		i;

	START();
	while (tmp != NULL && size > 0)
	{
		if (!checkkolnew(lst_b, num))
			break ;
		if (tmp->x > (*num)->mid)
			NEXT();
		else
		{
			tmp = tmp->next;
			rb(lst_b, num, 1);
			i++;
		}
		size--;
	}
	sort_a(lst_a, lst_b, num, ski);
	to_up(i, lst_b, num);
	sort_lessfor(lst_a, ski, num);
	return (ski);
}
