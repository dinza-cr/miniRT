/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:47:35 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/09 19:10:11 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

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
    t_tuple	y_axis;
    t_tuple	helper;
    t_tuple	x_axis;
    t_tuple	z_axis;
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

t_intersections	cylinder_intersect(t_shape *s, t_ray r)
{
	t_intersections	res;
	double a;
	double b;
	double c;
	double disc;

	a = r.direction.x * r.direction.x + r.direction.z * r.direction.z;
	b = 2 * (r.origin.x * r.direction.x + r.origin.z * r.direction.z);
	c = r.origin.x * r.origin.x + r.origin.z * r.origin.z - 1;
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (cons_intersections(0));
	res = cons_intersections(2);
	if (!res.solutions)
		return (cons_intersections(0));
	res.solutions[0] = cons_intersection((-b - sqrt(disc)) / (2 * a), s);
	res.solutions[1] = cons_intersection((-b + sqrt(disc)) / (2 * a), s);
	if (res.solutions[0].t > res.solutions[1].t)
		swap_i(&res.solutions[0], &res.solutions[1]);
	return (res);
}


