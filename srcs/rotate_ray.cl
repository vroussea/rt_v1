# define CAM scene.pov
# define QUAD scene.quads
# define SPHERE 0
# define DX dir.x
# define DY dir.y
# define DZ dir.z
# define PX pos.x
# define PY pos.y
# define PZ pos.z
# define SIZE_X 1280
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

t_vector3d	rotate_y(t_vector3d dir, double ang)
{
	dir.x = dir.x * cos(ang) + dir.z * sin(ang);
	dir.z = dir.z * cos(ang) - dir.x * sin(ang);
	return (dir);
}

t_vector3d	rotate_z(t_vector3d dir, double ang)
{
	dir.x = dir.x * cos(ang) - dir.y * sin(ang);
	dir.y = dir.y * cos(ang) + dir.x * sin(ang);
	return (dir);
}

double	collide_sphere(t_obj ray, t_obj quad)
{
	double		a;
	double		b;
	double		c;
	double		d;

	a = pow(ray.DX, 2) + pow(ray.DY, 2) + pow(ray.DZ, 2);
	b = 2 * ray.DX * (ray.PX - quad.PX) +
		2 * ray.DY * (ray.PY - quad.PY) +
		2 * ray.DZ * (ray.PZ - quad.PZ);
	c = pow(quad.PX, 2) + pow(quad.PY, 2) + pow(quad.PZ, 2) +
		pow(ray.PX, 2) + pow(ray.PY, 2) + pow(ray.PZ, 2) -
		2 * (quad.PX * ray.PX + quad.PY * ray.PY + quad.PZ * ray.PZ )
		- pow(quad.size, 2);
	d =	b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	c = (- b - sqrt(d)) / (2 * a);
	d = (- b + sqrt(d)) / (2 * a);
	return (c < d ? c : d);
}

int	which_quad(t_obj ray, t_scene scene)
{
	int		crt;
	int		col;
	double	dist;
	double	tmp_dist;

	crt = 0;
	col = 0;
	dist = 0x76FFFFFF;
	tmp_dist = dist;
	while (crt < scene.nb_quad)
	{
		if (QUAD[crt].type == SPHERE)
		tmp_dist = collide_sphere(ray, QUAD[crt]);
		if (tmp_dist > 0 && tmp_dist < dist)
		{
			dist = tmp_dist;
			col = QUAD[crt].col;
		}
		crt++;
	}
	return (col);
}

__kernel void	rotate_ray(__global int *col, __global t_scene scene)
{
	t_obj	ray;
	int		id;
	double	x;
	double	y;

	id = get_global_id(0);
	x = (id % SIZE_X) * (PI / 3) / SIZE_X;
	x -= (PI / 6);
	y = (int)(id / SIZE_X) * (PI * (SIZE_X / SIZE_Y) / 3) / SIZE_Y;
	y -= (PI * (SIZE_X / SIZE_Y) / 6);
	ray.pos.x = CAM.pos.x;
	ray.pos.y = CAM.pos.y;
	ray.pos.z = CAM.pos.z;
	ray.dir = rotate_y(CAM.dir, x[id]);
	ray.dir = rotate_z(ray.dir, y[id]);
	col[id] = which_quad(ray, scene);
}
