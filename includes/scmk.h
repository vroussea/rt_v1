/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scmk.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:06:19 by vroussea          #+#    #+#             */
/*   Updated: 2017/01/20 15:04:30 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCMK_H
# define SCMK_H

# include "rt_v1.h"

t_obj		create_pov();
t_obj		create_spot();
t_obj		create_obj(int val);
double		catch_double(char *str);
int			catch_col(char *str);
int			catch_int(char *str);
int			loop_nb(char *str);
void		sphere_type(t_obj *obj);
void		plane_type(t_obj *obj);
t_vect3d	dir();

#endif
