/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:34:31 by vroussea          #+#    #+#             */
/*   Updated: 2016/11/13 18:01:19 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scmk.h"

t_pov	create_pov()
{
	char	*line;
	t_pov	pov;

	ft_putendl("| Point of vew : ");
	ft_putendl("Enter x, y and z coordinates");
	ft_putstr("x : ");
	get_next_line(0, &line);
	pov.pos.x = ft_atof(line);
	ft_strdel(&line);
	ft_putstr("y : ");
	get_next_line(0, &line);
	pov.pos.y = ft_atof(line);
	ft_strdel(&line);
	ft_putstr("z : ");
	get_next_line(0, &line);
	pov.pos.z = ft_atof(line);
	ft_strdel(&line);
	return (pov);
}
