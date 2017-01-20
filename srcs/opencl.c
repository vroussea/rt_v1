/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 11:22:55 by vroussea          #+#    #+#             */
/*   Updated: 2017/01/12 11:20:53 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_v1.h"

static int	*enqueue_tasks(cl_command_queue queue, cl_kernel kern,
		t_scene scene, cl_mem buff)
{
	int		*col;
	size_t	*global_wi;
	cl_int	errcode;

	global_wi = (size_t *)ft_memalloc(sizeof(size_t) * 2);
	global_wi[0] = sizeof(int) * SIZE_X * SIZE_Y;
	global_wi[1] = sizeof(scene);
	errcode = clEnqueueNDRangeKernel (queue, kern, 2,
			NULL, global_wi, NULL, 0, NULL, NULL);
	if (errcode != CL_SUCCESS)
		return (error_msg("Error while enqueing task"));
	if (clEnqueueReadBuffer(queue, buff, CL_TRUE, 0,
				sizeof(int) * SIZE_X * SIZE_Y, &col,
				0, NULL, NULL) != CL_SUCCESS)
		return (error_msg("Error while reading buffer"));
	ft_memdel((void **)&global_wi);
	return (col);
}

static int	*init_values(cl_context ctxt, cl_device_id dvic, cl_program prog,
		t_scene scene)
{
	cl_command_queue	queue;
	cl_mem				mem_col;
	cl_mem				mem_scene;
	cl_kernel			kernel;
	int					*col;

	init_color(&col);
	if (!(queue = init_queue(ctxt, dvic)) ||
			!(kernel = init_kernel(prog)) ||
			!(mem_col = create_buffer(ctxt, queue,
					sizeof(int) * SIZE_X * SIZE_Y, (void *)&col)) ||
			!(mem_scene = create_buffer(ctxt, queue, sizeof(scene),
					(void *)&scene)) ||
			set_args(mem_col, mem_scene, kernel) ||
			!(col = enqueue_tasks(queue, kernel, scene, mem_col)))
		return (NULL);
	return (col);
}

int		*opencl(t_scene scene)
{
	cl_context		ctxt;
	cl_device_id	dvic;
	cl_program		prog;
	char			*src;
	int				*col;

	if (!(src = load_source_code()) ||
			!(ctxt = get_context(&dvic)) ||
			!(prog = build_program(src, ctxt, dvic)) ||
			!(col = init_values(ctxt, dvic, prog, scene)))
		return (error_msg("Program abort"));
	return (col);
}
