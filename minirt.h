/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:30:44 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/15 17:41:42 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINRT_H

# define EPSILON 0.00001

# include <math.h>

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w; // 1.0 for points 0.0 for vectors
}	t_tuple;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

//constructors
t_tuple	cons_vector(int x, int y, int z);
t_tuple	cons_point(int x, int y, int z);
t_color	cons_color(double r, double g, double b);

//operations
int		top_compare(t_tuple a, t_tuple b);
t_tuple	top_add(t_tuple a, t_tuple b);
t_tuple	top_subs(t_tuple a, t_tuple b);
t_tuple	top_negate(t_tuple a);
t_tuple	top_multi(t_tuple a, double scal);
t_tuple	top_divi(t_tuple a, double scal);
double	top_magnitude(t_tuple a);
t_tuple	top_normalize(t_tuple a);
double	top_dot(t_tuple a, t_tuple b);
t_tuple	top_cross(t_tuple a, t_tuple b);
t_color	cop_add(t_color	a, t_color b);
t_color	cop_subs(t_color a, t_color b);
t_color	cop_multi(t_color a, double scal);
t_color	cop_blend(t_color a, t_color b);

#endif