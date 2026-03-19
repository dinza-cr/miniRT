/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 12:42:22 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/19 12:44:17 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_tuple	normal_at(t_shape *s, t_tuple world_point)
{
	t_tuple	object_point;
	t_tuple	object_normal;
	t_tuple	world_normal;

	object_point = mop_multitup(s->inv_transfo, world_point);
	if (s->sphere.valid)
		object_normal = top_subs(object_point, cons_point(0, 0, 0));
	else if (s->plane.valid)
		object_normal = cons_vector(0, 1, 0);
	else if (s->cylinder.valid)
		object_normal = cylinder_normal_at(s, object_point);
	else
		object_normal = cons_vector(0, 0, 0);
	world_normal = mop_multitup(mop_transpose(s->inv_transfo), object_normal);
	world_normal.w = 0;
	world_normal = top_normalize(world_normal);
	return (world_normal);
}

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	t_tuple	res;

	res = top_multi(normal, 2 * top_dot(in, normal));
	res = top_subs(in, res);
	return (res);
}

int	is_shadowed(t_world *world, t_tuple point)
{
	t_tuple			v;
	double			distance;
	t_tuple			direction;
	t_ray			r;
	t_intersections	intersections;
	double			h;

	v = top_subs(world->light.coord, point);
	distance = top_magnitude(v);
	direction = top_normalize(v);
	r = cons_ray(point, direction);
	intersections = iop_intersect_world(world, r);
	h = iop_hit(intersections);
	dest_intersections(&intersections);
	if (h != INFINITY && h < distance)
		return (1);
	else
		return (0);
}
