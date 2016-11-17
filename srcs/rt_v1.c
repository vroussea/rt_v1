/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_v1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:40:43 by vroussea          #+#    #+#             */
/*   Updated: 2016/11/17 12:40:31 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_v1.h"
#include <mlx.h>

/*void		caller(t_env *env)
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
	//ft_putendl(((t_pov *)env->lst->content)->name);
	env->meml = mlx_get_data_addr(env->img, &bpp, &(env->sizel), &edan);
	mlx_hook(env->win, 2, 0, key_funct, env);
	mlx_hook(env->win, 17, 0, quit_funct, env);
	caller(env);
	mlx_loop(env->mlx);
}*/

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
//	t_env	*env;
	void	*mlx;
	void	*win;
	void	*img;

//	if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
//		quit_funct(env);
//	env->sx = 1280;
//	env->sy = 720;
	if (argc < 2 || check_ext(argv[1]))
		ft_putendl("Error : Please enter valid scene (.sc) file.");
	else
	{
		if (!(mlx = mlx_init()) ||
			!(win = mlx_new_window(mlx, SIZE_X, SIZE_Y, "RT_V1")) ||
			!(img = mlx_new_image(mlx, SIZE_X, SIZE_Y)))
			ft_putendl("Error : Can't initialize mlx.");
		else
			reader(argv[1]);
			//init_val(env, argv[1]);
	}
	return (0);
}
