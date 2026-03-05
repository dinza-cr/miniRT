/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:21:34 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/04 16:34:04 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

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
	//ajouter matrices transfo + inv
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
