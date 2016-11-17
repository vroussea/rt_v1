/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 10:51:10 by vroussea          #+#    #+#             */
/*   Updated: 2016/11/17 15:06:00 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_v1.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

t_scene	reader(char *file)
{
	t_scene	scene;
	int		fd;
	ssize_t	size;

	fd = open(file, O_RDONLY);
	size = sizeof(t_pov) + sizeof(int) * 2;
	if ((read(fd, &scene, size)) != size)
		ft_putendl("Can't read scene");
	size = sizeof(t_obj) * scene.nb_obj;
	if ((read(fd, (scene.objs = (t_obj *)ft_memalloc(size)), size)) != size)
		ft_putendl("Can't read scene");
	size = sizeof(t_spot) * scene.nb_spot;
	if ((read(fd, (scene.spots = (t_spot *)ft_memalloc(size)), size)) != size)
		ft_putendl("Can't read scene");
	printf("pos x pov : %f\n", scene.pov.pos.x);
	printf("pos y pov : %f\n", scene.pov.pos.y);
	printf("pos z pov : %f\n", scene.pov.pos.z);
	printf("pos x dir : %f\n", scene.pov.dir.x);
	printf("pos y dir : %f\n", scene.pov.dir.y);
	printf("pos z dir : %f\n", scene.pov.dir.z);
	printf("nb objs : %d\n", scene.nb_obj);
	printf("nb spots : %d\n", scene.nb_spot);
	printf("obj num : 1\n");
	printf("obj x pos : %f\n", scene.objs[0].pos.x);
	printf("obj y pos : %f\n", scene.objs[0].pos.y);
	printf("obj z pos : %f\n", scene.objs[0].pos.z);
	printf("obj x dir : %f\n", scene.objs[0].dir.x);
	printf("obj y dir : %f\n", scene.objs[0].dir.y);
	printf("obj z dir : %f\n", scene.objs[0].dir.z);
	printf("obj color : 0x%x\n", scene.objs[0].col);
	printf("obj num : 2\n");
	printf("obj x pos : %f\n", scene.objs[1].pos.x);
	printf("obj y pos : %f\n", scene.objs[1].pos.y);
	printf("obj z pos : %f\n", scene.objs[1].pos.z);
	printf("obj ray : %d\n", scene.objs[1].ray);
	printf("obj color : 0x%x\n", scene.objs[1].col);
	printf("spot x pos : %f\n", scene.spots[0].pos.x);
	printf("spot y pos : %f\n", scene.spots[0].pos.y);
	printf("spot z pos : %f\n", scene.spots[0].pos.z);
	printf("spot x dir : %f\n", scene.spots[0].dir.x);
	printf("spot y dir : %f\n", scene.spots[0].dir.y);
	printf("spot z dir : %f\n", scene.spots[0].dir.z);
	return (scene);
}
