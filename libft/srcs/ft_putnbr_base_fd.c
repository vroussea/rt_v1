/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 13:50:46 by vroussea          #+#    #+#             */
/*   Updated: 2016/09/14 18:06:22 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_fd(long n, int base, int fd)
{
	unsigned long	value;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		value = n * -1;
	}
	else
		value = n;
	if (value >= (unsigned long)base)
	{
		ft_putnbr_base_fd(value / base, base, fd);
		ft_putnbr_base_fd(value % base, base, fd);
	}
	else
	{
		if (value <= 9)
			ft_putchar_fd('0' + value, fd);
		else
			ft_putchar_fd('a' + value - 10, fd);
	}
}
