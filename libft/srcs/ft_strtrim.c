/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:34:15 by vroussea          #+#    #+#             */
/*   Updated: 2016/11/24 13:00:12 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	char	*tmp;
	size_t	size;

	tmp = (char *)s;
	while (*tmp == ' ' || *tmp == '\n' || *tmp == '\t')
		tmp++;
	if ((size = ft_strlen(tmp)) == 0)
		return (ft_strnew(0));
	while (tmp[size - 1] == ' ' || tmp[size - 1] == '\n'
			|| tmp[size - 1] == '\t')
		size--;
	if ((str = ft_strnew(size)))
	{
		str[size] = '\0';
		while (size)
		{
			str[size - 1] = tmp[size - 1];
			size--;
		}
	}
	else
		str = NULL;
	return (str);
}
