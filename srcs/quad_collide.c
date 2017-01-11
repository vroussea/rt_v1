/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quad_collide.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:10:29 by vroussea          #+#    #+#             */
/*   Updated: 2017/01/11 18:46:29 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "..includes.rt_v1.h"

double	collide_sphere(t_obj ray, t_obj quad)
{
	double		a;
	double		b;
	double		c;
	double		d;

	a = ft_pow(ray.DX, 2) + ft_pow(ray.DY, 2) + ft_pow(ray.DZ, 2);
	b = 2 * ray.DX * (ray.PX - quad.PX) +
		2 * ray.DY * (ray.PY - quad.PY) +
		2 * ray.DZ * (ray.PZ - quad.PZ);
	c = ft_pow(quad.PX, 2) + ft_pow(quad.PY, 2) + ft_pow(quad.PZ, 2) +
		ft_pow(ray.PX, 2) + ft_pow(ray.PY, 2) + ft_pow(ray.PZ, 2) -
		2 * (quad.PX * ray.PX + quad.PY * ray.PY + quad.PZ * ray.PZ )
		- ft_pow(quad.size, 2);
	d = b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	c = (- b - sqrt(d)) / (2 * a);
	d = (- b + sqrt(d)) / (2 * a);
	return (c < d ? c : d);
}
