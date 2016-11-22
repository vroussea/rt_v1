/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scmk.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:06:19 by vroussea          #+#    #+#             */
/*   Updated: 2016/11/21 14:58:57 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCMK_H
# define SCMK_H

# include "rt_v1.h"

t_pov		create_pov();
t_spot		create_spot();
t_obj		create_obj(int val);
float		catch_float(char *str);
int			catch_col(char *str);
int			catch_int(char *str);
int			loop_nb(char *str);
void		sphere_type(t_obj *obj);
void		plane_type(t_obj *obj);
t_vectorf3	dir();

#endif
