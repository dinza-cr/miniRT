// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main_depl.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2026/02/27 14:24:47 by dinza-cr          #+#    #+#             */
// /*   Updated: 2026/03/18 14:17:22 by dinza-cr         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "minirt.h"

// int main(int argc, char **argv)
// {
// 	t_world *world;
// 	t_canva *canva;

// 	if (argc != 2)
// 		return (printf("Add a map !\n"), 0);

// 	world = parsing(argv);
// 	if (!world || !world->valid)
// 		return (1);

// 	canva = render(world->C, world);
//     canva->w = world;

// 	canva_to_mlx(canva);

// 	mlx_hook(canva->win, 17, 0, safe_exit, canva);
// 	mlx_key_hook(canva->win, key_hook, canva);

// 	mlx_loop(canva->mlx);

// 	dest_canva(canva);
// 	return (0);
// }