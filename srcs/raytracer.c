/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:34:02 by vroussea          #+#    #+#             */
/*   Updated: 2017/02/08 19:22:56 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_v1.h"
#include <stdio.h>/////

static int	which_quad(t_obj ray, t_scene scene, t_functs *functs)
{
	int			crt;
	int			col;
	double		dist;
	double		tmp_dist;

	crt = 0;
	col = 0;
	dist = 0x76FFFFFF;
	tmp_dist = dist;
	while (crt < scene.nb_quad)
	{
		tmp_dist = functs[QUAD[crt].type](ray, QUAD[crt], scene);
		if (tmp_dist > 0 && tmp_dist < dist)
		{
			dist = tmp_dist;
			//col = QUAD[crt].col;
			col = (light(ray, dist, scene, functs) ? 0 : QUAD[crt].col);
		//	printf("col : 0x%X\n", col);
		}
		crt++;
	}
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
	t_functs	*functs;

	fill_quad_functs_tab(&functs);
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
	//pixel((int)440, (int)250, rotate_ray((double)440, (double)200, scene, functs), meml);
	//pixel((int)SIZE_X / 2, (int)SIZE_Y / 2, rotate_ray((double)SIZE_X / 2, (double)SIZE_Y / 2, scene, functs), meml);
	ft_memdel((void **)&functs);
}
