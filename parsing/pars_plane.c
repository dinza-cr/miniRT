/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:21:34 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/26 17:43:42 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_plane	*init_plane(void)
{
	t_plane	*res;

	res = malloc(sizeof(t_plane));
	if (!res)
		return (NULL);
	res->valid = 0;
	res->coord = cons_point(0, 0, 0);
	res->normal = cons_vector(0, 0, 0);
	res->color = cons_color(0, 0, 0);
	res->next = NULL;
	return (res);
}

t_plane	*cons_plane(char **info)
{
	t_plane	*res;
	char	**buff;

	res = init_plane();
	if (!res)
		return (NULL);
	if (count_elem(info) != 4)
		return (res);
	buff = ft_split(info[1], ',');
	if (!buff || count_elem(buff) != 3)
		return (free_split(buff), res);
	res->coord = cons_point(ft_atod(buff[0]), ft_atod(buff[1]), ft_atod(buff[2]));
	free_split(buff);
	buff = ft_split(info[2], ',');
	if (!buff || count_elem(buff) != 3)
		return (free_split(buff), res);
	res->normal = cons_vector(ft_atod(buff[0]), ft_atod(buff[1]), ft_atod(buff[2]));
	free_split(buff);
	if (!in_range(res->normal.x, -1.0, 1.0) || !in_range(res->normal.y, -1.0, 1.0) || !in_range(res->normal.z, -1.0, 1.0) || top_magnitude(res->normal) < EPSILON)
		return (res);
	res->normal = top_normalize(res->normal);
	buff = ft_split(info[3], ',');
	if (!buff || count_elem(buff) != 3)
		return (free_split(buff), res);
	res->color = cons_color(ft_atod(buff[0]) / 255.0, ft_atod(buff[1]) / 255.0, ft_atod(buff[2]) / 255.0);
	free_split(buff);
	if (!in_range(res->color.r, 0.0, 1.0) || !in_range(res->color.g, 0.0, 1.0) || !in_range(res->color.b, 0.0, 1.0))
		return (res);
	res->valid = 1;
	return (res);
}

void	add_plane(char **info, t_scene *scene)
{
	t_plane	*new;

	new = cons_plane(info);
	if (!new)
		return ;
	new->next = scene->planes;
	scene->planes = new;
}