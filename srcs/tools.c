/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 18:40:34 by vroussea          #+#    #+#             */
/*   Updated: 2017/02/07 14:00:17 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_v1.h"

void	*error_msg(char *str)
{
	ft_putendl(str);
	return (NULL);
}

void	pixel(int x, int y, int col, char *meml)
{
	if (x >= 0 && x < SIZE_X && y >= 0 && y < SIZE_Y)
		ft_memcpy(&meml[(x - 1) * 4 + (y - 1) * SIZE_X * 4], &(col), 4);
}

void	fill_quad_functs_tab(t_functs **functs)
{
	*functs = (t_functs *)ft_memalloc(sizeof(t_functs) * 4);
	(*functs)[SPHERE] = collide_sphere;
	(*functs)[PLANE] = collide_plan;
	(*functs)[CYLINDER] = collide_cylinder;
	(*functs)[CONE] = collide_cone;
}
