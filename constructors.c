/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:50:21 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/15 18:29:04 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	cons_point(double x, double y, double z)
{
	t_tuple	res;

	res.x = x;
	res.y = y;
	res.z = z;
	res.w = 1.0;
	return (res);
}

t_tuple	cons_vector(double x, double y, double z)
{
	t_tuple	res;

	res.x = x;
	res.y = y;
	res.z = z;
	res.w = 0.0;
	return (res);
}

t_color cons_color(double r, double g, double b)
{
	t_color res;

	res.r = r;
	res.g = g;
	res.b = b;
	return (res);
}

t_canva	*cons_canva(int width, int height)
{
	t_canva *res;

		
	res = malloc (sizeof(t_canva));
	if (!(res))
		return (NULL);
	res->width = width;
	res->height = height;
	res->pixels = ft_calloc(width * height, sizeof(t_color));
	if (!res->pixels)
		return (free(res), NULL);
	return (res);
}