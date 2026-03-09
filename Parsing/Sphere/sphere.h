/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:50:16 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/09 18:06:50 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "../../Exec/Color/color.h"
# include "../../Exec/Tuples/tuple.h"
# include "../Exec/Material/material.h"

typedef struct s_world	t_world;
typedef struct s_shape	t_shape;


typedef struct s_sphere
{
	int				valid;

	t_tuple			coord;
	double			diameter;
	double			radius;
}	t_sphere;

//parsing
t_shape			*pars_sphere(char **info);

//constructor
t_sphere		cons_sphere(void);


//fonctions
t_matrix		sp_transform(t_shape *s);
t_intersections	sphere_intersect(t_shape *s, t_ray r);
void			add_sphere(char **info, t_world *world);

#endif