/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 16:23:08 by vroussea          #+#    #+#             */
/*   Updated: 2016/09/14 17:04:22 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrealloc(char *str, size_t n)
{
	int		size;
	int		i;
	char	*new;

	size = ft_strlen(str);
	if (!(new = ft_strnew(size + n)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		new[i] = str[i];
		i++;
	}
	ft_strdel(&str);
	return (new);
}
