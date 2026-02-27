/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:19:37 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/27 18:17:26 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_light	cons_light(t_tuple position, t_color color)
{
	t_light	res;

	res.coord = position;
	res.brightness = 0.0;
	res.color = color;
	res.valid = 0;
	return (res);
}

t_light	pars_light(char **info, t_world *world)
{
	t_light	res;

	res = cons_light(cons_point(0, 0, 0), cons_color(0, 0, 0));
	if (count_elem(info) != 4)
		return (res);
	res.coord = get_point(info[1]);
	if (res.coord.w == -1)
		return (res);
	res.brightness = ft_atod(info[2]);
	if (!in_range(res.brightness, 0.0, 1.0))
		return (res);
	res.color = get_color(info[3]);
	if (res.color.r == -1)
		return (res);
	res.valid = 1;
	world->has_light = 1;
	return (res);
}

t_tuple	normal_at(t_sphere *s, t_tuple world_point)
{
	t_tuple	object_point;
	t_tuple	object_normal;
	t_tuple	world_normal;

	object_point = mop_multitup(mop_inverse(s->transform), world_point);
	object_normal = top_subs(object_point, cons_point(0, 0, 0));
	world_normal = mop_multitup(mop_transpose(mop_inverse(s->transform)),
			object_normal);
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

t_color lighting(t_material m, t_light l, t_tuple point, t_tuple eyev, t_tuple normalv)
{
	t_color	res;
	t_color	effective_color;
	t_tuple	lightv;
	t_color	ambient;
	double	light_dot_normal;
	t_color	diffuse;
	t_color	specular;
	t_tuple	reflectv;
	double	reflect_dot_eye;
	double	factor;

	effective_color = cop_blend(m.color, l.color);
	lightv = top_normalize(top_subs(l.coord, point));
	ambient = cop_multi(effective_color, m.ambient);
	light_dot_normal = top_dot(lightv, normalv);
	if (light_dot_normal < 0)
	{
		diffuse = cons_color(0, 0, 0);
		specular = cons_color(0, 0, 0);
	}
	else
	{
		diffuse = cop_multi(effective_color, m.diffuse * light_dot_normal);
		reflectv = reflect(top_negate(lightv), normalv);
		reflect_dot_eye = top_dot(reflectv, eyev);
		if (reflect_dot_eye <= 0)
			specular = cons_color(0, 0, 0);
		else
		{
			factor = pow(reflect_dot_eye, m.shininess);
			specular = cop_multi(l.color, m.specular * factor);
		}
	}
	res = cop_add(ambient, cop_add(diffuse, specular));
	return (res);
}
