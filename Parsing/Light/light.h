/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:46:35 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/19 16:20:15 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "../../Exec/Color/color.h"
# include "../../Exec/Tuples/tuple.h"
# include "../../Exec/Material/material.h"

typedef struct s_sphere	t_sphere;
typedef struct s_world	t_world;

typedef struct s_light // unique
{
	int		valid;
	t_tuple	coord;
	double	brightness;
	t_color	color;
}	t_light;

//parisng
t_light	pars_light(char **info, t_world *world);

//constructeur
t_light	cons_light(t_tuple position, t_color color);

//fonctions
t_tuple	normal_at(t_shape *s, t_tuple p);
t_tuple	reflect(t_tuple in, t_tuple normal);
t_color	lighting(t_world *world, t_comps comps, int in_shadow);
int		is_shadowed(t_world *world, t_tuple point);

#endif