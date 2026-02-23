/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 19:08:24 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/18 17:56:02 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
//constructeur
t_intersections	cons_intersections(int count)
{
	t_intersections	res;

	res.count = 0;
	res.solutions = NULL;
	if (count <= 0)
		return (res);
	res.solutions = malloc(sizeof(t_intersection) * count);
	if (!res.solutions)
		return (res);
	res.count = count;
	return (res);
}

//destructeur
void	free_intersections(t_intersections *xs)
{
	if (!xs)
		return ;
	free(xs->solutions);
	xs->solutions = NULL;
	xs->count = 0;
}

double	discriminant(t_sphere *s, t_ray r)
{
	double	a;
	double	b;
	double	c;
	double	res;
	t_tuple	sphere_to_ray;

	sphere_to_ray = top_subs(r.origin, s->coord);
	a = top_dot(r.direction, r.direction);
	b = 2.0 * top_dot(r.direction, sphere_to_ray);
	c = top_dot(sphere_to_ray, sphere_to_ray) - (s->radius * s->radius);
	res = (b * b) - (4.0 * a * c);
	return (res);
}

t_intersections	iop_intersect(t_sphere *s, t_ray r)
{
	t_intersections	res;
	double			dis;
	double			a;
	double			b;
	t_tuple			sphere_to_ray;

	r = rop_transform(r, mop_inverse(s->transform));
	dis = discriminant(s, r);
	if (dis < 0.0)
		return (cons_intersections(0));
	res = cons_intersections(2);
	if (!res.solutions)
		return (cons_intersections(0));
	sphere_to_ray = top_subs(r.origin, s->coord);
	a = top_dot(r.direction, r.direction);
	b = 2.0 * top_dot(r.direction, sphere_to_ray);
	res.solutions[0] = cons_intersection((-b - sqrt(dis)) / (2.0 * a), s);
	res.solutions[1] = cons_intersection((-b + sqrt(dis)) / (2.0 * a), s);
	if (res.solutions[0].t > res.solutions[1].t)
	{
		a = res.solutions[0].t;
		res.solutions[0].t = res.solutions[1].t;
		res.solutions[1].t = a;
	}
	return (res);
}

t_intersections	iop_intersections(int count, t_intersection *arr)
{
	t_intersections	res;
	int				i;

	res.count = count;
	res.solutions = NULL;
	if (count <= 0)
		return (res);
	res.solutions = malloc(sizeof(t_intersection) * count);
	if (!res.solutions)
		return (res);
	i = 0;
	while (i < count)
	{
		res.solutions[i] = arr[i];
		i++;
	}
	return (res);
}
