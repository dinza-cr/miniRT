/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:46:35 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/25 19:03:45 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "../../Exec/Color/color.h"
# include "../../Exec/Tuples/tuple.h"
# include "../../Exec/Material/material.h"
typedef struct s_sphere t_sphere;
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
t_tuple normal_at(t_sphere *s, t_tuple p);
t_tuple reflect(t_tuple in, t_tuple normal);
t_color lighting(t_material m, t_light l, t_tuple point, t_tuple eyev, t_tuple normalv);

#endif