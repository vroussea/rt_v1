/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:34:02 by vroussea          #+#    #+#             */
/*   Updated: 2017/01/11 18:01:09 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_v1.h"

int	which_quad(t_obj ray, t_scene scene)
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
		if (QUAD[crt].type == SPHERE)
			tmp_dist = collide_sphere(ray, QUAD[crt]);
//		else if (QUAD[crt].type == PLANE)
//			tmp_dist = collide_plane(ray, QUAD[crt]);
		if (tmp_dist > 0 && tmp_dist < dist)
		{
			dist = tmp_dist;
			col = QUAD[crt].col;
		}
		crt++;
	}
	return (col);
}
