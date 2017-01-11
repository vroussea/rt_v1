/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_v1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:40:43 by vroussea          #+#    #+#             */
/*   Updated: 2017/01/11 14:31:29 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_v1.h"
#include <mlx.h>

void		caller(t_env *env, char *meml, int size_l, t_scene scene)
{
	//int	*col;

//	col = opencl(scene);
	scene.pov.pos.x += 1 - 1;
	ft_bzero(meml, size_l * SIZE_Y);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 1, 1);
}

static void	init_val(t_env *env, t_scene scene)
{
	int		bpp;
	int		edan;
	int		size_l;
	char	*meml;

	meml = mlx_get_data_addr(env->img, &bpp, &size_l, &edan);
	mlx_hook(env->win, 2, 0, key_funct, env);
	mlx_hook(env->win, 17, 0, quit_funct, env);
	caller(env, meml, size_l, scene);
	mlx_loop(env->mlx);
}

static int	check_ext(char *line)
{
	size_t	size;

	size = ft_strlen(line);
	if (line[size - 1] != 'c' || line[size - 2] != 's' || line[size - 3] != '.')
		return (1);
	return (0);
}

int			main(int argc, char **argv)
{
	t_env	*env;
	t_scene	scene;

	if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
		return (1);
	if (argc < 2 || check_ext(argv[1]))
		ft_putendl("Error : Please enter valid scene (.sc) file.");
	else
	{
		scene = get_struct(argv[1]);
		if (!(env->mlx = mlx_init()) ||
			!(env->win = mlx_new_window(env->mlx, SIZE_X, SIZE_Y, "RT_V1")) ||
			!(env->img = mlx_new_image(env->mlx, SIZE_X, SIZE_Y)))
			ft_putendl("Error : Can't initialize mlx.");
		else
			init_val(env, scene);
	}
	return (0);
}
