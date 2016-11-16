/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:41:47 by vroussea          #+#    #+#             */
/*   Updated: 2016/11/16 16:18:20 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scmk.h"
#include <stdlib.h>

float		catch_float(char *str)
{
	char	*line;
	float	val;

	ft_putstr(str);
	if (get_next_line(0, &line) == -1)
	{
		ft_putendl("error with gnl while creating struct");
		exit(0);
	}
	val = ft_atof(line);
	ft_strdel(&line);
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

t_vectorf3	dir(void)
{
	t_vectorf3	dir;

	dir.x = 0;
	dir.y = 0;
	dir.z = 0;
	while (dir.x == 0 && dir.y == 0 && dir.z == 0)
	{
		dir.x = catch_float("x : ");
		dir.y = catch_float("y : ");
		dir.z = catch_float("z : ");
		if (dir.x == 0 && dir.y == 0 && dir.z == 0)
			ft_putendl("vector must not be NULL");
	}
	return (dir);
}

int			select_obj(void)
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
