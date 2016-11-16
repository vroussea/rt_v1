/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:23:26 by vroussea          #+#    #+#             */
/*   Updated: 2016/11/13 18:00:12 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static float	fill_float(const char *str, int i)
{
	float	floatty;
	int		val;
	int		div;

	floatty = 0;
	val = 0;
	div = 10;
	while (ft_isdigit(str[i]))
	{
		val = val * 10;
		val += str[i] - '0';
		i++;
	}
	if (str[i++] == '.')
	{
		while (ft_isdigit(str[i]))
		{
			floatty += (float)((float)(str[i] - '0') / div);
			div *= 10;
			i++;
		}
	}
	return ((float)(val + floatty));
}

float			ft_atof(const char *str)
{
	int		i;
	float	neg;

	neg = 1;
	i = 0;
	while (ft_isspace(str[i]) || str[i] == '-' || str[i] == '+')
		i++;
	if (i > 0 && str[i - 1] == '-')
		neg *= -1;
	return (fill_float(str, i) * neg);
}
