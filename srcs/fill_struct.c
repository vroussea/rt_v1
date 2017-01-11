/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:26:19 by vroussea          #+#    #+#             */
/*   Updated: 2017/01/11 17:45:06 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scmk.h"

t_obj			create_pov(void)
{
	t_obj	pov;

	pov.size = 0;
	pov.col = 0;
	pov.type = 0;
	ft_putendl("Point of vew : ");
	ft_putendl("Enter x, y and z coordinates");
	pov.pos.x = catch_double("x : ");
	pov.pos.y = catch_double("y : ");
	pov.pos.z = catch_double("z : ");
	ft_putendl("Enter x, y and z vector position");
	pov.dir = dir();
	return (pov);
}

t_obj			create_obj(int val)
{
	t_obj			obj;
	unsigned char	*col;

	obj.type = val;
	ft_putendl("Enter x, y and z coordinates");
	obj.pos.x = catch_double("x : ");
	obj.pos.y = catch_double("y : ");
	obj.pos.z = catch_double("z : ");
	obj.size = 0;
	obj.dir.x = 0;
	obj.dir.y = 0;
	obj.dir.z = 0;
	if (val == PLANE)
		plane_type(&obj);
	if (val == SPHERE)
		sphere_type(&obj);
	col = (unsigned char *)&(obj.col);
	ft_putendl("Choose object color :");
	col[2] = (unsigned char)catch_col("red value : ");
	col[1] = (unsigned char)catch_col("green value : ");
	col[0] = (unsigned char)catch_col("blue value : ");
	col[4] = 0;
	return (obj);
}

t_obj			create_spot(void)
{
	t_obj	spot;

	spot.type = 0;
	spot.size = 0;
	spot.col = 0;
	ft_putendl("Enter x, y and z coordinates");
	spot.pos.x = catch_double("x : ");
	spot.pos.y = catch_double("y : ");
	spot.pos.z = catch_double("z : ");
	ft_putendl("Enter x, y and z vector position");
	spot.dir = dir();
	return (spot);
}
