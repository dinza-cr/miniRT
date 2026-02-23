/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ray_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:12:49 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/23 18:08:26 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main(int argc, char **argv)
{
	(void)argc;
	int nb_xpixel = 500;
	int nb_ypixel = 500;
	t_canva *canva = cons_canva(nb_xpixel, nb_ypixel);
	
	t_scene *scene = parsing(argv);
	if (!scene)
		return (printf("Parsing failed\n"), 1);
	t_sphere *save = scene->spheres;
	while (scene->spheres)
	{
		scene->spheres->m = init_material();
		scene->spheres->m.color = cons_color(255.0 /255.0, 195.0 /255.0, 170.0 /255.0);
		scene->spheres = scene->spheres->next;
	}
	scene->spheres = save;
	
	t_camera camera;
	camera.coord = cons_point(0, 0, -5);

	double wall_zpos = 10.0;
	double wall_size = 10.0;
	double wall_xunits = wall_size / (double)nb_xpixel;
	double wall_yunits = wall_size / (double)nb_ypixel;
	double half = wall_size / 2.0;
	
	for (int y = 0; y < nb_ypixel ; y++)
	{
		double wall_ypos = half - wall_yunits * (double)y;
		for(int x = 0; x < nb_xpixel ; x++)
		{
			double wall_xpos = -half + wall_xunits * (double)x;
			
			t_tuple wall_point = cons_point(wall_xpos, wall_ypos, wall_zpos);
			t_tuple dir = top_normalize(top_subs(wall_point, camera.coord));

			t_ray ray = cons_ray(camera.coord, dir);
			while (scene->spheres)
			{
				t_intersections xs = iop_intersect(scene->spheres, ray);
				if (xs.count > 0)
				{
					t_tuple point = rop_position(ray, iop_hit(xs));
					t_tuple normal = normal_at(scene->spheres, point);
					t_tuple eye = top_negate(ray.direction);
					t_color color = lighting(scene->spheres->m, scene->L, point, eye, normal);
					write_pixel(canva, x, y, color);
					break;
				}
				scene->spheres = scene->spheres->next;
			}
			scene->spheres = save;
		}
	}

	canva_to_mlx(canva);
    mlx_hook(canva->win, 17, 0, safe_exit, canva);
    mlx_key_hook(canva->win, key_hook, canva);
    mlx_loop(canva->mlx);
	dest_canva(canva);
    return 0;
}