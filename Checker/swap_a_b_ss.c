/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a_b_ss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 20:56:15 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/15 16:55:37 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sa_c(t_lst *lst_a)
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
		}
	}
}

void		sb_c(t_lst *lst_b)
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
		}
	}
}

void		ss_c(t_lst **lst_a, t_lst **lst_b)
{
	sa_c(*lst_a);
	sb_c(*lst_b);
}
