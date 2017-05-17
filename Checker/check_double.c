/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 21:01:51 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/14 20:49:21 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		wwwfunc(int *i, int *k, t_ch **che_l, int *num)
{
	while (*i + (*che_l)->fin < (*che_l)->len)
	{
		*k = 0;
		while (*k < (*che_l)->len - (*che_l)->fin)
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
	if (*i + (*che_l)->fin == (*che_l)->len)
		return (1);
	return (0);
}

int		check_double(char **v, t_ch **che_l)
{
	int	i;
	int	num[(*che_l)->len - (*che_l)->fin];
	int	k;

	k = 0;
	i = (*che_l)->fin;
	while (i < (*che_l)->len)
	{
		num[k] = ft_atoi(v[i]);
		i++;
		k++;
	}
	num[k] = '\0';
	i = 0;
	if (!(wwwfunc(&i, &k, che_l, num)))
		return (0);
	if (i + (*che_l)->fin == (*che_l)->len)
		return (1);
	else
		return (0);
}
