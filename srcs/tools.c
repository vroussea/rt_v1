/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 18:40:34 by vroussea          #+#    #+#             */
/*   Updated: 2016/11/09 15:33:59 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"
#include <stdlib.h>
#include <math.h>

void		pixel(int x, int y, int col, t_env *env)
{
	if (x > 0 && x < env->sx && y > 0 && y < env->sy)
		ft_memcpy(&env->meml[(x - 1) * 4 + (y - 1) * env->sizel], &col, 4);
}

void		del_node(void *data, size_t size_data)
{
	t_pov	*tmp;

	size_data++;
	tmp = (t_pov *)data;
	ft_strdel(&(tmp->name));
}

/*int			add_node(void *node, t_env *env)
{
	t_list *new;

	ft_putendl(node->name);
	if (!(new = ft_lstnew(node, sizeof(node))))
		return (1);
	ft_putendl("mdr");
	//ft_putendl(new->content->name);
	ft_lstadd_end(&(env->lst), new);
	return (0);
}*/
