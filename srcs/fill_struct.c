/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:26:19 by vroussea          #+#    #+#             */
/*   Updated: 2016/11/16 16:09:21 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scmk.h"

t_pov			create_pov(void)
{
	t_pov	pov;

	ft_putendl("Point of vew : ");
	ft_putendl("Enter x, y and z coordinates");
	pov.pos.x = catch_float("x : ");
	pov.pos.y = catch_float("y : ");
	pov.pos.z = catch_float("z : ");
	ft_putendl("Enter x, y and z vector position");
	pov.dir = dir();
	return (pov);
}

t_obj			create_obj(int val)
{
	t_obj			obj;
	unsigned char	*col;

	ft_putendl("Enter x, y and z coordinates");
	obj.pos.x = catch_float("x : ");
	obj.pos.y = catch_float("y : ");
	obj.pos.z = catch_float("z : ");
	if (val == 1)
		plane_type(&obj);
	if (val == 0)
		sphere_type(&obj);
	col = (unsigned char *)&(obj.col);
	ft_putendl("Choose object color :");
	col[2] = (unsigned char)catch_col("red value : ");
	col[1] = (unsigned char)catch_col("green value : ");
	col[0] = (unsigned char)catch_col("blue value : ");
	col[4] = 0;
	return (obj);
}

t_spot			create_spot(void)
{
	t_spot	spot;

	ft_putendl("Enter x, y and z coordinates");
	spot.pos.x = catch_float("x : ");
	spot.pos.y = catch_float("y : ");
	spot.pos.z = catch_float("z : ");
	ft_putendl("Enter x, y and z vector position");
	spot.dir = dir();
	return (spot);
}
