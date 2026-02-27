/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:53:42 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/27 18:12:02 by dinza-cr         ###   ########.fr       */
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
	double				height;
	t_color				color;
	struct s_cylinder	*next;
}	t_cylinder;

//parsing
t_cylinder	*pars_cylinder(char **info);

//constructeur
t_cylinder	*cons_cylinder(void);

//destructeur
void		dest_cylinders(t_cylinder *cy);

//utils
void		add_cylinder(char **info, t_world *world);

#endif