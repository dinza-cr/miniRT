/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:21:34 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/04 15:57:34 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// //constructor
// t_plane	*cons_plane(void)
// {
// 	t_plane	*res;

// 	res = malloc(sizeof(t_plane));
// 	if (!res)
// 		return (NULL);
// 	res->valid = 0;
// 	res->coord = cons_point(0, 0, 0);
// 	res->normal = cons_vector(0, 0, 0);
// 	res->color = cons_color(0, 0, 0);
// 	res->next = NULL;
// 	return (res);
// }

// //destructor
// void	dest_planes(t_plane *pl)
// {
// 	t_plane	*tmp;

// 	while (pl)
// 	{
// 		tmp = pl->next;
// 		free(pl);
// 		pl = tmp;
// 	}
// }

// t_plane	*pars_plane(char **info)
// {
// 	t_plane	*res;

// 	res = cons_plane();
// 	if (!res)
// 		return (NULL);
// 	if (count_elem(info) != 4)
// 		return (res);
// 	res->coord = get_point(info[1]);
// 	if (res->coord.w == -1)
// 		return (res);
// 	res->normal = get_vector(info[2]);
// 	if (res->normal.w == -1)
// 		return (res);
// 	res->color = get_color(info[3]);
// 	if (res->color.r == -1)
// 		return (res);
// 	res->valid = 1;
// 	return (res);
// }

// void	add_plane(char **info, t_world *world)
// {
// 	t_plane	*new;

// 	new = pars_plane(info);
// 	if (!new)
// 		return ;
// 	new->next = world->planes;
// 	world->planes = new;
// }
