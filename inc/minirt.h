/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:30:44 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/22 14:26:24 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define EPSILON 0.00001
# define PI 3.14159265358979323846

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
	int		width;
	int		height;

	void	*mlx;
	void	*win;
	
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	
	t_color	*pixels;
}	t_canva;

typedef struct s_matrix
{
	int		size;
	double	m[4][4];  // [row][col]
} t_matrix;

# include "minirtt.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

//constructors
t_tuple		cons_point(double x, double y, double z);
t_tuple		cons_vector(double x, double y, double z);
t_color		cons_color(double r, double g, double b);
t_canva		*cons_canva(int width, int height);
t_matrix	cons_matrix(int size);
t_matrix	cons_idmatrix(void);

//operations
int			top_compare(t_tuple a, t_tuple b);
t_tuple		top_add(t_tuple a, t_tuple b);
t_tuple		top_subs(t_tuple a, t_tuple b);
t_tuple		top_negate(t_tuple a);
t_tuple		top_multi(t_tuple a, double scal);
t_tuple		top_divi(t_tuple a, double scal);
double		top_magnitude(t_tuple a);
t_tuple		top_normalize(t_tuple a);
double		top_dot(t_tuple a, t_tuple b);
t_tuple		top_cross(t_tuple a, t_tuple b);

t_color		cop_add(t_color	a, t_color b);
t_color		cop_subs(t_color a, t_color b);
t_color		cop_multi(t_color a, double scal);
t_color		cop_blend(t_color a, t_color b);

int			mop_compare(t_matrix a, t_matrix b);
t_matrix	mop_multimat(t_matrix a, t_matrix b);
t_tuple		mop_multitup(t_matrix a, t_tuple b);
t_matrix	mop_transpose(t_matrix a);
double		mop_det2(t_matrix a);
t_matrix	mop_submatrix(t_matrix a, int row, int col);
double		mop_minor3(t_matrix a, int row, int col);
double		mop_cofactor3(t_matrix a, int row, int col);
double		mop_det3(t_matrix a);
double		mop_minor4(t_matrix a, int row, int col);
double		mop_cofactor4(t_matrix a, int row, int col);
double		mop_det4(t_matrix a);
int			mop_isinvertible(t_matrix a);
double		mop_det(t_matrix a);
double		mop_cofactor(t_matrix a, int row, int col);
t_matrix	mop_comat(t_matrix a);
t_matrix	mop_inverse(t_matrix a);

t_matrix	trsf_translation(double x, double y, double z);
t_matrix	trsf_scaling(double x, double y, double z);
t_matrix	trsf_rotx(double radian);
t_matrix	trsf_roty(double radian);
t_matrix	trsf_rotz(double radian);
t_matrix	trsf_shearing(double xy, double xz, double yx, double yz, double zx, double zy);


//canva
void		write_pixel(t_canva *canva, int x_pos, int y_pos, t_color pixel);
int			ft_convertcolor(double a);
void		write_header(int fd, t_canva *canva);
void		canvas_to_ppm(t_canva *canva);
void		canva_to_mlx(t_canva *canva);
int			rgb_to_int(double r, double g, double b);
int			key_hook(int keycode, t_canva *c);

//exit
void		free_canva(t_canva *canva);
int			safe_exit(t_canva *canva);

#endif