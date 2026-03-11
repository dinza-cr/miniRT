/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canva_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:32:29 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/11 13:08:14 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	addr_put_pixel(t_canva *canva, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= canva->width || y >= canva->height)
		return ;
	dst = canva->addr + (y * canva->line_len + x * (canva->bpp / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

void	canva_to_mlx(t_canva *canva)
{
	int	i;
	int	x;
	int	y;
	int	color;	

	i = 0;
	y = 0;
	while (y < canva->height)
	{
		x = 0;
		while (x < canva->width)
		{
			color = rgb_to_int(canva->pixels[i].r, canva->pixels[i].g,
					canva->pixels[i].b);
			addr_put_pixel(canva, x, y, color);
			i++;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(canva->mlx, canva->win, canva->img, 0, 0);
}

void	update_render(t_canva *canva)
{
	int x;
	int y;
	t_ray r;
	t_color color;

	if (canva->rendering)
		return ;
	canva->rendering = 1;
	y = 0;
	update_camera(&canva->w->C);
	while (y < canva->w->C.vsize)
	{
		x = 0;
		while (x < canva->w->C.hsize)
		{
			r = ray_for_pixel(canva->w->C, x, y);
			color = color_at(canva->w, r);
			write_pixel(canva, x, y, color);
			x++;
		}
		y++;
	}
    canva_to_mlx(canva);
	canva->rendering = 0;
}

int	key_hook(int keycode, t_canva *c)
{
	t_world *w;

	w = c->w;
	if (keycode == 65307)
		safe_exit(c, NULL);
	if ((keycode == 119))
		w->C.coord.z += STEP;
	if ((keycode == 115))
		w->C.coord.z -= STEP;
	if ((keycode == 97))
		w->C.coord.x -= STEP;
	if ((keycode == 100))
		w->C.coord.x += STEP;
	if ((keycode == 65362))
		w->C.orientation.y += ROT;
	if ((keycode == 65364))
		w->C.orientation.y -= ROT;
	if ((keycode == 65361))
		w->C.orientation.x -= ROT;
	if ((keycode == 65363))
		w->C.orientation.x += ROT;
	if ((keycode == 113))
		w->C.coord.y += STEP;
	if ((keycode == 101))
		w->C.coord.y -= STEP;
	update_render(c);
	return (0);
}