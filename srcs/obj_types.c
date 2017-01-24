/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:34:07 by vroussea          #+#    #+#             */
/*   Updated: 2017/01/24 11:45:29 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scmk.h"

void	sphere_type(t_obj *obj)
{
	obj->size = catch_double("Enter sphere ray : ");
}

void	plane_type(t_obj *obj)
{
	ft_putendl("Enter direction coordinates");
	obj->dir = dir();
}
