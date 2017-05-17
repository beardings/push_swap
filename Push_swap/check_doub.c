/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 21:01:51 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/14 20:49:21 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		w_func(int *i, int *k, int len, int *num)
{
	while (*i < len - 1)
	{
		*k = 0;
		while (*k < len - 1)
		{
			if (*k == *i)
				(*k)++;
			else if (num[*i] != num[*k])
				(*k)++;
			else
				return (0);
		}
		(*i)++;
	}
	if (*i == len - 1)
		return (1);
	return (0);
}

int		check_doub(char **v, int len)
{
	int	i;
	int	num[len];
	int	k;

	k = 0;
	i = 1;
	while (i < len)
	{
		num[k] = ft_atoi(v[i]);
		i++;
		k++;
	}
	num[k] = '\0';
	i = 0;
	if (!(w_func(&i, &k, len, num)))
		return (0);
	if (i == len - 1)
		return (1);
	else
		return (0);
}
