/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 19:08:24 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/18 14:52:41 by dinza-cr         ###   ########.fr       */
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
	int					i[2];

	max_hits = 2 * count_shapes(w->shapes);
	res = cons_intersections(0);
	res.solutions = malloc(sizeof(t_intersection) * max_hits);
	if (!res.solutions || max_hits <= 0)
		return (res);
	i[0] = 0;
	temp = w->shapes;
	while (temp)
	{
		xs = iop_intersect(temp, r);
		i[1] = 0;
		while (i[1] < xs.count)
			res.solutions[i[0]++] = xs.solutions[i[1]++];
		dest_intersections(&xs);
		temp = temp->next;
	}
	res.count = i[0];
	sort_intersections(&res);
	return (res);
}
