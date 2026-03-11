/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canva_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:32:29 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/11 13:26:34 by dinza-cr         ###   ########.fr       */
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

int	key_hook(int keycode, t_canva *c)
{
	if (keycode == 65307)
		safe_exit(c, NULL);
	if ((keycode == 119))
		c->w->C.coord.z += STEP;
	if ((keycode == 115))
		c->w->C.coord.z -= STEP;
	if ((keycode == 97))
		c->w->C.coord.x -= STEP;
	if ((keycode == 100))
		c->w->C.coord.x += STEP;
	if ((keycode == 65362))
		c->w->C.orientation.y += ROT;
	if ((keycode == 65364))
		c->w->C.orientation.y -= ROT;
	if ((keycode == 65361))
		c->w->C.orientation.x -= ROT;
	if ((keycode == 65363))
		c->w->C.orientation.x += ROT;
	if ((keycode == 113))
		c->w->C.coord.y += STEP;
	if ((keycode == 101))
		c->w->C.coord.y -= STEP;
	update_render(c);
	return (0);
}
