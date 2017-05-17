/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lessfor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:09:44 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/13 19:47:29 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define DD() (tmp->next->x < tmp->next->next->x)
#define CC() (tmp->next->x > tmp->next->next->x)

void		func_o(t_lst *tmp, t_lst **lst, t_num **num)
{
	if (tmp->x > tmp->next->x)
	{
		if ((tmp->x < tmp->next->next->x) && DD())
			sa(*lst, num, 1);
		else if ((tmp->x > tmp->next->next->x) && CC())
		{
			sa(*lst, num, 1);
			ra(lst, num, 1);
			sa(*lst, num, 1);
			rra(lst, num, 1);
			sa(*lst, num, 1);
		}
		else if ((tmp->x > tmp->next->next->x) && DD())
		{
			sa(*lst, num, 1);
			ra(lst, num, 1);
			sa(*lst, num, 1);
			rra(lst, num, 1);
		}
	}
}

void		func_s(t_lst *tmp, t_lst **lst, t_num **num)
{
	if (tmp->x < tmp->next->x)
	{
		if ((tmp->x > tmp->next->next->x) && CC())
		{
			ra(lst, num, 1);
			sa(*lst, num, 1);
			rra(lst, num, 1);
			sa(*lst, num, 1);
		}
		else if ((tmp->x < tmp->next->next->x) && CC())
		{
			ra(lst, num, 1);
			sa(*lst, num, 1);
			rra(lst, num, 1);
		}
	}
}

void		sort_lessfor(t_lst **lst, int size, t_num **num)
{
	t_lst	*tmp;

	tmp = *lst;
	if (tmp != NULL)
	{
		if (size == 2)
			tmp->x > tmp->next->x ? sa(*lst, num, 1) : 0;
		if (size == 3)
		{
			func_o(tmp, lst, num);
			func_s(tmp, lst, num);
		}
	}
}
