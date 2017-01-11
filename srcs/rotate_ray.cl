#include "../includes/rtv1.h"

__kernel void	rotate_ray(__global int *col, __global t_scene scene)
{
	t_obj	r;
	int		id;
	double	x;
	double	y;

	id = get_global_id(0);
	x = (id % SIZE_X) * (PI / 3) / SIZE_X;
	x -= (PI / 6);
	y = (int)(id / SIZE_X) * (PI * (SIZE_X / SIZE_Y) / 3) / SIZE_Y;
	y -= (PI * (SIZE_X / SIZE_Y) / 6);
	r.pos.x = CAM.pos.x;
	r.pos.y = CAM.pos.y;
	r.pos.z = CAM.pos.z;
	r.dir = rotate_vect_y(CAM.dir, x[id]);
	r.dir = rotate_vect_z(r.dir, y[id]);
	col[id] = check_objects(r, scene);
}
