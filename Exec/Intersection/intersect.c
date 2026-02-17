/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 19:08:24 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/16 18:07:42 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_intersect cons_intersect()
{
	t_intersect res;

	res.count = 0;
	res.xs[0] = cons_intersection();
	res.xs[1] = cons_intersection();
	return (res);
}

double discriminant(t_sphere *s, t_ray r)
{
	double a;
	double b;
	double c;
	double res;
	t_tuple sphere_to_ray;

	sphere_to_ray = top_subs(r.origin, s->coord);
	a = top_dot(r.direction, r.direction);
	b = 2.0 * top_dot(r.direction, sphere_to_ray);
	c = top_dot(sphere_to_ray, sphere_to_ray) - (s->radius * s->radius);
	res = (b * b) - (4.0 * a * c);
	return (res);
}

t_intersect intersect(t_sphere *s, t_ray r)
{
    t_intersect	res;
    double	dis;
    double	a;
    double	b;
    t_tuple	sphere_to_ray;
	

    res = cons_intersect();
    sphere_to_ray = top_subs(r.origin, s->coord);
    a = top_dot(r.direction, r.direction);
    b = 2.0 * top_dot(r.direction, sphere_to_ray);
    dis = discriminant(s, r);
    if (dis < 0.0)
        return (res);
    res.xs[0].t = (-b - sqrt(dis)) / (2.0 * a);
	res.xs[0].object = s;
    res.xs[1].t = (-b + sqrt(dis)) / (2.0 * a);
	res.xs[1].object = s;
	res.count = 2;
	if (res.xs[0].t > res.xs[1].t)
	{
		a = res.xs[0].t;
		res.xs[0].t = res.xs[1].t;
		res.xs[1].t = a;
	}
    return (res);
}