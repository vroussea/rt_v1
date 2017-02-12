/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 15:04:15 by vroussea          #+#    #+#             */
/*   Updated: 2017/02/12 17:59:24 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_v1.h"
#include <math.h>
#include <stdio.h>////

int			col_grad(int col, int strength)
{
	unsigned char	*tmp;

	if (strength < 15)
		strength = 15;
	tmp = (unsigned char *)&col;
	tmp[0] = tmp[0] * strength / 100;
	tmp[1] = tmp[1] * strength / 100;
	tmp[2] = tmp[2] * strength / 100;
	return (col);
}

static int		is_light(t_obj ray, t_scene scene, t_functs *functs)
{
	int			crt;
	double		dist;

//	printf("ray dir :\nx : %f\ny : %f\nz : %f\n", ray.DX, ray.DY, ray.DZ);
	crt = 0;
	dist = 0xffffffff;
	while (crt < scene.nb_quad)
	{
		dist = functs[QUAD[crt].type](ray, QUAD[crt], scene);
//		printf("dist to next quad : %f\n", dist);
		if (dist > 0.0001 && dist < 0.9999)
		{
//			printf("quad :%d\n", crt);
			return (1);
		}
		crt++;
	}
	return (0);
}

static int	light_strength(t_obj ray, t_obj quad)
{
	t_norm_functs	norm_functs[4];
	t_vect3d		norm;
	double			ang;
	double			ang2;
	double			strength;

	norm_functs[SPHERE] = sphere_normal;
	norm_functs[PLANE] = plane_normal;
	norm_functs[CYLINDER] = cylinder_normal;
	norm_functs[CONE] = cone_normal;
	norm = norm_functs[quad.type](ray.pos, quad);
//	printf("norm1 :\nx : %f\ny : %f\nz : %f\n", norm.x, norm.y, norm.z);
	ang = vect3d_ang(ray.dir, norm) / RAD;
	norm = vect3d_mult_scal(norm, -1);
//	printf("norm2 :\nx : %f\ny : %f\nz : %f\n", norm.x, norm.y, norm.z);
	ang2 = vect3d_ang(ray.dir, norm) / RAD;
//	printf("angle : %f\n", ang);
//	printf("angle2 : %f\n", ang2);
	if (quad.type == CYLINDER || quad.type == CONE)
		strength = 100 - ang;
	else
		strength = 100 - (ang < ang2 ? ang : ang2);
	return (strength);
}

int			slct_light(t_obj ray, double dist, t_scene scene, t_obj quad)
{
	int			crt;
	int			strength;
	int			crt_strength;
	t_functs	functs[4];

	functs[SPHERE] = collide_sphere;
	functs[PLANE] = collide_plan;
	functs[CYLINDER] = collide_cylinder;
	functs[CONE] = collide_cone;
	ray.pos = vect3d_add(ray.pos, vect3d_mult_scal(ray.dir, dist));
	//printf("ray pos :\nx : %f\ny : %f\nz : %f\n", ray.PX, ray.PY, ray.PZ);
	crt = 0;
	strength = 0;
	while (crt < scene.nb_spot)
	{
	//	printf("light N%i :\nx : %f\ny : %f\nz : %f\n", crt, SPOT[crt].PX, SPOT[crt].PY, SPOT[crt].PZ);
		ray.dir = vect3d_sub(SPOT[crt].pos, ray.pos);
		if (is_light(ray, scene, functs) == 0)
		{
			crt_strength = light_strength(ray, quad);
			strength = (strength > crt_strength ? strength : crt_strength);
		}
	//	printf("strength : %d\n", strength);
		crt++;
	}
//	if (strength < 10)
//		strength += 10;
//	printf("finalstrength : %d\n", strength);
	return (strength > 100 ? 100 : strength);
}
