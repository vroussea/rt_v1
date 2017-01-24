/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quad_collide.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:10:29 by vroussea          #+#    #+#             */
/*   Updated: 2017/01/24 11:27:16 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_v1.h"
#include <math.h>

double	collide_sphere(t_obj ray, t_obj quad)
{
	double		a;
	double		b;
	double		c;
	double		d;

	a = ray.DX * ray.DX + ray.DY * ray.DY + ray.DZ * ray.DZ;
	b = 2 * ray.DX * (ray.PX - quad.PX) +
		2 * ray.DY * (ray.PY - quad.PY) +
		2 * ray.DZ * (ray.PZ - quad.PZ);
	c = quad.PX * quad.PX + quad.PY * quad.PY + quad.PZ * quad.PZ +
		ray.PX * ray.PX + ray.PY * ray.PY + ray.PZ * ray.PZ -
		2 * (quad.PX * ray.PX + quad.PY * ray.PY + quad.PZ * ray.PZ )
		- quad.size * quad.size;
	d = b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	return ((- b - sqrt(d)) / (2 * a));
}

double	collide_plan(t_obj ray, t_obj quad)
{
	return ((quad.DX * (quad.PX - ray.PX) + quad.DY * (quad.PY - ray.PY) + 
			quad.DZ * (quad.PZ - ray.PZ)) /
			vect3d_scal_prod(quad.dir, ray.dir));
}