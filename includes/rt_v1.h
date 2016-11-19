/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_v1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:36:29 by vroussea          #+#    #+#             */
/*   Updated: 2016/11/17 17:18:54 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_V1_H
# define RT_V1_H

# include "../libft/libft.h"
# define SIZE_X 1280
# define SIZE_Y 720

#pragma pack(1)

typedef	struct	s_spot
{
	t_vectorf3	pos;
	t_vectorf3	dir;
}				t_spot;

typedef	struct	s_pov
{
	t_vectorf3	pos;
	t_vectorf3	dir;
}				t_pov;

typedef	struct	s_object
{
	t_vectorf3	pos;
	t_vectorf3	dir;
	int			ray;
	int			col;
}				t_obj;

typedef struct	s_scene
{
	t_pov		pov;
	int			nb_obj;
	int			nb_spot;
	t_obj		*objs;
	t_spot		*spots;
}				t_scene;

typedef	struct	s_env
{
	void	*mlx;
	void	*win;
	int		sx;
	int		sy;
	void	*img;
	char	*meml;
	int		sizel;
	t_list	*lst;
}				t_env;

int				add_node(void *node, t_env *env);
t_scene			get_struct(char *file);
void			caller(t_env *env);
int				quit_funct(t_env *env);
int				key_funct(int keycode, t_env *env);
void			pixel(int x, int y, int col, t_env *env);
void			del_node(void *data, size_t size_data);

#endif
