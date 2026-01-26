/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:47:35 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/26 15:07:31 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_cylinder	*init_cylinder(void)
{
	t_cylinder	*res;

	res = malloc(sizeof(t_cylinder));
	if (!res)
		return (NULL);
	res->valid = 0;
	res->coord = cons_point(0, 0, 0);
	res->axis = cons_vector(0, 0, 0);
	res->diameter = 0;
	res->height = 0;
	res->color = cons_color(0, 0, 0);
	res->next = NULL;
	return (res);
}

t_cylinder	*cons_cylinder(char **info)
{
	t_cylinder	*res;
	char		**buff;
	
	res = init_cylinder();
	if (!res)
		return (NULL);
	if (count_elem(info) != 6)
    	return (res);
	buff = ft_split(info[1], ',');
	if (!buff || count_elem(buff) != 3)
		return (free_split(buff), res);
	res->coord = cons_point(ft_atod(buff[0]), ft_atod(buff[1]), ft_atod(buff[2]));
	free_split(buff);
	buff = ft_split(info[2], ',');
	if (!buff || count_elem(buff) != 3)
		return (free_split(buff), res);
	res->axis =cons_vector(ft_atod(buff[0]), ft_atod(buff[1]), ft_atod(buff[2]));
	free_split(buff);
	if (!in_range(res->axis.x, -1.0, 1.0) || !in_range(res->axis.y, -1.0, 1.0) || !in_range(res->axis.z, -1.0, 1.0) || top_magnitude(res->axis) < EPSILON)
		return (res);
	res->axis = top_normalize(res->axis);
	res->diameter = ft_atod(info[3]);
	if (res->diameter <= 0)
		return (res);
	res->height = ft_atod(info[4]);
	if (res->height <= 0)
		return (res);
	buff = ft_split(info[5], ',');
	if (!buff || count_elem(buff) != 3)
		return (free_split(buff), res);
	res->color = cons_color(ft_atod(buff[0]) / 255.0, ft_atod(buff[1]) / 255.0, ft_atod(buff[2]) / 255.0);
	free_split(buff);
	if (!in_range(res->color.r, 0.0, 1.0) || !in_range(res->color.g, 0.0, 1.0) || !in_range(res->color.b, 0.0, 1.0))
		return (res);
	res->valid = 1;
	return (res);
}

void	add_cylinder(char **info, t_scene *scene)
{
	t_cylinder	*new;

	new = cons_cylinder(info);
	if (!new)
		return ;
	new->next = scene->cylinders;
	scene->cylinders = new;
}