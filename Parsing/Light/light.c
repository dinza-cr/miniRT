/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:19:37 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/12 17:12:00 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_light	cons_light(char **info, t_scene *scene)
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
	scene->has_light = 1;
	return (res);
}