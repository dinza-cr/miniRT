/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:30:13 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/22 14:27:43 by dinza-cr         ###   ########.fr       */
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

int	safe_exit(t_canva *canva)
{
	dest_canva(canva);
	exit(0);
	return (0);
}
