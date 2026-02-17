/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:22:26 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/16 18:17:39 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

typedef struct s_sphere t_sphere;



typedef struct s_intersection
{
	double		t;
	t_sphere	*object;
} t_intersection;


typedef struct s_intersect
{
    int				count;
    t_intersection	xs[2];
} t_intersect;



t_intersect cons_intersect();
t_intersection	cons_intersection(void);

t_intersect	intersect(t_sphere *s, t_ray r);

t_intersection intersection(double t, t_sphere *object);
t_intersect		intersections(t_intersection i1, t_intersection i2);
double	hit(t_intersect xs);

#endif