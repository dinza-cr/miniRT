/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 00:00:00 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/08/26 00:00:00 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_world	*world;
	t_canva	*canva;

	if (argc != 2)
		return (ft_putendl_fd("Usage: ./minirt scene.rt", 2), 1);
	if (ft_strlen(argv[1]) < 3
		|| ft_strcmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt"))
		return (ft_putendl_fd("Error: expected a .rt scene", 2), 1);
	world = parsing(argv);
	if (!world || !world->valid)
		return (dest_world(world), 1);
	canva = render(world->C, world);
	if (!canva)
		return (dest_world(world), 1);
	canvas_to_ppm(canva);
	printf("Image generated: canva.ppm\n");
	dest_canva(canva);
	dest_world(world);
	return (0);
}
