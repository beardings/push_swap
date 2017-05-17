/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enotherclean.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 20:31:53 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/13 19:17:15 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define RRR() ((*wow)->next->x == 2 && (*wow)->next->next->x == 1)
#define RR() ((*wow)->next->x == 6 && (*wow)->next->next->x == 5)
#define R() ((*wow)->next->x == 8 && (*wow)->next->next->x == 7)

void		bla1(t_lst **wow, int *k)
{
	if (((*wow)->next->x == 1 && (*wow)->next->next->x == 2) || RRR())
	{
		lstdelone(wow);
		(*wow)->next->x = 9;
		(*k)++;
	}
	else if (((*wow)->next->x == 5 && (*wow)->next->next->x == 6) || RR())
	{
		lstdelone(wow);
		(*wow)->next->x = 10;
		(*k)++;
	}
	else if (((*wow)->next->x == 7 && (*wow)->next->next->x == 8) || R())
	{
		lstdelone(wow);
		(*wow)->next->x = 11;
		(*k)++;
	}
}

void		enotherclean(t_lst **lst)
{
	t_lst	*wow;
	int		k;

	wow = *lst;
	k = 0;
	while (wow->next != NULL)
	{
		bla1(&wow, &k);
		wow = wow->next;
	}
	if (k > 0)
		enotherclean(lst);
}
