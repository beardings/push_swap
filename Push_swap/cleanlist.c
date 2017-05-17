/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 20:15:29 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/13 19:16:08 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define G() ((*lst)->next->x == 7 && (*lst)->next->next->x == 1)
#define GG() ((*lst)->next->x == 8 && (*lst)->next->next->x == 2)
#define GGG() ((*lst)->next->x == 4 && (*lst)->next->next->x == 3)

void		nexf(int *k, t_lst **lst)
{
	if (((*lst)->next->x == 1 && (*lst)->next->next->x == 7) || G())
	{
		lstdel(lst);
		(*k) += 2;
	}
	else if (((*lst)->next->x == 2 && (*lst)->next->next->x == 8) || GG())
	{
		lstdel(lst);
		(*k) += 2;
	}
	else if (((*lst)->next->x == 3 && (*lst)->next->next->x == 4) || GGG())
	{
		lstdel(lst);
		(*k) += 2;
	}
	else if ((*lst)->next->x == 5 && (*lst)->next->next->x == 5)
	{
		lstdelone(lst);
		(*k) += 2;
	}
	else if ((*lst)->next->x == 6 && (*lst)->next->next->x == 6)
	{
		lstdelone(lst);
		(*k) += 2;
	}
}

void		cleanlist(t_lst **head)
{
	t_lst	*lst;
	int		k;

	k = 0;
	lst = *head;
	while (lst->next != NULL)
	{
		nexf(&k, &lst);
		lst = lst->next;
	}
	if (k > 0)
		cleanlist(head);
}
