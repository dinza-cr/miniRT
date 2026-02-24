/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:53:42 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/24 11:10:09 by dinza-cr         ###   ########.fr       */
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

//constructeur
t_cylinder	*init_cylinder(void);
t_cylinder	*cons_cylinder(char **info);

//add
void		add_cylinder(char **info, t_world *world);

//destructeur
void		dest_cylinders(t_cylinder *cy);
#endif