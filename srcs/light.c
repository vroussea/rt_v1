/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 15:04:15 by vroussea          #+#    #+#             */
/*   Updated: 2017/02/07 18:26:54 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_v1.h"
#include <math.h>
#include <stdio.h>////

/*static int	is_collide(t_obj ray, t_obj light, double dist, t_functs *functs)
{
	int		crt;
	double	tmp_dist;

	ray.dir = vect3d_unit(vect3d_sub(light.pos, ray.pos));
	while (crt < scene.nb_quad)
	{
		if (QUAD[crt].type >= 0 && QUAD[crt].type <= 3)
		{
			tmp_dist = functs[QUAD[crt].type](ray, QUAD[crt], scene);
			if (tmp_dist > 0 && tmp_dist < dist)
			{
				if (QUAD[crt].type == SPHERE)
					printf("dist : %f\n", tmp_dist);
				dist = tmp_dist;
				if (tmp_dist < dist)
					return (1);
			}
		}
		crt++;
	}
}*/

int			light(t_obj ray, double dist, t_scene scene, t_functs *functs)
{
	int			crt_l;
	int			crt_q;
	double	tmp_dist;

	ray.pos = vect3d_add(ray.pos, vect3d_mult_scal(ray.dir, dist));
//	printf("ray pos :\nx : %f\ny : %f\nz : %f\n", ray.PX, ray.PY, ray.PZ);
	crt_l = 0;
	tmp_dist = 0xffffffff;
	while (crt_l < scene.nb_spot)
	{
		ray.dir = vect3d_unit(vect3d_sub(SPOT[crt_l].pos, ray.pos));
		dist = sqrt(vect3d_scal_prod(SPOT[crt_l].pos, ray.pos));
//		printf("ray dir :\nx : %f\ny : %f\nz : %f\n", ray.DX, ray.DY, ray.DZ);
//		printf("dist impact - lumiere: %f\n", dist);
//		printf("light N%i :\nx : %f\ny : %f\nz : %f\n", crt_l, SPOT[crt_l].PX, SPOT[crt_l].PY, SPOT[crt_l].PZ);
		crt_q = 0;
		while (crt_q < scene.nb_quad)
		{
			tmp_dist = functs[QUAD[crt_q].type](ray, QUAD[crt_q], scene);
//			printf("dist to next quad : %f\n", tmp_dist);
			if (tmp_dist > 0.001 && tmp_dist < dist)
					return (1);
			crt_q++;
		}
		//if (is_collide(ray, SPOT[crt], dist, functs))
		//	return (1);
		crt_l++;
	}
	return (0);
}
