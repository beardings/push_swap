/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_pa_ppp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:35:08 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/15 17:35:10 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		pushres(t_lst **lst, t_lst **lil)
{
	if (*lst)
		(*lil)->next = *lst;
	*lst = *lil;
}

void		pb_c(t_lst **lst_a, t_lst **lst_b)
{
	t_lst *lal;

	if (*lst_a != NULL)
	{
		lal = *lst_a;
		*lst_a = (*lst_a)->next;
		lal->next = NULL;
		pushres(lst_b, &lal);
	}
}

void		pa_c(t_lst **lst_a, t_lst **lst_b)
{
	t_lst *lol;

	if (*lst_b != NULL)
	{
		lol = *lst_b;
		*lst_b = (*lst_b)->next;
		pushres(lst_a, &lol);
	}
}
