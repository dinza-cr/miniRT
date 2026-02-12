/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:31:43 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/12 17:17:27 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "../Tuples/tuple.h"

typedef struct s_matrix
{
	int		size;
	double	m[4][4];  // [row][col]
} t_matrix;

//constructeurs
t_matrix	cons_matrix(int size);
t_matrix	cons_idmatrix(void);
t_matrix	cons_mat4(double a0, double a1, double a2, double a3, double b0, double b1, double b2, double b3, double c0, double c1, double c2, double c3, double d0, double d1, double d2, double d3);

//matrix operations(mop)
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

//matric transformation(trsf)
t_matrix	trsf_translation(double x, double y, double z);
t_matrix	trsf_scaling(double x, double y, double z);
t_matrix	trsf_rotx(double radian);
t_matrix	trsf_roty(double radian);
t_matrix	trsf_rotz(double radian);
t_matrix	trsf_shearing(double xy, double xz, double yx, double yz, double zx, double zy);

#endif