/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:55:53 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/11 13:38:21 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "exec/color.h"
# include "exec/tuple.h"

typedef struct s_world t_world;

typedef struct s_plane
{
	int				valid;

	t_tuple			coord;
	t_tuple			normal;
}	t_plane;

//parsing
t_shape			*pars_plane(char **info);

//constructeur
t_plane			cons_plane(void);

//destructeur
void			dest_planes(t_plane *pl);

//utils
void			add_plane(char **info, t_world *world);
t_intersections	plane_intersect(t_shape *s, t_ray r);
t_matrix		pl_transform(t_shape *s);

#endif