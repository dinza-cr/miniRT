/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:21:24 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/12 17:15:59 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//constructor
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
	res->spheres = NULL;
	res->planes = NULL;
	res->cylinders = NULL;
	return (res);
}

//destructor
void	dest_scene(t_scene *scene)
{
	if (!scene)
		return ;
	dest_spheres(scene->spheres);
	dest_planes(scene->planes);
	dest_cylinders(scene->cylinders);
	free(scene);
}