/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 19:08:24 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/11 13:30:05 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
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
void	dest_intersections(t_intersections *xs)
{
	if (!xs)
		return ;
	free(xs->solutions);
	xs->solutions = NULL;
	xs->count = 0;
}

//intersect operations
t_intersections	iop_intersect(t_shape *s, t_ray r)
{
	r = rop_transform(r, s->inv_transfo);
	if (s->sphere.valid)
		return (sphere_intersect(s, r));
	else if (s->plane.valid)
		return (plane_intersect(s, r));
	else if (s->cylinder.valid)
		return (cylinder_intersect(s, r));
	return (cons_intersections(0));
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

t_intersections	iop_intersect_world(t_world *w, t_ray r)
{
	t_intersections		res;
	t_intersections		xs;
	t_shape				*temp;
	int					max_hits;
	int					k;
	int					i;

	max_hits = 2 * count_shapes(w->shapes);
	res.count = 0;
	res.solutions = NULL;
	if (max_hits == 0)
		return (res);
	res.solutions = malloc(sizeof(t_intersection) * max_hits);
	if (!res.solutions)
		return (res);
	k = 0;
	temp = w->shapes;
	while (temp)
	{
		xs = iop_intersect(temp, r);
		i = 0;
		while (i < xs.count)
			res.solutions[k++] = xs.solutions[i++];
		dest_intersections(&xs);
		temp = temp->next;
	}
	res.count = k;
	if (res.count > 1)
		sort_intersections(&res);
	return (res);
}

//utils
int	count_shapes(t_shape *s)
{
	int			res;
	t_shape		*temp;

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
	t_intersection	tmp;

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

double	discriminant(t_ray r, double *a, double *b)
{
	double	res;
	double	c;
	t_tuple	sphere_to_ray;

	sphere_to_ray = top_subs(r.origin, cons_point(0, 0, 0));
	*a = top_dot(r.direction, r.direction);
	*b = 2.0 * top_dot(r.direction, sphere_to_ray);
	c = top_dot(sphere_to_ray, sphere_to_ray) - 1.0;
	res = ((*b) * (*b)) - (4.0 * (*a) * (c));
	return (res);
}
