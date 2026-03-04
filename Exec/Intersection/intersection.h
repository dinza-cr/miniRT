/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:22:26 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/04 19:06:19 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "../Ray/ray.h"

typedef struct s_shape	t_shape;
typedef struct s_world	t_world;

typedef struct s_intersection
{
	double		t;
	t_shape		*object;
}	t_intersection;

typedef struct s_intersections
{
	int				count;
	t_intersection	*solutions;
}	t_intersections;

//constructeurs
t_intersection		cons_intersection(double t, t_shape *object);
t_intersections		cons_intersections(int count);

//destructeur
void				dest_intersections(t_intersections *xs);

//intersections operations(iop)
t_intersections		iop_intersect(t_shape *s, t_ray r);
t_intersections		iop_intersections(int count, t_intersection *arr);
double				iop_hit(t_intersections xs);
t_intersections		iop_intersect_world(t_world *w, t_ray r);

//utils
double				discriminant(t_ray r, double *a, double *b);
void				swap_i(t_intersection *a, t_intersection *b);

#endif