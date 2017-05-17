/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_a_b_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:37:55 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/15 18:39:45 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_lstsize(t_lst **lst_b)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = *lst_b;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void		rra_c(t_lst **lst_a)
{
	t_lst	*tmp;
	t_lst	*res;

	if (*lst_a != NULL && (check_lstsize(lst_a) > 1))
	{
		tmp = *lst_a;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		res = tmp;
		res = res->next;
		tmp->next = NULL;
		res->next = *lst_a;
		*lst_a = res;
	}
}

void		rrb_c(t_lst **lst_b)
{
	t_lst	*tmp;
	t_lst	*res;

	if (*lst_b != NULL && (check_lstsize(lst_b) > 1))
	{
		tmp = *lst_b;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		res = tmp;
		res = res->next;
		tmp->next = NULL;
		res->next = *lst_b;
		*lst_b = res;
	}
}

void		rrr_c(t_lst **lst_a, t_lst **lst_b)
{
	rra_c(lst_a);
	rrb_c(lst_b);
}
