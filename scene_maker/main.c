/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:26:12 by vroussea          #+#    #+#             */
/*   Updated: 2016/11/13 17:57:57 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scmk.h"
#include <fcntl.h>

static int		opener()
{
	char	*line;
	int		fd;
	mode_t	mode;
	char	*path;

	mode = S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR;
	ft_putendl("Enter scene name : ");
	get_next_line(0, &line);
	path = ft_strdup("../scenes/");
	fd = 5;//open(ft_strcat(path, line), O_CREAT | O_WRONLY, mode);
	ft_strdel(&line);
	return (fd);
}

int				main(void)
{
	int		type;
	t_scene	scene;
	int		fd;

	type = 0;
	fd = opener();
	scene.pov = create_pov();
//	scene.objects = create_obj();
//	scene.spots = create_spt();
	return (0);
}
