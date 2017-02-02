/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 14:56:08 by vroussea          #+#    #+#             */
/*   Updated: 2017/02/02 15:56:16 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_v1.h"
#include <stdio.h> ////////////

t_scene	grid_left_up_corner(t_scene scene)
{
	t_vect3d	forward;
	t_vect3d	orth;
	double		ang;

	printf("cam pos : \nx : %f\ny : %f\nz : %f\n", CAM.pos.x, CAM.pos.y, CAM.pos.z);
	forward = vect3d_fill(0.0, 0.0, 1.0);
	UP = vect3d_fill(0.0, 1.0, 0.0);
	RIGHT = vect3d_fill(1.0, 0.0, 0.0);
	orth = vect3d_unit(vect3d_vect_prod(forward, CAM.dir));
	ang = vect3d_ang(forward, CAM.dir);
	printf("angle : %f\n", ang / RAD);
	if (ang != 0.0)
	{
		RIGHT = vect3d_rot(orth, RIGHT, ang);
		UP = vect3d_rot(orth, UP, ang);
	}
	//LEFTUP = CAM.pos;
	LEFTUP = vect3d_fill(0.0, 0.0, 0.0);
	LEFTUP = vect3d_add(LEFTUP, vect3d_mult_scal(CAM.dir, GRID_DIST));
	LEFTUP = vect3d_add(LEFTUP, vect3d_mult_scal(UP, GRID_HEIGHT));
	LEFTUP = vect3d_sub(LEFTUP, vect3d_mult_scal(RIGHT, GRID_WIDTH));
	printf("UP : \nx : %f\ny : %f\nz : %f\n", UP.x, UP.y, UP.z);
	printf("RIGHT : \nx : %f\ny : %f\nz : %f\n", RIGHT.x, RIGHT.y, RIGHT.z);
	printf("LEFTUP : \nx : %f\ny : %f\nz : %f\n", LEFTUP.x, LEFTUP.y, LEFTUP.z);
	return (scene);
}
