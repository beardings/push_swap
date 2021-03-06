/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:47:15 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/15 17:47:42 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
