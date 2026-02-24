/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 19:08:24 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/24 16:04:05 by dinza-cr         ###   ########.fr       */
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

	(void)s;
	sphere_to_ray = top_subs(r.origin, cons_point(0, 0, 0));
	a = top_dot(r.direction, r.direction);
	b = 2.0 * top_dot(r.direction, sphere_to_ray);
	c = top_dot(sphere_to_ray, sphere_to_ray) - 1.0;
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
	sphere_to_ray = top_subs(r.origin, cons_point(0, 0, 0));
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

	res.count = 0;
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
	res.count = count;
	return (res);
}

int count_spheres(t_sphere *s)
{
	int res;
	t_sphere *temp;
	
	res = 0;
	temp = s;
	while (temp)
	{
		res++;
		temp = temp->next;
	}
	return (res);
}

void	swap_i(t_intersection *a, t_intersection *b)
{
	t_intersection tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_intersections(t_intersections *xs)
{
	int	i;
	int	j;

	i = 0;
	while (i < xs->count - 1)
	{
		j = 0;
		while (j < xs->count - 1 - i)
		{
			if (xs->solutions[j].t > xs->solutions[j + 1].t)
				swap_i(&xs->solutions[j], &xs->solutions[j + 1]);
			j++;
		}
		i++;
	}
}

t_intersections	intersect_world(t_world *w, t_ray r)
{
	t_intersections		res;
	t_sphere			*sp;
	int					max_hits;
	int					k;
	int					i;

	max_hits = 2 * count_spheres(w->spheres);
	res.count = 0;
	res.solutions = NULL;
	if (max_hits == 0)
		return (res);
	res.solutions = malloc(sizeof(t_intersection) * max_hits);
	if (!res.solutions)
		return (res);
	k = 0;
	sp = w->spheres;
	while (sp)
	{
		t_intersections xs = iop_intersect(sp, r);
		i = 0;
		while (i < xs.count)
			res.solutions[k++] = xs.solutions[i++];
		free_intersections(&xs);
		sp = sp->next;
	}
	res.count = k;
	if (res.count > 1)
		sort_intersections(&res);
	return (res);
}