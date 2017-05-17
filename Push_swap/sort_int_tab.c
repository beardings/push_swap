/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:16:54 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/13 19:46:37 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_int_tab(int *tab, int size)
{
	int	i;
	int	k;
	int	res;

	i = 0;
	k = 0;
	while (i < size)
	{
		while (k < size)
		{
			if (tab[i] < tab[k])
			{
				res = tab[i];
				tab[i] = tab[k];
				tab[k] = res;
			}
			k++;
		}
		k = 0;
		i++;
	}
}
