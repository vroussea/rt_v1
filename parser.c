/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:01:11 by vroussea          #+#    #+#             */
/*   Updated: 2016/11/08 18:28:11 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"
#include <unistd.h>
#include <fcntl.h>

static int	fill_pov(t_pov **pov, int fd)
{
	char	**tab;
	int 	ret;
	char	*line;

	if ((ret = get_next_line(fd, &line)) > 0)
		if (ft_strncmp(line, "-name ", 6) == 0)
			(*pov)->name = ft_strdup(line + 6);
	if ((ret = get_next_line(fd, &line)) > 0)
		if (ft_strncmp(line, "-position ", 10) == 0)
		{
			tab = ft_strsplit(line + 10, ' ');
			(*pov)->x = ft_atoi(tab[0]);
			(*pov)->y = ft_atoi(tab[1]);
			(*pov)->z = ft_atoi(tab[2]);
			ft_tabdel((void ***)&tab);
		}
	if ((ret = get_next_line(fd, &line)) > 0)
		if (ft_strncmp(line, "-vector ", 8) == 0)
		{
			tab = ft_strsplit(line + 8, ' ');
			(*pov)->vx = ft_atoi(tab[0]);
			(*pov)->vy = ft_atoi(tab[1]);
			(*pov)->vz = ft_atoi(tab[2]);
			ft_tabdel((void ***)&tab);
		}
	return (ret == -1 ? 1 : 0);
}

static int	add_pov(int fd, t_env *env)
{
	t_pov	*pov;
	t_list *new;

	if (!(pov = ft_memalloc(sizeof(t_pov))))
		return (1);
	fill_pov(&pov, fd);
	if (!(new = ft_lstnew(pov, sizeof(pov))))
		return (1);
	ft_putendl((t_pov *)(new->content)->name);
	ft_lstadd_end(&(env->lst), new);
	return (0);
}

/*static int	add_spot()
  {
  return (0);
  }*/

int			parser(char *file, t_env *env)
{
	int	fd;
	char	*line;
	int		ret;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (1);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ft_strcmp(line, "pov") == 0)
			if (!(add_pov(fd, env)))
				return (1);
	/*	if (ft_strcmp(line, "sphere") == 0)
			if (!(add_sphere(fd, line, ret)))
				return (1);*/
		ft_strdel(&line);
	}
	close(fd);
	if (ret == -1)
		return (1);
	return (0);
}
