/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 20:28:17 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/13 20:43:08 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_value(char *str)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[0] == '-' && k == 0)
		{
			i++;
			k++;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	if (str[i] == '\0' && str[i - 1] != '-')
		return (1);
	else
		return (0);
}

int			next_st(char **v, t_ch **che_l, int *k, int *i)
{
	if (v[*i][*k] == '-' && v[*i][*k + 1] == 'v' && v[*i][*k + 2] == '\0')
	{
		if ((*che_l)->flag_v == 1)
			return (0);
		(*che_l)->flag_v = 1;
		return (1);
	}
	else if (v[*i][*k] == '-' && v[*i][*k + 1] == 'c' && v[*i][*k + 2] == '\0')
	{
		if ((*che_l)->flag_c == 1)
			return (0);
		(*che_l)->flag_c = 1;
		return (1);
	}
	else if (v[*i][*k] == '-' && v[*i][*k + 1] == 'k' && v[*i][*k + 2] == '\0')
	{
		if ((*che_l)->flag_k == 1)
			return (0);
		(*che_l)->flag_k = 1;
		return (1);
	}
	else
		return (0);
}

int			check_flag(char **v, t_ch **che_l)
{
	int		i;
	int		k;
	int		kol;

	i = 1;
	k = 0;
	kol = 0;
	while (i < 4 && i != (*che_l)->len)
	{
		if ((next_st(v, che_l, &k, &i)) == 0)
			break ;
		else
			kol++;
		i++;
	}
	if ((*che_l)->len == i)
		return (-1);
	else if ((check_value(v[i])) == 1)
	{
		if (i == 1)
			(*che_l)->fin = 1;
		return (kol);
	}
	else
		return (0);
}
