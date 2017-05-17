/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 20:58:58 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/13 18:49:19 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ra(t_lst **lst_a, t_num **num, int i)
{
	t_lst	*tmp;
	t_lst	*res;

	tmp = *lst_a;
	if (*lst_a != NULL)
	{
		*lst_a = (*lst_a)->next;
		tmp->next = NULL;
		res = *lst_a;
		if (res != NULL)
		{
			while (res->next != NULL)
				res = res->next;
			res->next = tmp;
			i == 1 ? neednextlst(&((*num)->com), 1) : 0;
			i == 1 ? (*num)->lenop++ : 0;
		}
	}
}

void		rb(t_lst **lst_b, t_num **num, int i)
{
	t_lst	*tmp;
	t_lst	*res;

	tmp = *lst_b;
	if (*lst_b != NULL)
	{
		*lst_b = (*lst_b)->next;
		tmp->next = NULL;
		res = *lst_b;
		if (res != NULL)
		{
			while (res->next != NULL)
				res = res->next;
			res != NULL ? res->next = tmp : 0;
			res == NULL ? res = tmp : 0;
			i == 1 ? neednextlst(&((*num)->com), 2) : 0;
			i == 1 ? (*num)->lenop++ : 0;
		}
	}
}

void		rr(t_lst **lst_a, t_lst **lst_b, t_num **num, int i)
{
	ra(lst_a, num, i);
	rb(lst_b, num, i);
}
