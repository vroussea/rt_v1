/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_v1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:36:29 by vroussea          #+#    #+#             */
/*   Updated: 2017/01/12 16:31:45 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_V1_H
# define RT_V1_H

# include "../libft/includes/libft.h"

# ifdef __APPLE__
#  include <OpenCL/opencl.h>
# else
#  include <cl.h>
# endif

# define SIZE_X 1000
# define SIZE_Y 1000
# define SCENE_VER 1.06
# define CAM scene.pov
# define SPOT scene.spots
# define QUAD scene.quads
# define PI 3.14159265358979323846
# define SOURCE_SIZE 0x100000
# define SPHERE 0
# define CONE 1
# define CYLINDRE 2
# define PLANE 3
# define DX dir.x
# define DY dir.y
# define DZ dir.z
# define PX pos.x
# define PY pos.y
# define PZ pos.z
# define ANG 500

# pragma pack(1)

typedef	struct	s_obj
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

typedef	struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_env;

int			add_node(void *node, t_env *env);
t_scene		get_struct(char *file);
void		caller(t_env *env, char *str, t_scene scene);
int			quit_funct(t_env *env);
int			key_funct(int keycode, t_env *env);
int			*opencl(t_scene scene);
void		*error_msg(char *str);
t_vector3d	rotate_y(t_vector3d dir, double ang);
t_vector3d	rotate_z(t_vector3d dir, double ang);
double		collide_sphere(t_obj ray, t_obj quad);
void		pixel_browser(t_scene scene, char *meml);
void		pixel(int x, int y, int col, char *meml);

#endif
