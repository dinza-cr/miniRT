/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:47:35 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/04 15:57:08 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// //constructeur
// t_cylinder	*cons_cylinder(void)
// {
// 	t_cylinder	*res;

// 	res = malloc(sizeof(t_cylinder));
// 	if (!res)
// 		return (NULL);
// 	res->valid = 0;
// 	res->coord = cons_point(0, 0, 0);
// 	res->axis = cons_vector(0, 0, 0);
// 	res->diameter = 0;
// 	res->height = 0;
// 	res->color = cons_color(0, 0, 0);
// 	res->next = NULL;
// 	return (res);
// }

// //destructor
// void	dest_cylinders(t_cylinder *cy)
// {
// 	t_cylinder	*tmp;

// 	while (cy)
// 	{
// 		tmp = cy->next;
// 		free(cy);
// 		cy = tmp;
// 	}
// }

// t_cylinder	*pars_cylinder(char **info)
// {
// 	t_cylinder	*res;

// 	res = cons_cylinder();
// 	if (!res)
// 		return (NULL);
// 	if (count_elem(info) != 6)
// 		return (res);
// 	res->coord = get_point(info[1]);
// 	if (res->coord.w == -1)
// 		return (res);
// 	res->axis = get_vector(info[2]);
// 	if (res->axis.w == -1)
// 		return (res);
// 	res->diameter = ft_atod(info[3]);
// 	if (res->diameter <= 0)
// 		return (res);
// 	res->height = ft_atod(info[4]);
// 	if (res->height <= 0)
// 		return (res);
// 	res->color = get_color(info[5]);
// 	if (res->color.r == -1)
// 		return (res);
// 	res->valid = 1;
// 	return (res);
// }

// void	add_cylinder(char **info, t_world *world)
// {
// 	t_cylinder	*new;

// 	new = pars_cylinder(info);
// 	if (!new)
// 		return ;
// 	new->next = world->cylinders;
// 	world->cylinders = new;
// }
