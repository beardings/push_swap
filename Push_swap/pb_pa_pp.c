/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_pa_pp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:20:16 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/13 19:20:17 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		pushres(t_lst **lst, t_lst **lil)
{
	if (*lst)
		(*lil)->next = *lst;
	*lst = *lil;
}

void		pb(t_lst **lst_a, t_lst **lst_b, t_num **num, int i)
{
	t_lst *lal;

	if (*lst_a != NULL)
	{
		lal = *lst_a;
		*lst_a = (*lst_a)->next;
		lal->next = NULL;
		pushres(lst_b, &lal);
		i == 1 ? neednextlst(&((*num)->com), 4) : 0;
		i == 1 ? (*num)->lenop++ : 0;
	}
}

void		pa(t_lst **lst_a, t_lst **lst_b, t_num **num, int i)
{
	t_lst *lol;

	if (*lst_b != NULL)
	{
		lol = *lst_b;
		*lst_b = (*lst_b)->next;
		pushres(lst_a, &lol);
		i == 1 ? neednextlst(&((*num)->com), 3) : 0;
		i == 1 ? (*num)->lenop++ : 0;
	}
}
