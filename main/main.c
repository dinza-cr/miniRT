/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:24:47 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/21 10:32:22 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_world	*world;
	t_canva	*canva;

	if (argc != 2)
		return (printf("Add a map !\n"), 0);
	world = parsing(argv);
	if (!world || !world->valid)
	{
		if (world)
			dest_world(world);
		return (1);
	}

	canva = render(world->cam, world);
	
	if (!canva)
		return (dest_world(world), 1);
	canva_to_mlx(canva);
	mlx_hook(canva->win, 17, 0, safe_exit, canva);
	mlx_key_hook(canva->win, key_hook, canva);
	mlx_loop(canva->mlx);
	return (0);
}
