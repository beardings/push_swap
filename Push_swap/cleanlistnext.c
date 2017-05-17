/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanlistnext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 20:30:44 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/13 19:16:46 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define D() ((*wow)->next->next->next->x == 7)
#define DD() ((*wow)->next->next->next->x == 4)
#define DDD() ((*wow)->next->next->next->x == 8)
#define DDDD() ((*wow)->next->next->next->x == 3)

void		cln1(t_lst **wow, int *k)
{
	if ((*wow)->next->x == 1 && (*wow)->next->next->x == 4 && D())
	{
		lstdelone(wow);
		(*wow)->next->x = 5;
		(*wow)->next->next->x = 4;
		(*k)++;
	}
	else if ((*wow)->next->x == 7 && (*wow)->next->next->x == 5 && DD())
	{
		lstdelone(wow);
		(*wow)->next->x = 4;
		(*wow)->next->next->x = 7;
		(*k)++;
	}
	else if ((*wow)->next->x == 5 && (*wow)->next->next->x == 1 && DD())
	{
		lstdelone(wow);
		(*wow)->next->x = 4;
		(*wow)->next->next->x = 1;
		(*k)++;
	}
}

void		cln2(t_lst **wow, int *k)
{
	if ((*wow)->next->x == 2 && (*wow)->next->next->x == 3 && DDD())
	{
		lstdelone(wow);
		(*wow)->next->x = 6;
		(*wow)->next->next->x = 3;
		(*k)++;
	}
	else if ((*wow)->next->x == 8 && (*wow)->next->next->x == 6 && DDDD())
	{
		lstdelone(wow);
		(*wow)->next->x = 3;
		(*wow)->next->next->x = 8;
		(*k)++;
	}
	else if ((*wow)->next->x == 6 && (*wow)->next->next->x == 2 && DDDD())
	{
		lstdelone(wow);
		(*wow)->next->x = 3;
		(*wow)->next->next->x = 2;
		(*k)++;
	}
}

void		cleanlistnext(t_lst **lst)
{
	t_lst	*wow;
	int		k;

	wow = *lst;
	k = 0;
	while (wow->next->next->next != NULL)
	{
		cln1(&wow, &k);
		cln2(&wow, &k);
		wow = wow->next;
	}
	if (k > 0)
		cleanlistnext(lst);
}
