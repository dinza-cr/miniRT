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

#include "minirt.h"

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
	res->alpha = ft_calloc(width * height, 1);
	if (!res->pixels || !res->alpha)
		return (free(res->pixels), free(res->alpha), free(res), NULL);
	return (res);
}

//destructeur
void	dest_canva(t_canva *canva)
{
	if (!canva)
		return ;
	if (canva->pixels)
		free(canva->pixels);
	free(canva->alpha);
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
	canva->alpha[i] = 255;
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
