/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:53:42 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/19 12:38:52 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "../../Exec/Color/color.h"
# include "../../Exec/Tuples/tuple.h"

typedef struct s_world	t_world;

typedef struct s_cylinder
{
	int					valid;

	t_tuple				coord;
	t_tuple				axis;
	double				diameter;
	double				radius;
	double				height;
	double				minimum;
	double				maximum;
}	t_cylinder;

//parsing
t_shape			*pars_cylinder(char **info);

//constructeur
t_cylinder		cons_cylinder(void);

//destructeur
void			dest_cylinders(t_cylinder *cy);

//utils
void			add_cylinder(char **info, t_world *world);
t_matrix		cy_transform(t_shape *s);
t_intersections	cylinder_intersect(t_shape *s, t_ray r);
t_tuple			cylinder_normal_at(t_shape *s, t_tuple object_point);
int				check_cap(t_ray r, double t);
int				cylinder_count_caps(t_shape *s, t_ray r);
#endif