/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_v1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:36:29 by vroussea          #+#    #+#             */
/*   Updated: 2016/11/08 18:25:40 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_V1_H
# define RT_V1_H

# include "libft/libft.h"

typedef	struct	s_plane
{
	char	*name;
	double	x;
	double	y;
	double	z;
	double	vx;
	double	vy;
	double	vz;
	double	col;
}				t_plane;

typedef	struct	s_spot
{
	char	*name;
	double	x;
	double	y;
	double	z;
	double	vx;
	double	vy;
	double	vz;
}				t_spot;

typedef	struct	s_pov
{
	char	*name;
	double	x;
	double	y;
	double	z;
	double	vx;
	double	vy;
	double	vz;
}				t_pov;

typedef	struct	s_sphere
{
	char	*name;
	double	x;
	double	y;
	double	z;
	double	ray;
	double	col;
}				t_sphere;

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
int				parser(char *file, t_env *env);
void			caller(t_env *env);
int				quit_funct(t_env *env);
int				key_funct(int keycode, t_env *env);
void			pixel(int x, int y, int col, t_env *env);

#endif
