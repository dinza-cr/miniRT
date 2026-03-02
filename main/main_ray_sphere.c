// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main_ray_sphere.c                                  :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2026/02/23 17:12:49 by dinza-cr          #+#    #+#             */
// /*   Updated: 2026/02/28 13:31:42 by dinza-cr         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "minirt.h"

// int main(int argc, char **argv)
// {
// 	if (argc != 2)
// 		return (printf("Add a scene !\n"), 0);

// 	t_world *world = parsing(argv);
// 	if (!world)
// 		return (printf("Parsing failed\n"), 1);

// 	t_canva *canva = cons_canva(world->C.hsize, world->C.vsize);
	
// 	t_camera camera;
// 	camera.coord = cons_point(0, 0, -5);

// 	double wall_zpos = 10.0;
// 	double wall_size = 10.0;
// 	double wall_xunits = wall_size / (double)world->C.vsize;
// 	double wall_yunits = wall_size / (double)world->C.hsize;
// 	double half = wall_size / 2.0;
	
// 	for (int y = 0; y < world->C.vsize ; y++)
// 	{
// 		double wall_ypos = half - wall_yunits * (double)y;
// 		for(int x = 0; x < world->C.hsize ; x++)
// 		{
// 			double wall_xpos = -half + wall_xunits * (double)x;
			
// 			t_tuple wall_point = cons_point(wall_xpos, wall_ypos, wall_zpos);
// 			t_tuple dir = top_normalize(top_subs(wall_point, camera.coord));

// 			t_ray ray = cons_ray(camera.coord, dir);
// 			t_intersections xs = iop_intersect(world->spheres, ray);
// 			if (xs.count > 0)
// 			{
// 				t_tuple point = rop_position(ray, iop_hit(xs));
// 				t_tuple normal = normal_at(world->spheres, point);
// 				t_tuple eye = top_negate(ray.direction);
// 				t_color color = lighting(world->spheres->m, world->L, point, eye, normal);

// 				write_pixel(canva, x, y, color);
// 			}
// 		}
// 	}
	
	
// 	canva_to_mlx(canva);
//     mlx_hook(canva->win, 17, 0, safe_exit, canva);
//     mlx_key_hook(canva->win, key_hook, canva);
//     mlx_loop(canva->mlx);
// 	dest_canva(canva);
//     return 0;
// }