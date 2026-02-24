/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:22:26 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/24 16:10:22 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

typedef struct s_sphere	t_sphere;
typedef struct s_world t_world;

typedef struct s_intersection
{
	double		t;
	t_sphere	*object;
}	t_intersection;

typedef struct s_intersections
{
	int				count;
	t_intersection	*solutions;
}	t_intersections;

t_intersection		cons_intersection(double t, t_sphere *object);

t_intersections		cons_intersections(int count);
void				free_intersections(t_intersections *xs);

double				discriminant(t_sphere *s, t_ray r);
t_intersections		iop_intersect(t_sphere *s, t_ray r);
t_intersections		iop_intersections(int count, t_intersection *arr);
double				iop_hit(t_intersections xs);

t_intersections		intersect_world(t_world *w, t_ray r);

#endif