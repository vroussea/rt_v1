/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scmk.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:06:19 by vroussea          #+#    #+#             */
/*   Updated: 2016/11/16 16:13:02 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCMK_H
# define SCMK_H

# include "../libft/libft.h"
# include "rt_v1.h"

t_pov		create_pov();
t_spot		create_spot();
t_obj		create_obj(int val);
int			select_obj();
float		catch_float(char *str);
int			catch_col(char *str);
int			loop_nb(char *str);
void		sphere_type(t_obj *obj);
void		plane_type(t_obj *obj);
t_vectorf3	dir();

#endif
