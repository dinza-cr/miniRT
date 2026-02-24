/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:44:28 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/24 11:10:17 by dinza-cr         ###   ########.fr       */
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
	double	FOV;
}	t_camera;

//constructor
t_camera	cons_camera(char **info, t_world *world);

#endif