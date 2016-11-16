/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:34:07 by vroussea          #+#    #+#             */
/*   Updated: 2016/11/16 11:00:29 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scmk.h"

void	sphere_type(t_obj *obj)
{
	obj->ray = catch_int("Enter sphere ray : ");
}

void	plane_type(t_obj *obj)
{
	ft_putendl("Enter direction coordinates");
	obj->dir = dir();
}
