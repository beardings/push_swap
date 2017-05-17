/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lessfor_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:13:36 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/13 19:48:29 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define AAA() (tmp->next->x > tmp->next->next->x)
#define BBB() (tmp->next->x < tmp->next->next->x)

void		ff(t_lst **lst, t_num **num, t_lst *tmp)
{
	if (tmp->x > tmp->next->x)
	{
		if ((tmp->x < tmp->next->next->x) && BBB())
			sa(*lst, num, 1);
		else if ((tmp->x > tmp->next->next->x) && AAA())
		{
			ra(lst, num, 1);
			sa(*lst, num, 1);
		}
		else if ((tmp->x > tmp->next->next->x) && BBB())
			ra(lst, num, 1);
	}
	else if (tmp->x < tmp->next->x)
	{
		if ((tmp->x > tmp->next->next->x) && AAA())
			rra(lst, num, 1);
		else if ((tmp->x < tmp->next->next->x) && AAA())
		{
			sa(*lst, num, 1);
			ra(lst, num, 1);
		}
	}
}

void		sort_lessfor_a(t_lst **lst, int size, t_num **num)
{
	t_lst	*tmp;

	tmp = *lst;
	if (tmp != NULL)
	{
		if (size == 2)
			if (tmp->x > tmp->next->x)
				sa(*lst, num, 1);
		if (size == 3)
			ff(lst, num, tmp);
	}
}
