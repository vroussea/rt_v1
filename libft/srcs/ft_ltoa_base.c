/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 16:35:18 by vroussea          #+#    #+#             */
/*   Updated: 2016/09/14 18:07:02 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	sizer(unsigned long value, int base)
{
	int	size;

	size = 0;
	if (value == 0)
		size++;
	while (value > 0)
	{
		size++;
		value = value / base;
	}
	return (size);
}

static char	*tab_filler(char *tab, unsigned long val, int base, int size)
{
	if (val == 0)
		tab[size - 1] = '0';
	while (val > 0)
	{
		size--;
		if ((val % base) > 9)
			tab[size] = 'a' + ((val % base) - 10);
		else
			tab[size] = '0' + (val % base);
		val = val / base;
	}
	return (tab);
}

char		*ft_ltoa_base(long value, int base)
{
	char			*tab;
	unsigned long	val;
	int				size;
	int				isneg;

	isneg = 0;
	if (base < 2 || base > 16)
		return (NULL);
	if (value < 0)
	{
		val = (-1) * value;
		if (base == 10)
			isneg = 1;
	}
	else
		val = value;
	size = sizer(val, base);
	if (!(tab = ft_strnew(size + isneg)))
		return (NULL);
	if (isneg == 1)
		tab[0] = '-';
	tab[size + isneg] = '\0';
	tab = tab_filler(tab, val, base, size + isneg);
	return (tab);
}
