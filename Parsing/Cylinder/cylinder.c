/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:47:35 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/04 16:47:27 by dinza-cr         ###   ########.fr       */
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
	res->cylinder.height = ft_atod(info[4]);
	if (res->cylinder.height <= 0)
		return (res);
	res->material.color = get_color(info[5]);
	if (res->material.color.r == -1)
		return (res);
	res->cylinder.valid = 1;
	return (res);
}

void	add_cylinder(char **info, t_world *world)
{
	t_shape	*new;

	new = pars_cylinder(info);
	if (!new || new->cylinder.valid == 0)
		return ;
	new->next = world->shapes;
	world->shapes = new;
}
