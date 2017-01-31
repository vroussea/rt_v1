/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scmk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:31:31 by vroussea          #+#    #+#             */
/*   Updated: 2017/01/27 13:33:10 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scmk.h"

static void	set_choices(t_choices **choices)
{
	*choices = (t_choices *)ft_memalloc(sizeof(t_choices) * 3);
	(*choices)[0] = &scene_creator;
	(*choices)[1] = &scene_displayer;
//	(*choices)[2] = &scene_editor;
}

int			main(void)
{
	int			choice;
	char		*line;
	t_choices	*choices;

	set_choices(&choices);
	choice = -1;
	while (choice != 0)
	{
		ft_putendl("What do you want to do ?");
		ft_putendl("0 : Exit");
		ft_putendl("1 : Create Scene");
		ft_putendl("2 : Display Scene");
		ft_putendl("3 : Edit Scene");
		if (get_next_line(0, &line) == -1)
		{
			ft_putendl("error with gnl while asking next action");
			return (1);
		}
		choice = ft_atoi(line);
		ft_strdel(&line);
		if (choice > 0 && choice < 4)
			if (choices[choice - 1]())
				return (1);
	}
	ft_memdel((void **)&choices);
	return (0);
}
