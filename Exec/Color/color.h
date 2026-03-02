/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:30:37 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/27 18:46:28 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H 

# include "../Comps/comps.h"

typedef struct s_world	t_world;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

//constructeur
t_color		cons_color(double r, double g, double b);

//color operation (cop)
t_color		cop_add(t_color	a, t_color b);
t_color		cop_subs(t_color a, t_color b);
t_color		cop_multi(t_color a, double scal);
t_color		cop_blend(t_color a, t_color b);
int			cop_compare(t_color a, t_color b);
t_color		cop_shade_hit(t_world *world, t_comps comps);
t_color		color_at(t_world *world, t_ray r);

#endif