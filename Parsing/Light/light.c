/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:19:37 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/20 13:02:34 by dinza-cr         ###   ########.fr       */
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
	world->has_light = 1;
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
	return (res);
}

t_color	lighting(t_world *world, t_comps comps, int in_shadow)
{
	t_color	res;
	t_tuple	lightv;
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;

	res = cop_blend(comps.shape->material.color, world->light.color);
	lightv = top_normalize(top_subs(world->light.coord, comps.point));
	ambient = cop_multi(cop_blend(comps.shape->material.color, world
				->amb.color), comps.shape->material.ambient * world->amb.ratio);
	if (top_dot(lightv, comps.normalv) < 0)
		diffuse = cons_color(0, 0, 0);
	else
		diffuse = cop_multi(res,
				comps.shape->material.diffuse * top_dot(lightv, comps.normalv)
				* world->light.brightness);
	specular = cons_color(0, 0, 0);
	if (in_shadow)
		res = ambient;
	else
		res = cop_add(ambient, cop_add(diffuse, specular));
	return (res);
}
