/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scmk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:31:31 by vroussea          #+#    #+#             */
/*   Updated: 2016/12/17 13:14:34 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scmk.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static int		opener(void)
{
	char	*line;
	int		fd;
	mode_t	mode;
	char	*path;
	char	*ext;

	mode = S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR;
	ft_putendl("Enter scene name : ");
	get_next_line(0, &line);
	path = ft_strdup("./scenes/");
	ext = ft_strdup(".sc");
	fd = open(ft_strcat(ft_strcat(path, line), ext), O_CREAT | O_WRONLY, mode);
	ft_strdel(&line);
	ft_strdel(&path);
	return (fd);
}

static int		select_obj(void)
{
	char	*line;
	int		val;

	val = -1;
	while (val < 0 || val > 1)
	{
		ft_putendl("Enter object type number : Sphere (0), Plane(1)");
		if (get_next_line(0, &line) == -1)
		{
			ft_putendl("error with gnl while creating struct");
			exit(0);
		}
		val = ft_atoi(line);
		ft_strdel(&line);
	}
	return (val);
}

static void		objs_tab(t_scene *scene)
{
	int		i;
	char	*str;

	scene->nb_quad = 0;
	while (scene->nb_quad < 1)
		scene->nb_quad = loop_nb("\nEnter object quantity : ");
	i = 0;
	scene->quads = (t_obj *)ft_memalloc(sizeof(t_obj) * scene->nb_quad);
	while (i < scene->nb_quad)
	{
		ft_putstr("\nObj number : ");
		str = ft_itoa(i + 1);
		ft_putendl(str);
		ft_strdel(&str);
		scene->quads[i] = create_obj(select_obj());
		i++;
	}
}

static void		spots_tab(t_scene *scene)
{
	int		i;
	char	*str;

	scene->nb_spot = 0;
	while (scene->nb_spot < 1)
		scene->nb_spot = loop_nb("\nEnter spot quantity : ");
	i = 0;
	scene->spots = (t_obj *)ft_memalloc(sizeof(t_obj) * scene->nb_spot);
	while (i < scene->nb_spot)
	{
		ft_putstr("\nSpot number : ");
		str = ft_itoa(i + 1);
		ft_putendl(str);
		ft_strdel(&str);
		scene->spots[i] = create_spot();
		i++;
	}
}

int				main(void)
{
	t_scene	scene;
	int		fd;
	float	struct_ver;

	fd = opener();
	scene.pov = create_pov();
	objs_tab(&scene);
	spots_tab(&scene);
	struct_ver = SCENE_VER;
	write(fd, &struct_ver, sizeof(float));
	write(fd, &scene, sizeof(t_obj) + sizeof(int) * 2);
	write(fd, scene.quads, sizeof(t_obj) * scene.nb_quad);
	write(fd, scene.spots, sizeof(t_obj) * scene.nb_spot);
	ft_memdel((void **)&(scene.quads));
	ft_memdel((void **)&(scene.spots));
	close(fd);
	return (0);
}
