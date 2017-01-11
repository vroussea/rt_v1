/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:41:53 by vroussea          #+#    #+#             */
/*   Updated: 2016/12/16 15:43:18 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	fill_double(const char *str, int i)
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

double			ft_atod(const char *str)
{
	int		i;
	double	neg;

	neg = 1;
	i = 0;
	while (ft_isspace(str[i]) || str[i] == '-' || str[i] == '+')
		i++;
	if (i > 0 && str[i - 1] == '-')
		neg *= -1;
	return (fill_double(str, i) * neg);
}
