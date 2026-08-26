/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:21:34 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/11 13:38:13 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//constructor
t_plane	cons_plane(void)
{
	t_plane	res;

	res.valid = 0;
	res.coord = cons_point(0, 0, 0);
	res.normal = cons_vector(0, 0, 0);
	return (res);
}

t_shape	*pars_plane(char **info)
{
	t_shape	*res;

	res = cons_shape();
	if (!res)
		return (NULL);
	if (count_elem(info) != 4)
		return (res);
	res->plane.coord = get_point(info[1]);
	if (res->plane.coord.w == -1)
		return (res);
	res->plane.normal = get_vector(info[2]);
	if (res->plane.normal.w == -1)
		return (res);
	res->material.color = get_color(info[3]);
	if (res->material.color.r == -1)
		return (res);
	res->transformation = pl_transform(res);
	res->inv_transfo = mop_inverse(res->transformation);
	res->plane.valid = 1;
	return (res);
}

void	add_plane(char **info, t_world *world)
{
	t_shape	*new;

	new = pars_plane(info);
	if (!new)
		return ;
	new->next = world->shapes;
	world->shapes = new;
}

t_matrix	pl_transform(t_shape *s)
{
	t_tuple		y_axis;
	t_tuple		helper;
	t_tuple		x_axis;
	t_tuple		z_axis;
	t_matrix	rotation;
	t_matrix	translation;

	y_axis = s->plane.normal;
	if (fabs(y_axis.z) < 1 - EPSILON)
		helper = cons_vector(0, 0, 1);
	else
		helper = cons_vector(1, 0, 0);
	x_axis = top_cross(helper, y_axis);
	x_axis = top_normalize(x_axis);
	z_axis = top_cross(y_axis, x_axis);
	rotation = cons_mat4(
			x_axis.x, y_axis.x, z_axis.x, 0,
			x_axis.y, y_axis.y, z_axis.y, 0,
			x_axis.z, y_axis.z, z_axis.z, 0,
			0, 0, 0, 1);
	translation = trsf_translation(s->plane.coord.x,
			s->plane.coord.y, s->plane.coord.z);
	return (mop_multimat(translation, rotation));
}

t_intersections	plane_intersect(t_shape *s, t_ray r)
{
	t_intersections	res;
	double			t;

	if (fabs(r.direction.y) < EPSILON)
		return (cons_intersections(0));
	t = (-r.origin.y) / (r.direction.y);
	if (t <= EPSILON)
		return (cons_intersections(0));
	res = cons_intersections(1);
	if (!res.solutions)
		return (cons_intersections(0));
	res.solutions[0] = cons_intersection(t, s);
	return (res);
}
