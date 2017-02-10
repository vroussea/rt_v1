/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 15:04:15 by vroussea          #+#    #+#             */
/*   Updated: 2017/02/10 18:04:07 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_v1.h"
#include <math.h>
#include <stdio.h>////

int			col_grad(int col, int strength)
{
	unsigned char	*tmp;

	if (strength < 30)
		strength = 30;
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

/*static int	light_strength()
{

}*/

int			slct_light(t_obj ray, double dist, t_scene scene, t_functs *functs)
{
	int			crt;
	int			strength;

	ray.pos = vect3d_add(ray.pos, vect3d_mult_scal(ray.dir, dist));
//	printf("ray pos :\nx : %f\ny : %f\nz : %f\n", ray.PX, ray.PY, ray.PZ);
	crt = 0;
	strength = 0;
	while (crt < scene.nb_spot)
	{
//		printf("light N%i :\nx : %f\ny : %f\nz : %f\n", crt, SPOT[crt].PX, SPOT[crt].PY, SPOT[crt].PZ);
		ray.dir = vect3d_sub(SPOT[crt].pos, ray.pos);
		if (is_light(ray, scene, functs) == 0)
			strength = 100;//light_strength();
		crt++;
	}
//	printf("strength : %d\n", strength);
	return (strength > 100 ? 100 : strength);
}
