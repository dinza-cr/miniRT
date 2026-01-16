/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:30:44 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/16 18:12:10 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define EPSILON 0.00001

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <unistd.h>

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w; // 1.0 for points 0.0 for vectors
}	t_tuple;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

typedef struct s_canva
{
	int width;
	int height;
	t_color *pixels;
}	t_canva;

typedef struct s_matrix
{
	int		size;
	double	m[4][4];  // [row][col]
} t_matrix;

# include "minirtt.h"

//constructors
t_tuple	cons_vector(double x, double y, double z);
t_tuple	cons_point(double x, double y, double z);
t_color	cons_color(double r, double g, double b);
t_canva	*cons_canva(int width, int height);
t_matrix cons_matrix(int size);

//operations
int		top_compare(t_tuple a, t_tuple b);
t_tuple	top_add(t_tuple a, t_tuple b);
t_tuple	top_subs(t_tuple a, t_tuple b);
t_tuple	top_negate(t_tuple a);
t_tuple	top_multi(t_tuple a, double scal);
t_tuple	top_divi(t_tuple a, double scal);
double	top_magnitude(t_tuple a);
t_tuple	top_normalize(t_tuple a);
double	top_dot(t_tuple a, t_tuple b);
t_tuple	top_cross(t_tuple a, t_tuple b);
t_color	cop_add(t_color	a, t_color b);
t_color	cop_subs(t_color a, t_color b);
t_color	cop_multi(t_color a, double scal);
t_color	cop_blend(t_color a, t_color b);

//canva
void	write_pixel(t_canva *canva, int x_pos, int y_pos, t_color color);
void	canvas_to_ppm(t_canva *canva);

//utils
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_itoa(int n);
int		ft_strlen(char *str);

#endif