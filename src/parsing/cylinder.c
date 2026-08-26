/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:47:35 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/18 13:55:22 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//constructeur
t_cylinder	cons_cylinder(void)
{
	t_cylinder	res;

	res.valid = 0;
	res.coord = cons_point(0, 0, 0);
	res.axis = cons_vector(0, 0, 0);
	res.diameter = 0;
	res.radius = 0;
	res.height = 0;
	return (res);
}

t_shape	*pars_cylinder(char **info)
{
	t_shape	*res;

	res = cons_shape();
	if (!res)
		return (NULL);
	if (count_elem(info) != 6)
		return (res);
	res->cylinder.coord = get_point(info[1]);
	if (res->cylinder.coord.w == -1)
		return (res);
	res->cylinder.axis = get_vector(info[2]);
	if (res->cylinder.axis.w == -1)
		return (res);
	res->cylinder.diameter = ft_atod(info[3]);
	if (res->cylinder.diameter <= 0)
		return (res);
	res->cylinder.radius = res->cylinder.diameter/2;
	res->cylinder.height = ft_atod(info[4]);
	if (res->cylinder.height <= 0)
		return (res);
	res->cylinder.minimum = -res->cylinder.height/2;
	res->cylinder.maximum = res->cylinder.height/2;
	res->material.color = get_color(info[5]);
	if (res->material.color.r == -1)
		return (res);
	res->transformation = cy_transform(res);
	res->inv_transfo = mop_inverse(res->transformation);
	res->cylinder.valid = 1;
	return (res);
}

void	add_cylinder(char **info, t_world *world)
{
	t_shape	*new;

	new = pars_cylinder(info);
	if (!new)
		return ;
	new->next = world->shapes;
	world->shapes = new;
}

t_matrix	cy_transform(t_shape *s)
{
	t_tuple		y_axis;
	t_tuple		helper;
	t_tuple		x_axis;
	t_tuple		z_axis;
	t_matrix	rotation;
	t_matrix	translation;
	t_matrix	scaling;
	double		radius;
	double		half_h;

	y_axis = top_normalize(s->cylinder.axis);
	if (fabs(y_axis.z) < 1 - EPSILON)
		helper = cons_vector(0, 0, 1);
	else
		helper = cons_vector(1, 0, 0);
	x_axis = top_normalize(top_cross(helper, y_axis));
	z_axis = top_cross(y_axis, x_axis);
	rotation = cons_mat4(
			x_axis.x, y_axis.x, z_axis.x, 0,
			x_axis.y, y_axis.y, z_axis.y, 0,
			x_axis.z, y_axis.z, z_axis.z, 0,
			0, 0, 0, 1);
	radius = s->cylinder.diameter * 0.5;
	half_h = s->cylinder.height * 0.5;
	scaling = trsf_scaling(radius, half_h, radius);
	translation = trsf_translation(
			s->cylinder.coord.x,
			s->cylinder.coord.y,
			s->cylinder.coord.z);
	return (mop_multimat(translation, mop_multimat(rotation, scaling)));
}

int	check_cap(t_ray r, double t)
{
	double	x;
	double	z;

	x = r.origin.x + t * r.direction.x;
	z = r.origin.z + t * r.direction.z;
	return (((x * x) + (z * z)) <= 1);
}

int	cylinder_count_caps(t_shape *s, t_ray r)
{
	double	t;
	int		count;
	
	count = 0;
	if (fabs(r.direction.y) <= EPSILON)
		return (0);
	t = (s->cylinder.minimum - r.origin.y) / r.direction.y;
	if (check_cap(r, t))
		count++;
	t = (s->cylinder.maximum - r.origin.y) / r.direction.y;
	if (check_cap(r, t))
		count++;
	return (count);
}

int	cylinder_add_caps(t_shape *s, t_ray r, t_intersections *xs, int start)
{
	double	t;
	int		count;

	count = start;
	if (fabs(r.direction.y) <= EPSILON)
		return (count);
	t = (s->cylinder.minimum - r.origin.y) / r.direction.y;
	if (check_cap(r, t))
		xs->solutions[count++] = cons_intersection(t, s);
	t = (s->cylinder.maximum - r.origin.y) / r.direction.y;
	if (check_cap(r, t))
		xs->solutions[count++] = cons_intersection(t, s);
	return (count);
}

t_intersections	cylinder_intersect(t_shape *s, t_ray r)
{
	t_intersections	res;
	double			a;
	double			b;
	double			c;
	double			disc;
	t_intersection	t0;
	t_intersection	t1;
	double			y0;
	double			y1;
	int				side_count;
	int				cap_count;

	a = r.direction.x * r.direction.x + r.direction.z * r.direction.z;
	if (fabs(a) < EPSILON)
		return (cons_intersections(0));
	b = 2 * (r.origin.x * r.direction.x + r.origin.z * r.direction.z);
	c = r.origin.x * r.origin.x + r.origin.z * r.origin.z - 1;
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (cons_intersections(0));
	t0 = cons_intersection((-b - sqrt(disc)) / (2 * a), s);
	t1 = cons_intersection((-b + sqrt(disc)) / (2 * a), s);
	if (t0.t > t1.t)
		swap_i(&t0, &t1);
	y0 = r.origin.y + t0.t * r.direction.y;
	y1 = r.origin.y + t1.t * r.direction.y;
	side_count = 0;
	if (y0 > s->cylinder.minimum && y0 < s->cylinder.maximum)
		side_count++;
	if (y1 > s->cylinder.minimum && y1 < s->cylinder.maximum)
		side_count++;
	cap_count = cylinder_count_caps(s, r);
	res = cons_intersections(side_count + cap_count);
	if ((side_count + cap_count) > 0 && !res.solutions)
		return (cons_intersections(0));
	side_count = 0;
	if (y0 > s->cylinder.minimum && y0 < s->cylinder.maximum)
		res.solutions[side_count++] = t0;
	if (y1 > s->cylinder.minimum && y1 < s->cylinder.maximum)
		res.solutions[side_count++] = t1;
	res.count = cylinder_add_caps(s, r, &res, side_count);
	return (res);
}

t_tuple cylinder_normal_at(t_shape *s, t_tuple object_point)
{
	double dist;

	dist = (object_point.x * object_point.x) + (object_point.z * object_point.z);
	if (dist < 1 && object_point.y >= s->cylinder.maximum - EPSILON)
		return (cons_vector(0, 1, 0));
	else if (dist < 1 && object_point.y <= s->cylinder.minimum + EPSILON)
		return (cons_vector(0, -1, 0));
	else
		return (cons_vector(object_point.x, 0, object_point.z));
}

