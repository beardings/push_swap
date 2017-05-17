/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:40:53 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/15 17:43:43 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long		ft_atoi_l(const char *str)
{
	long	i;
	long	result;
	long	sign;

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

int			check_maxint(char *str)
{
	long	i;

	i = ft_atoi_l(str);
	if (i > INT_MAX || i < INT_MIN)
		return (0);
	else
		return (1);
}
