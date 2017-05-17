/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotatee.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 20:58:58 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/15 16:56:15 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ra_c(t_lst **lst_a)
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
		}
	}
}

void		rb_c(t_lst **lst_b)
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
		}
	}
}

void		rr_c(t_lst **lst_a, t_lst **lst_b)
{
	ra_c(lst_a);
	rb_c(lst_b);
}
