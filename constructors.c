/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:50:21 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/19 17:14:04 by dinza-cr         ###   ########.fr       */
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

t_pixel	cons_pixel(double r, double g, double b)
{
	t_pixel	res;

	res.r = r;
	res.g = g;
	res.b = b;
	return (res);
}

t_canva	*cons_canva(int width, int height)
{
	t_canva	*res;

	res = malloc (sizeof(t_canva));
	if (!(res))
		return (NULL);
	res->width = width;
	res->height = height;
	res->pixels = ft_calloc(width * height, sizeof(t_pixel));
	if (!res->pixels)
		return (free(res), NULL);
	return (res);
}

t_matrix	cons_matrix(int size)
{
	t_matrix	res;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res.m[i][j] = 0.0;
			j++;
		}
		i++;
	}
	if (size < 2 || size > 4)
	{
		res.size = 0;
		printf("wrong matrix size !!! \n");
		return (res);
	}
	res.size = size;
	return (res);
}

t_matrix	cons_idmatrix(void)
{
	t_matrix	res;

	res = cons_matrix(4);
	res.m[0][0] = 1.0;
	res.m[1][1] = 1.0;
	res.m[2][2] = 1.0;
	res.m[3][3] = 1.0;
	return (res);
}