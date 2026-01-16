/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canva.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:45:34 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/16 15:47:52 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	write_pixel(t_canva *canva, int x_pos, int y_pos, t_color color)
{
	int i;
	
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

int		ft_convertcolor(double a)
{
	int	res;

	if (a < 0.0)
		a = 0.0;
	else if (a > 1.0)
		a = 1.0;
	res = a * 255;
	return (res);
}

void write_header(int fd, t_canva *canva)
{
	char *height;
	char *width;

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

void canvas_to_ppm(t_canva *canva)
{
	int fd;
	int i;
	int j;
	char *color;

	i = 0;
	j = 0;
	fd = open("canva.ppm", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		return (perror("open"));
	write_header(fd, canva);
	while (i < canva->height * canva->width)
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