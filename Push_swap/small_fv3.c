/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_fv3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:41:37 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/13 19:42:30 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			checkkol(t_lst **lst_a, t_num **num)
{
	int		i;
	t_lst	*tmp;

	i = 0;
	tmp = *lst_a;
	while (tmp != NULL)
	{
		if (tmp->x <= (*num)->mid)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

int			lenlstnew(t_lst **lst)
{
	int		i;
	t_lst	*res;

	i = 0;
	res = *lst;
	while (res != NULL)
	{
		i++;
		res = res->next;
	}
	return (i);
}

void		return_bina(t_lst **lst_a, t_lst **lst_b, t_num **num, int size)
{
	while (size > 0)
	{
		pb(lst_a, lst_b, num, 1);
		(*num)->end++;
		size--;
	}
}

void		return_binb(t_lst **lst_a, t_lst **lst_b, t_num **num, int size)
{
	while (size > 0)
	{
		pa(lst_a, lst_b, num, 1);
		(*num)->end++;
		size--;
	}
}

int			checkkolnew(t_lst **lst_b, t_num **num)
{
	int		i;
	t_lst	*tmp;

	i = 0;
	tmp = *lst_b;
	while (tmp != NULL)
	{
		if (tmp->x > (*num)->mid)
			i++;
		tmp = tmp->next;
	}
	return (i);
}
