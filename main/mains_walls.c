// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   mains_walls.c                                      :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2026/02/28 13:40:50 by dinza-cr          #+#    #+#             */
// /*   Updated: 2026/03/02 19:18:30 by dinza-cr         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "minirt.h"


// int main(int argc, char **argv)
// {
//     if (argc != 2)
// 		return (printf("Add a map !\n"), 0);

// 	t_world *world = parsing(argv);
//     if (!world)
// 		return (printf("Parsing failed\n"), 1);

//     t_sphere *temp = world->spheres;

//     temp->transform = trsf_scaling(10, 0.01, 10);
//     temp->m.color = cons_color(1, 0.9, 0.9);
//     temp->m.specular = 0;

//     temp = temp->next;
    
//     temp->transform = mop_multimat(trsf_translation(0,0,5),
//         mop_multimat(trsf_roty(-PI/4),
//             mop_multimat(trsf_rotx(PI/2),
//                 trsf_scaling(10, 0.01, 10))));
//     temp->m.color = cons_color(1, 0.9, 0.9);
//     temp->m.specular = 0;

//     temp = temp->next;

//     temp->transform = mop_multimat(trsf_translation(0,0,5),
//         mop_multimat(trsf_roty(PI/4),
//             mop_multimat(trsf_rotx(PI/2),
//                  trsf_scaling(10, 0.01, 10))));
//     temp->m.color = cons_color(1, 0.9, 0.9);
//     temp->m.specular = 0;

    
// 	t_canva *canva = render(world->C, world);
//     canva_to_mlx(canva);
//     mlx_hook(canva->win, 17, 0, safe_exit, canva);
//     mlx_key_hook(canva->win, key_hook, canva);
//     mlx_loop(canva->mlx);

//     dest_canva(canva);
//     return 0;
// }