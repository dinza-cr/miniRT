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
	if (!res->pixels)
		return (free(res), NULL);
	return (res);
}

//destructeur
void	dest_canva(t_canva *canva)
{
	if (!canva)
		return ;
	if (canva->pixels)
		free(canva->pixels);
	free(canva);
}

void	write_header(int fd, t_canva *canva)
{
	char	*height;
	char	*width;

	write(fd, "P3\n", 3);
	height = ft_itoa(canva->height);
	width = ft_itoa(canva->width);
	write(fd, width, ft_strlen(width));
	write(fd, " ", 1);
	write(fd, height, ft_strlen(height));
	write(fd, "\n255\n", 5);
	free(height);
	free(width);
}

void	canvas_to_ppm(t_canva *canva)
{
	int		fd;
	int		i;
	int		j;
	char	*color;

	if (!canva)
		return ;
	i = 0;
	j = 0;
	fd = open("canva.ppm", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		return (perror("open"));
	write_header(fd, canva);
	while (i < canva->width * canva->height)
	{
		color = ft_itoa(ft_convertcolor(canva->pixels[i].r));
		write(fd, color, ft_strlen(color));
		write(fd, " ", 1);
		free(color);
		color = ft_itoa(ft_convertcolor(canva->pixels[i].g));
		write(fd, color, ft_strlen(color));
		write(fd, " ", 1);
		free(color);
		color = ft_itoa(ft_convertcolor(canva->pixels[i].b));
		write(fd, color, ft_strlen(color));
		write(fd, " ", 1);
		free(color);
		j++;
		if (j == canva->width)
		{
			write(fd, "\n", 1);
			j = 0;
		}
		i++;
	}
	write(fd, "\n", 1);
	close(fd);
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
