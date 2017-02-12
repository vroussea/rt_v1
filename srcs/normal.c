/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:37:54 by vroussea          #+#    #+#             */
/*   Updated: 2017/02/12 17:42:37 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_v1.h"
#include <stdio.h> /////

t_vect3d	plane_normal(t_vect3d pos, t_obj plane)
{
	pos = plane.dir;
	return (pos);
}

t_vect3d	sphere_normal(t_vect3d pos, t_obj sphere)
{
	t_vect3d	norm;

	norm = vect3d_sub(pos, sphere.pos);
	return (norm);
}

t_vect3d	cylinder_normal(t_vect3d pos, t_obj cyl)
{
	t_vect3d	norm;
	t_obj		plane;
	double		d;
	t_vect3d	v;

	plane.dir = cyl.dir;
	plane.pos = pos;
	d = vect3d_scal_prod(cyl.dir, plane.dir);
	if (d)
		d = vect3d_scal_prod(vect3d_sub(plane.pos, cyl.pos), plane.dir) / d;
	else
	{
		cyl.dir = vect3d_mult_scal(cyl.dir, -1);
		d = vect3d_scal_prod(cyl.dir, plane.dir);
		d = vect3d_scal_prod(vect3d_sub(plane.pos, cyl.pos), plane.dir) / d;
	}
//	printf("d : %f\n", d);
	v = vect3d_mult_scal(vect3d_unit(cyl.dir), d);
//	printf("v :\nx : %f\ny : %f\nz : %f\n", v.x, v.y, v.z);
	v = vect3d_add(v, cyl.pos);
//	printf("v :\nx : %f\ny : %f\nz : %f\n", v.x, v.y, v.z);
//	printf("pos :\nx : %f\ny : %f\nz : %f\n", pos.x, pos.y, pos.z);
	norm = vect3d_sub(pos, v);
	return (norm);
}

t_vect3d	cone_normal(t_vect3d pos, t_obj cone)
{
	t_vect3d	norm;
	t_obj		plane;
	double		d;
	t_vect3d	u;
	t_vect3d	v;

	u = vect3d_sub(pos, cone.pos);
	plane.dir = u;
	plane.pos = pos;
	d = vect3d_scal_prod(cone.dir, plane.dir);
	if (d)
		d = vect3d_scal_prod(vect3d_sub(plane.pos, cone.pos), plane.dir) / d;
	else
	{
		cone.dir = vect3d_mult_scal(cone.dir, -1);
		d = vect3d_scal_prod(cone.dir, plane.dir);
		d = vect3d_scal_prod(vect3d_sub(plane.pos, cone.pos), plane.dir) / d;
	}
	v = vect3d_mult_scal(vect3d_unit(cone.dir), d);
	v = vect3d_add(v, cone.pos);
	norm = vect3d_sub(pos, v);
	return (norm);
}
