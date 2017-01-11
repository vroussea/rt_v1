/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:28:32 by vroussea          #+#    #+#             */
/*   Updated: 2017/01/10 15:26:51 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/openclproject.h"

static int		write_buffer(cl_command_queue queue,
		cl_mem buffer, void *ptr, size_t size)
{
	cl_int	errcode;

	errcode = clEnqueueWriteBuffer(queue, buffer, CL_TRUE, 0,
			size, ptr, 0, NULL, NULL);
	if (errcode != CL_SUCCESS)
		return (1);
	return (0);
}

static cl_mem	create_buffer(cl_context context, cl_command_queue queue,
		size_t size, void *ptr)
{
	cl_mem	buffer;
	cl_int	errcode;

	buffer = NULL;
	buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, size, NULL, &errcode);
	if (errcode != CL_SUCCESS ||
			write_buffer(queue, buffer, ptr, size))
		return (error_msg("Error while creating Buffer"));
	return (buffer);
}

int				set_args(cl_mem col, cl_mem scene, cl_kernel kernel)
{

	if (clSetKernelArg(kernel, 0, sizeof(cl_mem),
				(void *)&col) != CL_SUCCESS ||
				clSetKernelArg(kernel, 0, sizeof(cl_mem),
				(void *)&scene) != CL_SUCCESS)
	{
		ft_putendl("Error while setting a kernel argument");
		return (1);
	}
	return (0);
}
