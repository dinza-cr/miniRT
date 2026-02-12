/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:50:16 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/12 17:07:08 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "../../Exec/Color/color.h"
# include "../../Exec/Tuples/tuple.h"

typedef struct s_scene t_scene;

typedef struct s_sphere
{
	int				valid;
	t_tuple			coord;
	double			diameter;
	t_color			color;
	struct s_sphere	*next;
}	t_sphere;

//constructor
t_sphere	*cons_sphere(char **info);
t_sphere	*init_sphere(void);

//add
void		add_sphere(char **info, t_scene *scene);

//destructor
void		dest_spheres(t_sphere *sp);

#endif