/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:34:02 by vroussea          #+#    #+#             */
/*   Updated: 2017/02/12 17:50:57 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_v1.h"

static int	which_quad(t_obj ray, t_scene scene, t_functs *functs)
{
	int			closer;
	int			tmp_crt;
	int			col;
	double		dist;
	double		tmp_dist;

	closer = -1;
	tmp_crt = 0;
	col = 0;
	dist = 0x76FFFFFF;
	tmp_dist = dist;
	while (tmp_crt < scene.nb_quad)
	{
		tmp_dist = functs[QUAD[tmp_crt].type](ray, QUAD[tmp_crt], scene);
		if (tmp_dist > 0 && tmp_dist < dist)
		{
			closer = tmp_crt;
			dist = tmp_dist;
		}
		tmp_crt++;
	}
	if (closer != -1)
		col = col_grad(
				QUAD[closer].col, slct_light(ray, dist, scene, QUAD[closer]));
	return (col);
}

static int	rotate_ray(double x, double y, t_scene scene, t_functs *functs)
{
	t_obj		ray;
	
	ray.pos = CAM.pos;
	ray.dir = vect3d_add(LEFTUP,
			vect3d_mult_scal(RIGHT, x * GRID_WIDTH * 2 / (double)SIZE_X));
	ray.dir = vect3d_sub(ray.dir,
			vect3d_mult_scal(UP, y * GRID_HEIGHT * 2 / (double)SIZE_Y));
	return (which_quad(ray, scene, functs));
}

void			pixel_browser(t_scene scene, char *meml)
{
	double		x;
	double		y;
	t_functs	functs[4];

	functs[SPHERE] = collide_sphere;
	functs[PLANE] = collide_plan;
	functs[CYLINDER] = collide_cylinder;
	functs[CONE] = collide_cone;
	x = 0;
	while (x < SIZE_X)
	{
		y = 0;
		while (y < SIZE_Y)
		{
			pixel((int)x, (int)y, rotate_ray(x, y, scene, functs), meml);
			y++;
		}
		x++;
	}
//	pixel((int)399, (int)340, 0, meml);
//	pixel((int)394, (int)349, 0, meml);
//	pixel((int)390, (int)349, 0, meml);
//	pixel((int)399, (int)340, rotate_ray((double)399, (double)340, scene, functs), meml);
//	pixel((int)394, (int)349, rotate_ray((double)394, (double)349, scene, functs), meml);
//	pixel((int)390, (int)349, rotate_ray((double)390, (double)349, scene, functs), meml);
	//pixel((int)SIZE_X / 2, (int)SIZE_Y / 2, rotate_ray((double)SIZE_X / 2, (double)SIZE_Y / 2, scene, functs), meml);
}
