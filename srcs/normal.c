/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:37:54 by vroussea          #+#    #+#             */
/*   Updated: 2017/02/11 16:39:12 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_v1.h"

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

t_vect3d	cylinder_normal(t_vect3d pos, t_obj cylinder)
{
	t_vect3d	norm;

	norm = vect3d_sub(pos, sphere.pos);
	return (norm);
}

t_vect3d	cone_normal(t_vect3d pos, t_obj cone)
{
	t_vect3d	norm;
	t_vect3d	u;
	t_vect3d	v;

	u = vect3d_sub(
	norm = vect3d_sub(pos, sphere.pos);
	return (norm);
}
