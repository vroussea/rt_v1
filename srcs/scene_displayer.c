/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_displayer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 13:06:25 by vroussea          #+#    #+#             */
/*   Updated: 2017/01/27 15:06:38 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scmk.h"

static void		show_spots(t_scene scene)
{
	int	i;

	i = 0;
	while (i++ < scene.nb_spot)
	{
		ft_putstr("SPOT number ");
		ft_putendl(ft_itoa(i - 1));
		ft_putstr("Pos x : ");
		ft_putendl(ft_itoa(SPOT[i - 1].PX));
		ft_putstr("Pos y : ");
		ft_putendl(ft_itoa(SPOT[i - 1].PY));
		ft_putstr("Pos z : ");
		ft_putendl(ft_itoa(SPOT[i - 1].PZ));
		ft_putstr("Dir x : ");
		ft_putendl(ft_itoa(SPOT[i - 1].DX));
		ft_putstr("Dir y : ");
		ft_putendl(ft_itoa(SPOT[i - 1].DY));
		ft_putstr("Dir z : ");
		ft_putendl(ft_itoa(SPOT[i - 1].DZ));
	}
}

static void		show_name(t_obj quad)
{
	if (quad.type == SPHERE)
		ft_putendl("Sphere Type");
	if (quad.type == PLANE)
		ft_putendl("Plane Type");
	if (quad.type == CONE)
		ft_putendl("CONE Type");
	if (quad.type == CYLINDRE)
		ft_putendl("CYLINDRE Type");
}

static void		show_quads(t_scene scene)
{
	int	i;

	i = 0;
	while (i++ < scene.nb_quad)
	{
		ft_putstr("QUAD number ");
		ft_putendl(ft_itoa(i - 1));
		show_name(QUAD[i - 1]);
		ft_putstr("Pos x : ");
		ft_putendl(ft_itoa(QUAD[i - 1].PX));
		ft_putstr("Pos y : ");
		ft_putendl(ft_itoa(QUAD[i - 1].PY));
		ft_putstr("Pos z : ");
		ft_putendl(ft_itoa(QUAD[i - 1].PZ));
		if (QUAD[i - 1].type != SPHERE)
		{
			ft_putstr("Dir x : ");
			ft_putendl(ft_itoa(QUAD[i - 1].DX));
			ft_putstr("Dir y : ");
			ft_putendl(ft_itoa(QUAD[i - 1].DY));
			ft_putstr("Dir z : ");
			ft_putendl(ft_itoa(QUAD[i - 1].DZ));
		}
		ft_putstr("Size : ");
		ft_putendl(ft_itoa(QUAD[i - 1].size));
		ft_putstr("COL : 0x");
		ft_putendl(ft_itoa_base(QUAD[i - 1].col, 16));
	}
}

static void		show_pov(t_scene scene)
{
	ft_putendl("Camera :\nPosition :");
	ft_putstr("Pos x : ");
	ft_putendl(ft_itoa(CAM.PX));
	ft_putstr("Pos y : ");
	ft_putendl(ft_itoa(CAM.PY));
	ft_putstr("Pos z : ");
	ft_putendl(ft_itoa(CAM.PZ));
	ft_putstr("Dir x : ");
	ft_putendl(ft_itoa(CAM.DX));
	ft_putstr("Dir y : ");
	ft_putendl(ft_itoa(CAM.DY));
	ft_putstr("Dir z : ");
	ft_putendl(ft_itoa(CAM.DZ));
}

static int	scene_opener(t_scene *scene)
{
	char	*line;
	char	*path;

	ft_putendl("Enter scene name : ");
	if (get_next_line(0, &line) == -1)
	{
		ft_putendl("error with gnl while asking scene name");
		return (1);
	}
	path = ft_strjoin("./scenes/", line);
	*scene = get_struct(path);
	ft_strdel(&line);
	ft_strdel(&path);
	return (0);
}

int			scene_displayer(void)
{
	t_scene	scene;

	if (scene_opener(&scene))
		return (1);
	show_pov(scene);
	show_quads(scene);
	show_spots(scene);
	return (0);
}
