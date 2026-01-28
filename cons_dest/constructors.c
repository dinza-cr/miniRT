/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:50:21 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/28 16:59:15 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

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

t_color	cons_color(double r, double g, double b)
{
	t_color	res;

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
	res->pixels = ft_calloc(width * height, sizeof(t_color));
	if (!res->pixels)
		return (free(res), NULL);
	res->mlx = mlx_init();
	res->win = mlx_new_window((res->mlx), width, height, "miniRT");
	res->img = mlx_new_image(res->mlx, res->width, res->height);
	res->addr = mlx_get_data_addr(res->img, &res->bpp,
			&res->line_len, &res->endian);
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

t_matrix	cons_mat4(double a0, double a1, double a2, double a3, double b0, double b1, double b2, double b3, double c0, double c1, double c2, double c3, double d0, double d1, double d2, double d3)
{
	t_matrix A;

	A = cons_matrix(4);
	
	A.m[0][0] = a0;
	A.m[0][1] = a1;
	A.m[0][2] = a2;
	A.m[0][3] = a3;

	A.m[1][0] = b0;
	A.m[1][1] = b1;
	A.m[1][2] = b2;
	A.m[1][3] = b3;

	A.m[2][0] = c0;
	A.m[2][1] = c1;
	A.m[2][2] = c2;
	A.m[2][3] = c3;

	A.m[3][0] = d0;
	A.m[3][1] = d1;
	A.m[3][2] = d2;
	A.m[3][3] = d3;

	return (A);
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
