/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cons_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 12:10:55 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/24 15:37:43 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"



t_amblight	cons_amblight(char **elements, t_scene *scene)
{
	t_amblight	res;
	char		**rgb;
	
	res.valid = 0;
	res.ratio = 0;
	res.color = cons_color(0, 0, 0);
	if (count_elem(elements) != 3)
		return (res);
	res.ratio = ft_atod(elements[1]);
	if (res.ratio < 0.0 || res.ratio > 1.0)
		return (res);
	rgb = ft_split(elements[2], ',');
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

t_camera	cons_camera(char **elements, t_scene *scene)
{
	t_camera res;
	char **buff;
	
	res.valid = 0;
	res.coord = cons_point(0, 0, 0);
	res.orientation = cons_vector(0, 0, 0);
	res.FOV = 0;
	if (count_elem(elements) != 4)
		return (res);
	buff = ft_split(elements[1], ',');
	if (!buff || count_elem(buff) != 3)
		return (free_split(buff), res);
	res.coord = cons_point(ft_atod(buff[0]), ft_atod(buff[1]), ft_atod(buff[2]));
	free_split(buff);
	buff = ft_split(elements[2], ',');
	if (!buff || count_elem(buff) != 3)
		return (free_split(buff), res);
	res.orientation =cons_vector(ft_atod(buff[0]), ft_atod(buff[1]), ft_atod(buff[2]));
	free_split(buff);
	if (!in_range(res.orientation.x, -1.0, 1.0) || !in_range(res.orientation.y, -1.0, 1.0) || !in_range(res.orientation.z, -1.0, 1.0) || top_magnitude(res.orientation) < EPSILON)
		return (res);
	res.FOV = ft_atod(elements[3]);
	if (!in_range(res.FOV, 0.0, 180.0))
		return (res);
	res.valid = 1;
	scene->has_camera = 1;
	return (res);
}

t_light	cons_light(char **elements, t_scene *scene)
{
	t_light	res;
	char **buff;
	
	res.valid = 0;
	res.coord = cons_point(0, 0, 0);
	res.brightness = 0;
	res.color = cons_color(0, 0, 0);
	if (count_elem(elements) != 4)
		return (res);
	buff = ft_split(elements[1], ',');
	if (!buff || count_elem(buff) != 3)
		return (free_split(buff), res);
	res.coord = cons_point(ft_atod(buff[0]), ft_atod(buff[1]), ft_atod(buff[2]));
	free_split(buff);
	res.brightness = ft_atod(elements[2]);
	if (!in_range(res.brightness, 0.0, 1.0))
		return (res);
	buff = ft_split(elements[3], ',');
	if (!buff || count_elem(buff) != 3)
		return (free_split(buff), res);
	res.color = cons_color(ft_atod(buff[0]), ft_atod(buff[1]), ft_atod(buff[2]));
	free_split(buff);
	if (!in_range(res.color.r, 0.0, 255.0) || !in_range(res.color.g, 0.0, 255.0) || !in_range(res.color.b, 0.0, 255.0))
		return (res);
	res.valid = 1;
	scene->has_light = 1;
	return (res);
}

// t_sphere	cons_sphere(t_tuple	c, double	d, t_color	col)
// {
// 	t_sphere	res;

// 	res.coord = c;
// 	res.diameter = d;
// 	res.color = col;
// 	res.next = NULL;
// 	return (res);
// }

// t_plane	cons_plane(t_tuple c, t_tuple n, t_color col)
// {
// 	t_plane	res;

// 	res.coord = c;
// 	res.normal = top_normalize(n);
// 	res.color = col;
// 	res.next = NULL;
// 	return (res);
// }

// t_cylinder cons_cylinder(t_tuple c, t_tuple a, double d, double h, t_color col)
// {
// 	t_cylinder res;

// 	res.coord = c;
// 	res.axis = top_normalize(a);
// 	res.diameter = d;
// 	res.height = h;
// 	res.color = col;
// 	res.next = NULL;
// 	return (res);
// }

t_scene	*cons_scene(void)
{
	t_scene	*res;

	res = malloc(sizeof(t_scene));
	if (!res)
		return (NULL);
	res->valid = 0;
	res->has_ambient = 0;
	res->has_camera = 0;
	res->has_light = 0;
	return (res);
}