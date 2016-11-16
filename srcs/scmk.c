/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:26:12 by vroussea          #+#    #+#             */
/*   Updated: 2016/11/16 16:10:35 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scmk.h"
#include <fcntl.h>
#include <unistd.h>

static int		opener(void)
{
	char	*line;
	int		fd;
	mode_t	mode;
	char	*path;

	mode = S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR;
	ft_putendl("Enter scene name : ");
	get_next_line(0, &line);
	path = ft_strdup("../scenes/");
	fd = open(ft_strcat(path, line), O_CREAT | O_WRONLY, mode);
	ft_strdel(&line);
	ft_strdel(&path);
	return (fd);
}

static void		objs_tab(t_scene *scene)
{
	int		i;
	char	*str;

	scene->nb_obj = loop_nb("\nEnter object quantity : ");
	i = 0;
	scene->objs = (t_obj *)ft_memalloc(sizeof(t_obj) * scene->nb_obj);
	while (i < scene->nb_obj)
	{
		ft_putstr("\nObj number : ");
		str = ft_itoa(i + 1);
		ft_putendl(str);
		ft_strdel(&str);
		scene->objs[i] = create_obj(select_obj());
		i++;
	}
}

static void		spots_tab(t_scene *scene)
{
	int		i;
	char	*str;

	scene->nb_spot = loop_nb("\nEnter spot quantity : ");
	i = 0;
	scene->spots = (t_spot *)ft_memalloc(sizeof(t_spot) * scene->nb_spot);
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

	fd = opener();
	scene.pov = create_pov();
	objs_tab(&scene);
	spots_tab(&scene);
	write(fd, &scene, sizeof(t_pov) + sizeof(int) * 2);
	if (scene.nb_obj > 0)
		write(fd, &scene, sizeof(t_obj) * scene.nb_obj);
	if (scene.nb_spot > 0)
		write(fd, &scene, sizeof(t_spot) * scene.nb_spot);
	ft_memdel((void **)&(scene.objs));
	ft_memdel((void **)&(scene.spots));
	return (0);
}
