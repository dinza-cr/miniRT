/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:55:53 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/30 19:41:24 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "../../Exec/Color/color.h"
# include "../../Exec/Tuples/tuple.h"

typedef struct s_world	t_world;
typedef struct s_shape	t_shape;

typedef struct s_plane
{
	int				valid;

	t_tuple			coord;
	t_tuple			normal;
	int				has_texture;
	int				texture_loaded;
	char			*texture_path;
	void			*texture_img;
	char			*texture_addr;
	int				texture_width;
	int				texture_height;
	int				texture_bpp;
	int				texture_line_len;
	int				texture_endian;
}	t_plane;

//parsing
t_shape			*pars_plane(char **info);
t_color			plane_texture_at(t_shape *s, t_tuple world_point);
void			load_world_plane_textures(t_world *world, void *mlx);
void			destroy_world_plane_textures(t_world *world, void *mlx);

//constructeur
t_plane			cons_plane(void);

//destructeur
void			dest_planes(t_plane *pl);

//utils
void			add_plane(char **info, t_world *world);
t_intersections	plane_intersect(t_shape *s, t_ray r);
t_matrix		pl_transform(t_shape *s);

#endif