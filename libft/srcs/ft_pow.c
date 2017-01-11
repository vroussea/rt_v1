/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:18:01 by vroussea          #+#    #+#             */
/*   Updated: 2017/01/11 18:33:37 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_pow(double x, double y)
{
	double	value;
	int		yneg;

	value = x;
	yneg = 0;
	if (y == 0)
		return (1);
	if (y < 0)
	{
		y = y * -1;
		yneg++;
	}
	while (y > 1)
	{
		x *= value;
		y--;
	}
	return (yneg ? 1 / x : x);
}
