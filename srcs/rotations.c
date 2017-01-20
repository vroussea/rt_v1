/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:45:02 by vroussea          #+#    #+#             */
/*   Updated: 2017/01/16 14:17:26 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_v1.h"
#include <math.h>

t_vector3d	rotate_y(t_vector3d dir, double ang)
{
	dir.x = dir.x * cos(ang) + dir.z * sin(ang);
	dir.z = dir.z * cos(ang) - dir.x * sin(ang);
	return (dir);
}

t_vector3d	rotate_z(t_vector3d dir, double ang)
{
	dir.x = dir.x * cos(ang) - dir.y * sin(ang);
	dir.y = dir.y * cos(ang) + dir.x * sin(ang);
	return (dir);
}
