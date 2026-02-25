/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:50:16 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/25 19:05:24 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "../../Exec/Color/color.h"
# include "../../Exec/Tuples/tuple.h"
# include "../Exec/Material/material.h"
typedef struct s_world	t_world;

typedef struct s_sphere
{
	int				valid;
	t_tuple			coord;
	double			diameter;
	double			radius;
	t_matrix		transform;
	t_material		m;
	struct s_sphere	*next;
}	t_sphere;

//parsing
t_sphere	*pars_sphere(char **info);

//constructor
t_sphere	*cons_sphere(void);

//destructor
void		dest_spheres(t_sphere *sp);

//fonctions
void		set_transform(t_sphere *s, t_matrix t);

//utils
void		add_sphere(char **info, t_world *world);


#endif