/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 18:40:34 by vroussea          #+#    #+#             */
/*   Updated: 2016/12/17 16:48:12 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_v1.h"

void			*error_msg(char *str)
{
	ft_putendl(str);
	return (NULL);
}

void	init_color(int	**col)
{
	unsigned int	size;

	size = sizeof(int) * SIZE_X * SIZE_Y;
	*col = (int *)ft_memalloc(size);
	ft_memset((void *)(*col), 0, size);
}

/*void		pixel(t_pt pt, t_env *env, int size_l, char *str)
  {
  if (pt.x > 0 && pt.x < SIZE_X && pt.y > 0 && pt.y < SIZE_Y)
  ft_memcpy(str[(pt.x - 1) * 4 + (pt.y - 1) * size_l], &(pt.col), 4);
  }

  int			add_node(void *node, t_env *env)
  {
  t_list *new;

  ft_putendl(node->name);
  if (!(new = ft_lstnew(node, sizeof(node))))
  return (1);
  ft_putendl("mdr");
  ft_putendl(new->content->name);
  ft_lstadd_end(&(env->lst), new);
  return (0);
  }*/
