/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:30:13 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/26 17:38:03 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	dest_canva(t_canva *canva)
{
	if (!canva)
		return ;
	if (canva->img)
		mlx_destroy_image(canva->mlx, canva->img);
	if (canva->win)
		mlx_destroy_window(canva->mlx, canva->win);
	if (canva->pixels)
		free(canva->pixels);
	if (canva->mlx)
	{
		mlx_destroy_display(canva->mlx);
		free(canva->mlx);
	}
	free(canva);
}

void	dest_spheres(t_sphere *sp)
{
	t_sphere	*tmp;

	while (sp)
	{
		tmp = sp->next;
		free(sp);
		sp = tmp;
	}
}

void	dest_planes(t_plane *pl)
{
	t_plane	*tmp;

	while (pl)
	{
		tmp = pl->next;
		free(pl);
		pl = tmp;
	}
}

void	dest_cylinders(t_cylinder *cy)
{
	t_cylinder	*tmp;

	while (cy)
	{
		tmp = cy->next;
		free(cy);
		cy = tmp;
	}
}

void	dest_scene(t_scene *scene)
{
	if (!scene)
		return ;
	dest_spheres(scene->spheres);
	dest_planes(scene->planes);
	dest_cylinders(scene->cylinders);
	free(scene);
}

int	safe_exit(t_canva *canva, t_scene *scene)
{
	dest_canva(canva);
	dest_scene(scene);
	exit(0);
	return (0);
}
