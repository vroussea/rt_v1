/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:34:02 by vroussea          #+#    #+#             */
/*   Updated: 2017/01/24 11:09:26 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_v1.h"

static int	which_quad(t_obj ray, t_scene scene, t_functs *functs)
{
	int		crt;
	int		col;
	double	dist;
	double	tmp_dist;

	crt = 0;
	col = 0;
	dist = 0x76FFFFFF;
	tmp_dist = dist;
	while (crt < scene.nb_quad)
	{
		tmp_dist = functs[QUAD[crt].type](ray, QUAD[crt]);
		if (tmp_dist > 0 && tmp_dist < dist)
		{
			dist = tmp_dist;
			col = QUAD[crt].col;
		}
		crt++;
	}
	return (col);
}

static int	rotate_ray(double x, double y, t_scene scene, t_functs *functs)
{
	t_obj		ray;
	
	x *= (PI / 3) / SIZE_X;
	x -= (PI / 6);
	y *= (PI / 3) / SIZE_Y;
	y -= (PI / 6);
	ray.pos = CAM.pos;
	ray.dir = vect3d_rot_y(CAM.dir, y);
	ray.dir = vect3d_rot_z(ray.dir, x);
	return (which_quad(ray, scene, functs));
}

void		pixel_browser(t_scene scene, char *meml)
{
	double	x;
	double	y;
	t_functs	*functs;

	fill_quad_functs_tab(&functs);
	//t_vector3d	grid_pos = CAM.pos + ((vecDir*viewplaneDist)+(upVec*(viewplaneHeight/2.0f))) - (rightVec*(viewplaneWidth/2.0f))
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
	ft_memdel((void **)&functs);
}
