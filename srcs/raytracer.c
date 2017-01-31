/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:34:02 by vroussea          #+#    #+#             */
/*   Updated: 2017/01/31 18:50:33 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_v1.h"
#include <stdio.h> ////////

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
		if (QUAD[crt].type >= 0 && QUAD[crt].type <= 3)
		{
			tmp_dist = functs[QUAD[crt].type](ray, QUAD[crt]);
			if (tmp_dist > 0 && tmp_dist < dist)
			{
				dist = tmp_dist;
				col = QUAD[crt].col;
			}
		}
		crt++;
	}
	return (col);
}

static t_vect3d	grid_left_up_corner(t_scene scene)
{
	t_vect3d	grid_pos;
	t_vect3d	vect_up;
	t_vect3d	vect_right;
	t_vect3d	tmp;

	vect_up = vect3d_mult_scal(vect3d_rot_y(CAM.dir, -90 * RAD), CAM.DX);
	vect_up = vect3d_add(vect_up, vect3d_mult_scal(vect3d_rot_z(CAM.dir, -90 * RAD), CAM.DY));
	vect_up = vect3d_add(vect_up, vect3d_mult_scal(vect3d_rot_x(CAM.dir, -90 * RAD), CAM.DZ));
	vect_right = vect3d_rot_z(CAM.dir, 90 * RAD);
	tmp = vect3d_mult_scal(CAM.dir, GRID_DIST);
	grid_pos = vect3d_add(CAM.pos, tmp);
	tmp = vect3d_mult_scal(vect_up, GRID_HEIGHT / 2.0);
	grid_pos = vect3d_add(grid_pos, tmp);
	tmp = vect3d_mult_scal(vect_right, GRID_WIDTH / 2.0);
	grid_pos = vect3d_sub(grid_pos, tmp);
//	printf("cam dir :\nx : %f\ny : %f\nz : %f\n", CAM.DX, CAM.DY, CAM.DZ);
//	printf("vect up :\nx : %f\ny : %f\nz : %f\n", vect_up.x, vect_up.y, vect_up.z);
//	printf("vect right :\nx : %f\ny : %f\nz : %f\n", vect_right.x, vect_right.y, vect_right.z);
//	printf("grid pos :\nx : %f\ny : %f\nz : %f\n", grid_pos.x, grid_pos.y, grid_pos.z);
	return (grid_pos);
}

static int	rotate_ray(double x, double y, t_scene scene, t_functs *functs)
{
	t_obj		ray;
	t_vect3d	grid_pos;
	t_vect3d	vect_up;
	t_vect3d	vect_right;
	
	grid_pos = grid_left_up_corner(scene);
	ray.pos = CAM.pos;
	//vect_up = vect3d_rot_y(CAM.dir, -90 * RAD);
	vect_up = vect3d_mult_scal(vect3d_rot_y(CAM.dir, -90 * RAD), CAM.DX);
	vect_up = vect3d_add(vect_up, vect3d_mult_scal(vect3d_rot_z(CAM.dir, -90 * RAD), CAM.DY));
	vect_up = vect3d_add(vect_up, vect3d_mult_scal(vect3d_rot_x(CAM.dir, -90 * RAD), CAM.DZ));
	vect_right = vect3d_rot_z(CAM.dir, 90 * RAD);
	ray.dir = vect3d_add(grid_pos, vect3d_mult_scal(vect_right, GRID_WIDTH / (float)SIZE_X * x));
	ray.dir = vect3d_sub(ray.dir, vect3d_mult_scal(vect_up, GRID_HEIGHT / (float)SIZE_Y * y));
	/*x *= (PI / 3) / SIZE_X;
	x -= (PI / 6);
	y *= (PI / 3) / SIZE_Y;
	y -= (PI / 6);
	ray.dir = vect3d_rot_y(CAM.dir, y);
	ray.dir = vect3d_rot_z(ray.dir, x);*/
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
	ft_memdel((void **)&functs);
}
