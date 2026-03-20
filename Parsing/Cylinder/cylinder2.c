/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 16:49:50 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/20 15:40:49 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_matrix	cy_matassemble(t_tuple x_axis, t_tuple y_axis,
	t_tuple z_axis, t_shape *s)
{
	t_matrix	res;
	t_matrix	rotation;
	t_matrix	translation;
	t_matrix	scaling;

	rotation = cons_mat4(
			cons_tuple(x_axis.x, y_axis.x, z_axis.x, 0),
			cons_tuple(x_axis.y, y_axis.y, z_axis.y, 0),
			cons_tuple(x_axis.z, y_axis.z, z_axis.z, 0),
			cons_tuple(0, 0, 0, 1));
	translation = trsf_translation(
			s->cylinder.coord.x,
			s->cylinder.coord.y,
			s->cylinder.coord.z);
	scaling = trsf_scaling(s->cylinder.diameter * 0.5,
			s->cylinder.height * 0.5, s->cylinder.diameter * 0.5);
	res = mop_multimat(translation, mop_multimat(rotation, scaling));
	return (res);
}

t_matrix	cy_transform(t_shape *s)
{
	t_tuple		x_axis;
	t_tuple		y_axis;
	t_tuple		z_axis;
	t_tuple		helper;
	t_matrix	res;

	y_axis = top_normalize(s->cylinder.axis);
	if (fabs(y_axis.z) < 1 - EPSILON)
		helper = cons_vector(0, 0, 1);
	else
		helper = cons_vector(1, 0, 0);
	x_axis = top_normalize(top_cross(helper, y_axis));
	z_axis = top_cross(y_axis, x_axis);
	res = cy_matassemble(x_axis, y_axis, z_axis, s);
	return (res);
}

t_intersections	cylinder_intersect(t_shape *s, t_ray r)
{
	t_intersections	res;
	double			disc[4];
	t_intersection	t[2];
	double			y[2];
	int				count[2];

	cy_discriminant(disc, r, s, t);
	if (fabs(disc[0]) < EPSILON || disc[3] < 0)
		return (cons_intersections(0));
	if (t[0].t > t[1].t)
		swap_i(&t[0], &t[1]);
	y[0] = r.origin.y + t[0].t * r.direction.y;
	y[1] = r.origin.y + t[1].t * r.direction.y;
	count[0] = count_sides(s, y);
	count[1] = count_caps(s, r);
	res = cons_intersections(count[0] + count[1]);
	if ((count[0] + count[1]) > 0 && !res.solutions)
		return (cons_intersections(0));
	count[0] = 0;
	if (y[0] > s->cylinder.minimum && y[0] < s->cylinder.maximum)
		res.solutions[count[0]++] = t[0];
	if (y[1] > s->cylinder.minimum && y[1] < s->cylinder.maximum)
		res.solutions[count[0]++] = t[1];
	res.count = cylinder_add_caps(s, r, &res, count[0]);
	return (res);
}

t_tuple	cylinder_normal_at(t_shape *s, t_tuple object_point)
{
	double	dist;

	dist = (object_point.x * object_point.x)
		+ (object_point.z * object_point.z);
	if (dist < 1 && object_point.y >= s->cylinder.maximum - EPSILON)
		return (cons_vector(0, 1, 0));
	else if (dist < 1 && object_point.y <= s->cylinder.minimum + EPSILON)
		return (cons_vector(0, -1, 0));
	else
		return (cons_vector(object_point.x, 0, object_point.z));
}
