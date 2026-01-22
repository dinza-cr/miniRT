/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canva_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:32:29 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/22 12:59:10 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int rgb_to_int(double r, double g, double b)
{
	int r_res;
	int	g_res;
	int	b_res;
	
	r_res = ft_convertcolor(r);
	g_res = ft_convertcolor(g);
	b_res = ft_convertcolor(b);
	return (r_res << 16 | g_res << 8 | b_res);
}

void	addr_put_pixel(t_canva *canva, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= canva->width || y >= canva->height)
		return;
	dst = canva->addr + (y * canva->line_len + x * (canva->bpp / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

void	canva_to_mlx(t_canva *canva)
{
	int	i;
	int x;
	int y;
	int color;	

	i = 0;
	y = 0;
	while(y < canva->height)
	{
		x = 0;
		while (x < canva->width)
		{
			color = rgb_to_int(canva->pixels[i].r, canva->pixels[i].g, canva->pixels[i].b);
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
		safe_exit(c);
	return (0);
}