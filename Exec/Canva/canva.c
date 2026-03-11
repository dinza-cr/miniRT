/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canva.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:26:41 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/11 13:24:37 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//constructeur
t_canva	*cons_canva(int width, int height)
{
	t_canva	*res;

	res = malloc (sizeof(t_canva));
	if (!(res))
		return (NULL);
	res->width = width;
	res->height = height;
	res->pixels = ft_calloc(width * height, sizeof(t_color));
	if (!res->pixels)
		return (free(res), NULL);
	res->mlx = mlx_init();
	res->win = mlx_new_window((res->mlx), width, height, "miniRT");
	res->img = mlx_new_image(res->mlx, res->width, res->height);
	res->addr = mlx_get_data_addr(res->img, &res->bpp,
			&res->line_len, &res->endian);
	res->rendering = 0;
	return (res);
}

//destructeur
void	dest_canva(t_canva *canva)
{
	if (!canva)
		return ;
	if (canva->img)
		mlx_destroy_image(canva->mlx, canva->img);
	if (canva->win)
		mlx_destroy_window(canva->mlx, canva->win);
	if (canva->pixels)
		free(canva->pixels);
	if (canva->mlx)
	{
		mlx_destroy_display(canva->mlx);
		free(canva->mlx);
	}
	if (canva->w)
		dest_world(canva->w);
	free(canva);
}

//fonctions
void	write_pixel(t_canva *canva, int x_pos, int y_pos, t_color color)
{
	int	i;

	if (!canva)
		return ;
	if (x_pos < 0
		|| y_pos < 0
		|| x_pos >= canva->width
		|| y_pos >= canva->height)
		return ;
	i = x_pos + (canva->width * y_pos);
	canva->pixels[i] = color;
}

int	ft_convertcolor(double a)
{
	int	res;

	if (a < 0.0)
		a = 0.0;
	else if (a > 1.0)
		a = 1.0;
	res = a * 255;
	return (res);
}

int	rgb_to_int(double r, double g, double b)
{
	int	res;
	int	r_res;
	int	g_res;
	int	b_res;

	r_res = ft_convertcolor(r);
	g_res = ft_convertcolor(g);
	b_res = ft_convertcolor(b);
	res = r_res << 16 | g_res << 8 | b_res;
	return (res);
}