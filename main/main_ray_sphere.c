/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ray_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:12:12 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/23 10:53:36 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main(void)
{
	int nb_xpixel = 500;
	int nb_ypixel = 500;
	t_canva *canva = cons_canva(nb_xpixel, nb_ypixel);
	
	t_scene *scene = cons_scene();
	scene->spheres = init_sphere();
	scene->spheres->color = cons_color(1, 0, 0);
	scene->spheres->radius = 1;
	
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
			t_intersections xs = iop_intersect(scene->spheres, ray);
			if (xs.count > 0)
				write_pixel(canva, x, y, scene->spheres->color);
		}
	}

	canva_to_mlx(canva);
    mlx_hook(canva->win, 17, 0, safe_exit, canva);
    mlx_key_hook(canva->win, key_hook, canva);
    mlx_loop(canva->mlx);
	dest_canva(canva);
    return 0;
}