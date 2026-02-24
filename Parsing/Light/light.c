/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:19:37 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/24 11:09:50 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_light	point_light(t_tuple position, t_color color)
{
	t_light res;

	res.coord = position;
	res.brightness = 0.0;
	res.color = color;
	res.valid = 0;
	return (res);
}

t_light	cons_light(char **info, t_world *world)
{
	t_light	res;
	char	**buff;

	res.valid = 0;
	res.coord = cons_point(0, 0, 0);
	res.brightness = 0;
	res.color = cons_color(0, 0, 0);
	if (count_elem(info) != 4)
		return (res);
	buff = ft_split(info[1], ',');
	if (!buff || count_elem(buff) != 3)
		return (free_split(buff), res);
	res.coord = cons_point(ft_atod(buff[0]), ft_atod(buff[1]), ft_atod(buff[2]));
	free_split(buff);
	res.brightness = ft_atod(info[2]);
	if (!in_range(res.brightness, 0.0, 1.0))
		return (res);
	buff = ft_split(info[3], ',');
	if (!buff || count_elem(buff) != 3)
		return (free_split(buff), res);
	res.color = cons_color(ft_atod(buff[0]) / 255.0, ft_atod(buff[1]) / 255.0, ft_atod(buff[2]) / 255.0);
	free_split(buff);
	if (!in_range(res.color.r, 0.0, 1.0) || !in_range(res.color.g, 0.0, 1.0) || !in_range(res.color.b, 0.0, 1.0))
		return (res);
	res.valid = 1;
	world->has_light = 1;
	return (res);
}

t_tuple normal_at(t_sphere *s, t_tuple world_point)
{
	t_tuple object_point;
	t_tuple object_normal;
	t_tuple world_normal;

	object_point = mop_multitup(mop_inverse(s->transform), world_point);
	object_normal = top_subs(object_point, cons_point(0, 0, 0));
	world_normal = mop_multitup(mop_transpose(mop_inverse(s->transform)), object_normal);
	world_normal.w = 0;
	world_normal = top_normalize(world_normal);
	return (world_normal);
}

t_tuple reflect(t_tuple in, t_tuple normal)
{
	t_tuple res;
	
	res = top_multi(normal, 2 * top_dot(in, normal));
	res = top_subs(in, res);
	return (res);
}

t_color lighting(t_material m, t_light l, t_tuple point, t_tuple eyev, t_tuple normalv)
{
	t_color res;
	t_color effective_color;
	t_tuple lightv;
	t_color ambient;
	double light_dot_normal;
	t_color diffuse;
	t_color specular;
	t_tuple reflectv;
	double reflect_dot_eye;
	double factor;

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
