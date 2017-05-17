/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a_b_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 20:56:15 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/13 19:53:25 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sa(t_lst *lst_a, t_num **num, int i)
{
	t_lst	*tmp;
	t_lst	swap;

	if (lst_a != NULL)
	{
		tmp = lst_a;
		if (tmp->next)
		{
			swap.x = lst_a->x;
			tmp = tmp->next;
			lst_a->x = tmp->x;
			tmp->x = swap.x;
			i == 1 ? neednextlst(&((*num)->com), 5) : 0;
			i == 1 ? (*num)->lenop++ : 0;
		}
	}
}

void		sb(t_lst *lst_b, t_num **num, int i)
{
	t_lst	*tmp;
	t_lst	swap;

	if (lst_b != NULL)
	{
		tmp = lst_b;
		if (tmp->next)
		{
			swap.x = lst_b->x;
			tmp = tmp->next;
			lst_b->x = tmp->x;
			tmp->x = swap.x;
			i == 1 ? neednextlst(&((*num)->com), 6) : 0;
			i == 1 ? (*num)->lenop++ : 0;
		}
	}
}

void		ss(t_lst **lst_a, t_lst **lst_b, t_num **num, int i)
{
	sa(*lst_a, num, i);
	sb(*lst_b, num, i);
}
