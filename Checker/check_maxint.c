/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maxint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 20:24:02 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/13 20:24:48 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long			ft_atoi_l(const char *str)
{
	long		i;
	long		result;
	long		sign;

	result = 0;
	i = 0;
	sign = 1;
	if (str[i] == '\200')
		return (0);
	while (str[i] < 33)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		str[i] != 0 ? result = ((result * 10) + (str[i] - '0')) : 0;
		i++;
	}
	return (result * sign);
}

int				check_maxint(char *str)
{
	long		i;

	i = ft_atoi_l(str);
	if (i > INT_MAX || i < INT_MIN)
		return (0);
	else
		return (1);
}

int				check_int(char **v, t_ch **che_l)
{
	int			i;

	i = (*che_l)->fin;
	while (i < (*che_l)->len)
	{
		if ((check_value(v[i])))
		{
			if ((check_maxint(v[i])))
				i++;
			else
				return (0);
		}
		else
			return (0);
	}
	if (i == (*che_l)->len)
		return (1);
	else
		return (0);
}
