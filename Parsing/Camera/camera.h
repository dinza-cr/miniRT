/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:44:28 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/27 12:24:52 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

typedef struct s_world	t_world;

typedef struct s_camera // unique
{
	int		valid;

	t_tuple	coord;
	t_tuple	orientation;
	double	field_of_view;
	
	int		hsize;
	int		vsize;
	double	pixel_size;
	double	half_width;
	double	half_height;
	double	half_view;
	t_matrix transform;
}	t_camera;

//parsing
t_camera	pars_camera(char **info, t_world *world);

//constructor
t_camera	cons_camera(int hsize, int vsize,double fov);


t_ray	ray_for_pixel(t_camera camera, double px, double py);
t_canva *render(t_camera camera,t_world *world);

#endif