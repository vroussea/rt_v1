/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 18:48:41 by vroussea          #+#    #+#             */
/*   Updated: 2016/11/08 17:14:11 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "rt_v1.h"

int			key_funct(int keycode, t_env *env)
{
	if (keycode == 53)
		quit_funct(env);
	return (1);
}

int			quit_funct(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->win);
	ft_memdel((void **)&env);
	ft_putendl("Program Closed");
	exit(0);
	return (0);
}
