/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:30:13 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/26 15:00:12 by dinza-cr         ###   ########.fr       */
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

int	safe_exit(t_canva *canva, t_scene *scene)
{
	dest_canva(canva);
	free(scene);
	exit(0);
	return (0);
}
