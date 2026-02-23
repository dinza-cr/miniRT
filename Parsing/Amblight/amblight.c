/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amblight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:17:36 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/18 15:35:39 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_amblight	cons_amblight(char **info, t_scene *scene)
{
	t_amblight	res;
	char		**rgb;

	res.valid = 0;
	res.ratio = 0;
	res.color = cons_color(0, 0, 0);
	if (count_elem(info) != 3)
		return (res);
	res.ratio = ft_atod(info[1]);
	if (res.ratio < 0.0 || res.ratio > 1.0)
		return (res);
	rgb = ft_split(info[2], ',');
	if (!rgb)
		return (res);
	if (count_elem(rgb) != 3)
		return (free_split(rgb), res);
	res.color = cons_color(ft_atod(rgb[0]) / 255, ft_atod(rgb[1]) / 255, ft_atod(rgb[2]) / 255);
	if (res.color.r < 0 || res.color.r > 1
		|| res.color.g < 0 || res.color.g > 1
		|| res.color.b < 0 || res.color.b > 1)
		return (free_split(rgb), res);
	res.valid = 1;
	scene->has_ambient = 1;
	free_split(rgb);
	return (res);
}