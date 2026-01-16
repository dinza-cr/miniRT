/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_projectile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:02:56 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/16 17:04:19 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minirt.h"

// t_projectile tick(t_environnement env, t_projectile proj)
// {
// 	t_projectile res;

// 	res.position = top_add(proj.position, proj.velocity);
// 	res.velocity = top_add(proj.velocity, env.gravity);
// 	res.velocity = top_add(res.velocity, env.wind);
// 	return (res);
// }

// int main()
// {
// 	t_projectile proj;
// 	t_environnement env;
// 	t_canva *canva;
// 	t_color color;
// 	int x;
// 	int y;

// 	proj.position = cons_point(0.0, 1.0, 0.0);
// 	proj.velocity = top_normalize(cons_vector(1, 1.8, 0));
// 	proj.velocity = top_multi(proj.velocity, 11.25);
// 	env.gravity = cons_vector(0.0, -0.1, 0.0);
// 	env.wind = cons_vector(-0.01, 0.0, 0.0);
// 	canva = cons_canva (900, 550);
// 	color = cons_color(1.0, 0.0, 0.0);
// 	while (proj.position.y > 0.0)
// 	{
// 		x = round(proj.position.x);
// 		y = canva->height - 1 - round(proj.position.y);
// 		write_pixel(canva, x, y, color);
// 		proj = tick(env, proj);
// 	}
// 	canvas_to_ppm(canva);
// 	return (0);
// }