// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main_render.c                                      :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2026/02/27 14:24:47 by dinza-cr          #+#    #+#             */
// /*   Updated: 2026/02/27 14:51:51 by dinza-cr         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "minirt.h"

int main(int argc, char **argv)
{
    if (argc != 2)
		return (printf("Add a map !\n"), 0);

	t_world *world = parsing(argv);
    if (!world)
		return (printf("Parsing failed\n"), 1);

	t_canva *canva = render(world->C, world);
		
    canva_to_mlx(canva);
    mlx_hook(canva->win, 17, 0, safe_exit, canva);
    mlx_key_hook(canva->win, key_hook, canva);
    mlx_loop(canva->mlx);

    dest_canva(canva);
    return 0;
}