/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:18:47 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/24 11:10:21 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_camera	cons_camera(char **info, t_world *world)
{
	t_camera	res;
	char		**buff;

	res.valid = 0;
	res.coord = cons_point(0, 0, 0);
	res.orientation = cons_vector(0, 0, 0);
	res.FOV = 0;
	if (count_elem(info) != 4)
		return (res);
	buff = ft_split(info[1], ',');
	if (!buff || count_elem(buff) != 3)
		return (free_split(buff), res);
	res.coord = cons_point(ft_atod(buff[0]), ft_atod(buff[1]), ft_atod(buff[2]));
	free_split(buff);
	buff = ft_split(info[2], ',');
	if (!buff || count_elem(buff) != 3)
		return (free_split(buff), res);
	res.orientation = cons_vector(ft_atod(buff[0]), ft_atod(buff[1]), ft_atod(buff[2]));
	free_split(buff);
	if (!in_range(res.orientation.x, -1.0, 1.0) || !in_range(res.orientation.y, -1.0, 1.0) || !in_range(res.orientation.z, -1.0, 1.0) || top_magnitude(res.orientation) < EPSILON)
		return (res);
	res.orientation = top_normalize(res.orientation);
	res.FOV = ft_atod(info[3]);
	if (!in_range(res.FOV, 0.0, 180.0))
		return (res);
	res.valid = 1;
	world->has_camera = 1;
	return (res);
}