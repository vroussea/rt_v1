/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 10:51:10 by vroussea          #+#    #+#             */
/*   Updated: 2016/11/22 11:54:28 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_v1.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static void	error(int error)
{
	if (error == 1)
		ft_putendl("Error with file, can't read properly.");
	if (error == 0)
		ft_putendl("Can't allocate memory for the struct");
	if (error == 2)
		ft_putendl("Wrong scene version");
	exit(1);
}

t_scene		get_struct(char *file)
{
	t_scene	scene;
	int		fd;
	ssize_t	size;
	float	ver;
	float	crt_ver;

	ver = SCENE_VER;
	fd = open(file, O_RDONLY);
	if ((read(fd, &crt_ver, sizeof(float)) != sizeof(float)) || crt_ver != ver)
		error(2);
	size = sizeof(t_pov) + sizeof(int) * 2;
	if ((read(fd, &scene, size)) != size)
		error(1);
	size = sizeof(t_obj) * scene.nb_obj;
	if (!(scene.objs = (t_obj *)ft_memalloc(size)))
		error(0);
	if ((read(fd, scene.objs, size)) != size)
		error(1);
	size = sizeof(t_spot) * scene.nb_spot;
	if (!(scene.spots = (t_spot *)ft_memalloc(size)))
		error(0);
	if ((read(fd, scene.spots, size)) != size)
		error(1);
	return (scene);
}
