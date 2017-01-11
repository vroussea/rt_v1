/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:45:02 by vroussea          #+#    #+#             */
/*   Updated: 2017/01/11 16:34:42 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_v1.h"

t_vector3d	rotate_y(t_vector3d vect, double ang)
{
	vect.x = vect.x * cos(ang) + vect.z * sin(ang);
	vect.z = vect.z * cos(ang) - vect.x * sin(ang);
	return (vect);
}

t_vector3d	rotate_z(t_vector3d vect, double ang)
{
	vect.x = vect.x * cos(ang) - vect.y * sin(ang);
	vect.y = vect.y * cos(ang) + vect.x * sin(ang);
	return (vect);
}
