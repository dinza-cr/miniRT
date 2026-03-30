/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 16:00:00 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/30 19:41:24 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	t_world	*world;
	t_canva	*canva;
	char	*argv[3];

	argv[0] = "./minirt_test";
	argv[1] = "scenes/test.rt";
	argv[2] = NULL;
	world = parsing(argv);
	if (!world || !world->valid)
		return (1);
	canva = render(world->C, world);
	canva->w = world;
	canva_to_mlx(canva);
	mlx_hook(canva->win, 17, 0, safe_exit, canva);
	mlx_key_hook(canva->win, key_hook, canva);
	mlx_loop(canva->mlx);
	dest_canva(canva);
	return (0);
}
