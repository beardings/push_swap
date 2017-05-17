/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:43:58 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/13 19:46:06 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		findmid_b_n(t_lst **lst_a, t_lst **lst_b, t_num **num, int size)
{
	size = size / 2;
	(*num)->mid = itismid_b(lst_b, size);
	if ((checkmid(num, lst_b, size) == 1))
		findmid_b_n(lst_a, lst_b, num, size);
	(*num)->first_b = 0;
}

int			itismid_b(t_lst **lst_b, int size)
{
	int		*num;
	int		k;
	t_lst	*tmp;
	int		res;

	k = 0;
	tmp = *lst_b;
	num = (int *)malloc(sizeof(int) * size + 1);
	ft_bzero(num, (size_t)size + 1);
	while (k < size && tmp != NULL)
	{
		num[k] = tmp->x;
		tmp = tmp->next;
		k++;
	}
	sort_int_tab(num, size);
	k = size / 2;
	res = num[k];
	free(num);
	return (res);
}

int			checkmid(t_num **num, t_lst **lst_b, int size)
{
	int		len;
	t_lst	*tmp;

	len = 0;
	tmp = *lst_b;
	while (tmp != NULL && size > 0)
	{
		if (tmp->x > (*num)->mid)
			len++;
		tmp = tmp->next;
		size--;
	}
	if (len > 3)
	{
		(*num)->first_b = (*num)->mid;
		return (1);
	}
	(*num)->pro = len;
	return (0);
}

int			findmid_b(t_lst **lst_a, t_lst **lst_b, t_num **num, int size)
{
	(*num)->mid = itismid_b(lst_b, size);
	if ((checkmid(num, lst_b, size) == 1))
		findmid_b_n(lst_a, lst_b, num, size);
	return (begin_sort_b(lst_a, lst_b, num, size));
}

void		sort_b(t_lst **lst_a, t_lst **lst_b, t_num **num, int size)
{
	int skiko;

	skiko = 0;
	if (size > 2)
	{
		skiko = findmid_b(lst_a, lst_b, num, size);
		sort_b(lst_a, lst_b, num, size - skiko);
		return_bina(lst_a, lst_b, num, skiko);
	}
	else
		sort_lessfor_b(lst_b, size, num);
}
