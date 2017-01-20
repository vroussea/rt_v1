/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:41:47 by vroussea          #+#    #+#             */
/*   Updated: 2017/01/20 15:08:36 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scmk.h"
#include <stdlib.h>

double		catch_double(char *str)
{
	char	*line;
	float	val;

	ft_putstr(str);
	if (get_next_line(0, &line) == -1)
	{
		ft_putendl("error with gnl while creating struct");
		exit(0);
	}
	val = ft_atod(line);
	ft_strdel(&line);
	return (val);
}

int			catch_int(char *str)
{
	char	*line;
	float	val;

	val = -1;
	while (val < 0)
	{
		ft_putstr(str);
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

int			catch_col(char *str)
{
	char	*line;
	float	val;

	val = -1;
	while (val < 0 || val > 255)
	{
		ft_putstr(str);
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

t_vect3d	dir(void)
{
	t_vect3d	dir;

	dir.x = 0;
	dir.y = 0;
	dir.z = 0;
	while (dir.x == 0 && dir.y == 0 && dir.z == 0)
	{
		dir.x = catch_double("x : ");
		dir.y = catch_double("y : ");
		dir.z = catch_double("z : ");
		if (dir.x == 0 && dir.y == 0 && dir.z == 0)
			ft_putendl("vector must not be NULL");
	}
	return (dir);
}

int			loop_nb(char *str)
{
	int		i;
	char	*line;

	ft_putendl(str);
	if (get_next_line(0, &line) == -1)
	{
		ft_putendl("error with gnl while creating struct");
		exit(0);
	}
	i = ft_atoi(line);
	ft_strdel(&line);
	return (i);
}
