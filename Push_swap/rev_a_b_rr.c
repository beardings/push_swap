/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_a_b_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:37:55 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/13 19:38:25 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rra(t_lst **lst_a, t_num **num, int i)
{
	t_lst	*tmp;
	t_lst	*res;

	if (*lst_a != NULL && (checklstsize(lst_a) > 1))
	{
		tmp = *lst_a;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		res = tmp;
		res = res->next;
		tmp->next = NULL;
		res->next = *lst_a;
		*lst_a = res;
		i == 1 ? neednextlst(&((*num)->com), 7) : 0;
		i == 1 ? (*num)->lenop++ : 0;
	}
}

void		rrb(t_lst **lst_b, t_num **num, int i)
{
	t_lst	*tmp;
	t_lst	*res;

	if (*lst_b != NULL && (checklstsize(lst_b) > 1))
	{
		tmp = *lst_b;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		res = tmp;
		res = res->next;
		tmp->next = NULL;
		res->next = *lst_b;
		*lst_b = res;
		i == 1 ? neednextlst(&((*num)->com), 8) : 0;
		i == 1 ? (*num)->lenop++ : 0;
	}
}

void		rrr(t_lst **lst_a, t_lst **lst_b, t_num **num, int i)
{
	rra(lst_a, num, i);
	rrb(lst_b, num, i);
}
