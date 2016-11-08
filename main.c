/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 15:40:59 by vroussea          #+#    #+#             */
/*   Updated: 2016/11/08 17:49:12 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"
#include <mlx.h>

void		caller(t_env *env)
{
	ft_bzero(env->meml, env->sizel * env->sy);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 1, 1);
}

static void	init_val(t_env *env, char *file)
{
	int		bpp;
	int		edan;

	if (!(parser(file, env)))
	{
		ft_putendl("Error Scene");
		quit_funct(env);
	}
	//ft_putendl(env->lst->content->name);
	env->meml = mlx_get_data_addr(env->img, &bpp, &(env->sizel), &edan);
	mlx_hook(env->win, 2, 0, key_funct, env);
	mlx_hook(env->win, 17, 0, quit_funct, env);
	caller(env);
	mlx_loop(env->mlx);
}

int			main(int argc, char **argv)
{
	t_env	*env;

	if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
		quit_funct(env);
	env->sx = 1280;
	env->sy = 720;
	if (argc < 2 || !(env->mlx = mlx_init()) ||
		!(env->win = mlx_new_window(env->mlx, env->sx, env->sy, "RT_V1")) ||
		!(env->img = mlx_new_image(env->mlx, env->sx, env->sy)))
		ft_putendl("Error : Please enter valid scene file.");
	else
		init_val(env, argv[1]);
	return (0);
}
