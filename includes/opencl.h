/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:35:47 by vroussea          #+#    #+#             */
/*   Updated: 2017/01/12 11:57:16 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPENCL_H
# define OPENCL_H

# define CAM scene.pov
# define QUAD scene.quads
# define SPHERE 0
# define DX dir.x
# define DY dir.y
# define DZ dir.z
# define PX pos.x
# define PY pos.y
# define PZ pos.z
# define SIZE_x 1280
# define SIZE_Y 720
# define PI 3.14159265358979323846

typedef struct	s_vector3d
{
	double		x;
	double		y;
	double		z;
}				t_vector3d;

typedef struct	s_obj
{
	int			type;
	t_vector3d	pos;
	t_vector3d	dir;
	double		size;
	int			col;
}				t_obj;

typedef struct	s_scene
{
	t_obj		pov;
	int			nb_quad;
	int			nb_spot;
	t_obj		*quads;
	t_obj		*spots;
}				t_scene;

t_vector3d		rotate_vect_y(t_vector3d dir, double ang);
t_vector3d		rotate_vect_z(t_vector3d dir, double ang);
int				whiche_quad(t_obj ray, t_scene scene);
double			collide_sphere(t_obj ray, t_obj quad);

#endif
