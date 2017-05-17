/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:42:56 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/13 19:43:33 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			itismid(t_lst **lst_a, int size)
{
	int		*num;
	int		k;
	t_lst	*tmp;
	int		res;

	k = 0;
	tmp = *lst_a;
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

int			findmid(t_lst **lst_a, t_lst **lst_b, t_num **num, int size)
{
	(*num)->mid = itismid(lst_a, size);
	return (begin_sort(lst_a, lst_b, num, size));
}

void		sort_a(t_lst **lst_a, t_lst **lst_b, t_num **num, int size)
{
	int skiko;

	if (size > 2)
	{
		skiko = findmid(lst_a, lst_b, num, size);
		sort_a(lst_a, lst_b, num, size - skiko);
		sort_b(lst_a, lst_b, num, skiko);
		return_binb(lst_a, lst_b, num, skiko);
	}
	else
		sort_lessfor(lst_a, size, num);
}
